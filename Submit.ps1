$Folder = $PSScriptRoot | Split-Path -Leaf
New-Item -Force -ItemType Directory $env:TEMP\$Folder
Copy-Item -Recurse -Force .git $env:TEMP\$Folder
Compress-Archive -LiteralPath $env:TEMP\$Folder -DestinationPath ..\submit.zip
Remove-Item $env:TEMP\$Folder -Recurse -Whatif
