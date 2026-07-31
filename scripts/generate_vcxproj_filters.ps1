<#
PowerShell 스크립트: .vcxproj.filters 자동 생성
사용법 예시:
  .\scripts\generate_vcxproj_filters.ps1 -Root "F:\Github\STS_TEAM_PROJECT_TEXTRPG_CODEMASTER"
또는 특정 프로젝트만 처리:
  .\scripts\generate_vcxproj_filters.ps1 -ProjectPath "F:\...\Text RPG.vcxproj"

동작 요약:
  - .vcxproj 파일을 읽어 프로젝트에 포함된 파일 목록(ClCompile, ClInclude, ResourceCompile, None)을 추출
  - 파일의 상대 경로를 기준으로 Filter(가상 폴더)를 생성. 상위 카테고리: Source Files, Header Files, Resource Files, Other Files
  - 각 필터에 GUID를 생성하여 .vcxproj.filters 파일로 저장
#>
param(
	[string]$Root = ".",
	[string]$ProjectPath = ""
)

function Get-ProjectFiles($projPath) {
	try {
		$xml = [xml](Get-Content -Path $projPath -Raw)
	} catch {
		Write-Warning "Failed to read XML: $projPath"
		return $null
	}

	# XPath using local-name() to avoid namespace issues
	$nodes = @()
	$nodes += $xml.SelectNodes("//*[local-name() = 'ClCompile']")
	$nodes += $xml.SelectNodes("//*[local-name() = 'ClInclude']")
	$nodes += $xml.SelectNodes("//*[local-name() = 'ResourceCompile']")
	$nodes += $xml.SelectNodes("//*[local-name() = 'None']")

	$items = @()
	foreach ($n in $nodes) {
		if ($n -and $n.Include) {
			$items += [PSCustomObject]@{
				Include = $n.Include
				ItemType = $n.LocalName
			}
		}
	}
	return $items
}

function Build-FilterName($projDir, $include, $category) {
	# Normalize separator and compute relative path
	$inc = $include -replace '/', '\\'
	$fullPath = [System.IO.Path]::IsPathRooted($inc) ? $inc : Join-Path -Path $projDir -ChildPath $inc
	try {
		$rel = [System.IO.Path]::GetRelativePath($projDir, $fullPath)
	} catch {
		$rel = $inc
	}
	$folder = [System.IO.Path]::GetDirectoryName($rel)
	if ([string]::IsNullOrEmpty($folder)) { return $category }
	# Replace backslashes with '\' in filter display
	$folder = $folder -replace "\\","\\"
	return "$category\\$folder"
}

if ($ProjectPath -ne "") {
	$projFiles = Get-ChildItem -Path $ProjectPath -Filter *.vcxproj -File -ErrorAction SilentlyContinue
} else {
	$projFiles = Get-ChildItem -Path $Root -Filter *.vcxproj -Recurse -File -ErrorAction SilentlyContinue
}

if (-not $projFiles) {
	Write-Error "No .vcxproj files found under: $Root"
	exit 1
}

foreach ($proj in $projFiles) {
	$projFull = $proj.FullName
	$projDir = Split-Path -Parent $projFull
	Write-Output "Processing: $projFull"

	$items = Get-ProjectFiles -projPath $projFull
	if (-not $items) { Write-Warning "No project items found in $projFull"; continue }

	$fileGroups = @{
		'ClCompile' = @()
		'ClInclude' = @()
		'ResourceCompile' = @()
		'None' = @()
	}

	foreach ($it in $items) {
		$t = $it.ItemType
		if (-not $fileGroups.ContainsKey($t)) { $t = 'None' }
		$fileGroups[$t] += $it.Include
	}

	$entries = @()
	$filters = @{}

	foreach ($kv in $fileGroups.GetEnumerator()) {
		$itemType = $kv.Key
		foreach ($f in $kv.Value) {
			switch ($itemType) {
				'ClCompile'      { $cat = 'Source Files' }
				'ClInclude'      { $cat = 'Header Files' }
				'ResourceCompile'{ $cat = 'Resource Files' }
				default          { $cat = 'Other Files' }
			}
			$filterName = Build-FilterName -projDir $projDir -include $f -category $cat
			$entries += [PSCustomObject]@{ Include = $f; ItemType = $itemType; Filter = $filterName }
			if (-not $filters.ContainsKey($filterName)) { $filters[$filterName] = [guid]::NewGuid().ToString("B").ToUpper() }
		}
	}

	# Ensure top-level category filters exist
	foreach ($top in @('Source Files','Header Files','Resource Files','Other Files')) {
		if (-not $filters.ContainsKey($top)) { $filters[$top] = [guid]::NewGuid().ToString("B").ToUpper() }
	}

	# Build .filters content
	$sb = New-Object System.Text.StringBuilder
	$sb.AppendLine('<?xml version="1.0" encoding="utf-8"?>') | Out-Null
	$sb.AppendLine('<Project ToolsVersion="4.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">') | Out-Null

	# ItemGroup for file entries
	$sb.AppendLine('  <ItemGroup>') | Out-Null
	foreach ($e in $entries) {
		$tag = switch ($e.ItemType) {
			'ClCompile' { 'ClCompile' }
			'ClInclude' { 'ClInclude' }
			'ResourceCompile' { 'ResourceCompile' }
			default { 'None' }
		}
		$inc = $e.Include -replace '/', '\\'
		$filterEsc = [System.Security.SecurityElement]::Escape($e.Filter)
		$sb.AppendLine("    <$tag Include=\"$inc\">") | Out-Null
		$sb.AppendLine("      <Filter>$filterEsc</Filter>") | Out-Null
		$sb.AppendLine("    </$tag>") | Out-Null
	}
	$sb.AppendLine('  </ItemGroup>') | Out-Null

	# ItemGroup for Filter definitions
	$sb.AppendLine('  <ItemGroup>') | Out-Null
	foreach ($f in $filters.Keys | Sort-Object) {
		$guid = $filters[$f]
		$fEsc = [System.Security.SecurityElement]::Escape($f)
		$sb.AppendLine("    <Filter Include=\"$fEsc\">") | Out-Null
		$sb.AppendLine("      <UniqueIdentifier>$guid</UniqueIdentifier>") | Out-Null
		$sb.AppendLine("    </Filter>") | Out-Null
	}
	$sb.AppendLine('  </ItemGroup>') | Out-Null

	$sb.AppendLine('</Project>') | Out-Null

	$outPath = "$projFull.filters"
	$sb.ToString() | Out-File -FilePath $outPath -Encoding UTF8
	Write-Output "Generated: $outPath"
}

Write-Output "Done. .vcxproj.filters가 생성되었습니다. 변경 사항 확인 후 Visual Studio에서 프로젝트를 다시 로드하세요."