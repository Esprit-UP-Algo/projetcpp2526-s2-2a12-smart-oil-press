# Script pour corriger automatiquement les Makefile avec le support Qt SQL
# À exécuter après chaque régénération par qmake

$makefileDebug = "Makefile.Debug"
$makefileRelease = "Makefile.Release"

function Fix-Makefile {
    param([string]$filePath, [bool]$isDebug)
    
    if (-not (Test-Path $filePath)) {
        Write-Host "Fichier non trouvé: $filePath"
        return
    }
    
    $content = Get-Content $filePath -Raw
    
    # Corriger DEFINES
    if ($isDebug) {
        $oldDefines = "DEFINES       = -DUNICODE -D_UNICODE -DWIN32 -DMINGW_HAS_SECURE_API=1 -DQT_WIDGETS_LIB"
        $newDefines = "DEFINES       = -DUNICODE -D_UNICODE -DWIN32 -DMINGW_HAS_SECURE_API=1 -DQT_SQL_LIB -DQT_WIDGETS_LIB"
    } else {
        $oldDefines = "DEFINES       = -DUNICODE -D_UNICODE -DWIN32 -DMINGW_HAS_SECURE_API=1 -DQT_NO_DEBUG -DQT_WIDGETS_LIB"
        $newDefines = "DEFINES       = -DUNICODE -D_UNICODE -DWIN32 -DMINGW_HAS_SECURE_API=1 -DQT_NO_DEBUG -DQT_SQL_LIB -DQT_WIDGETS_LIB"
    }
    
    if ($content -like "*$oldDefines*") {
        $content = $content -replace [regex]::Escape($oldDefines), $newDefines
        Write-Host "✓ Mis à jour DEFINES dans $filePath"
    }
    
    # Corriger INCPATH
    $oldIncpath = "-I. -IC:/Qt/6.7.3/mingw_64/include -IC:/Qt/6.7.3/mingw_64/include/QtWidgets"
    $newIncpath = "-I. -IC:/Qt/6.7.3/mingw_64/include -IC:/Qt/6.7.3/mingw_64/include/QtSql -IC:/Qt/6.7.3/mingw_64/include/QtWidgets"
    
    if ($content -like "*$oldIncpath*") {
        $content = $content -replace [regex]::Escape($oldIncpath), $newIncpath
        Write-Host "✓ Mis à jour INCPATH dans $filePath"
    }
    
    # Corriger LIBS
    $oldLibs = "LIBS        =        C:\Qt\6.7.3\mingw_64\lib\libQt6Widgets.a"
    $newLibs = "LIBS        =        C:\Qt\6.7.3\mingw_64\lib\libQt6Sql.a C:\Qt\6.7.3\mingw_64\lib\libQt6Widgets.a"
    
    if ($content -like "*$oldLibs*") {
        $content = $content -replace [regex]::Escape($oldLibs), $newLibs
        Write-Host "✓ Mis à jour LIBS dans $filePath"
    }
    
    # Écrire le fichier modifié
    Set-Content $filePath $content
}

# Fixer les deux Makefile
Write-Host "Correction des Makefile pour le support Qt SQL..."
Fix-Makefile $makefileDebug $true
Fix-Makefile $makefileRelease $false
Write-Host "✓ Correction terminée!"
