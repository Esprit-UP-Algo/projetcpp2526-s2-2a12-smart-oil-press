# Script de compilation pour le projet Qt
# Ce script configure l'environnement Qt et compile le projet

$QtPath = "C:\Qt\6.7.3\mingw_64"
$ProjectPath = "C:\Users\DARRAGI YOMNA\Documents\projetcpp2526-s2-2a12-smart-oil-press-MACHINES_YOMNA"
$BuildPath = "$ProjectPath\build"

# Configurer l'environnement
$env:PATH = "$QtPath\bin;C:\Qt\Tools\mingw1120_64\bin;C:\Qt\Tools\Ninja;C:\Qt\Tools\CMake_64\bin;$env:PATH"
$env:CMAKE_PREFIX_PATH = $QtPath

Write-Host "===== Configuration Qt ====="
Write-Host "Qt Path: $QtPath"
Write-Host "Project Path: $ProjectPath"
Write-Host "Build Path: $BuildPath"

# Créer le répertoire de build
if (-not (Test-Path $BuildPath)) {
    New-Item -ItemType Directory $BuildPath | Out-Null
}

# Configurer cmake
Write-Host "`n===== Configuration CMake ====="
cd $BuildPath
& cmake.exe -G Ninja -DCMAKE_PREFIX_PATH="$QtPath" -DCMAKE_CXX_COMPILER="C:\Qt\Tools\mingw1120_64\bin\g++.exe" -DCMAKE_C_COMPILER="C:\Qt\Tools\mingw1120_64\bin\gcc.exe" ..

# Construire le projet
Write-Host "`n===== Compilation ====="
& ninja.exe

Write-Host "`n===== Compilation terminée ====="
Write-Host "Exécutable: $BuildPath\GestionMachines.exe"
