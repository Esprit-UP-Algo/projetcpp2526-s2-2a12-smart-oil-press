# Solution pour les erreurs Qt SQL

## Problème
Les Makefiles générés par qmake ne déclaraient pas le module Qt SQL (libQt6Sql), causant l'erreur:
```
QSqlDatabase: No such file or directory
```

## Solution appliquée

### 1. Modification du fichier `.pro`
Le fichier `ayoub_project.pro` a été modifié pour forcer l'inclusion du module SQL:
- `QT = core gui sql widgets` (au lieu de `QT +=`)
- Ajout explicite de `QMAKE_CXXFLAGS`, `QMAKE_LFLAGS`, et `LIBS` pour Qt SQL

### 2. Correction manuelle des Makefile
Les fichiers `Makefile.Debug` et `Makefile.Release` ont été corrigés pour inclure:
- `-DQT_SQL_LIB` dans les defines
- `-IC:/Qt/6.7.3/mingw_64/include/QtSql` dans les chemins d'inclusion
- `libQt6Sql.a` dans les bibliothèques liées

### 3. Exécutables générés
- ✅ `debug/ayoub_project.exe` (2.67 MB avec symboles de débogage)
- ✅ `release/ayoub_project.exe` (136 KB optimisé)

## Si qmake régénère les Makefile

Qt Creator peut régénérer les Makefile automatiquement. Pour corriger rapidement:

### Option 1: Utiliser le script PowerShell
```powershell
cd "c:\Users\ayoub\OneDrive\Bureau\mini enreguster"
.\fix-sql-makefiles.ps1
```

### Option 2: Nettoyer et régénérer
```powershell
$env:QTDIR = "C:\Qt\6.7.3\mingw_64"
$env:PATH = "$env:QTDIR\bin;C:\Qt\Tools\mingw1120_64\bin;$env:PATH"
cd "c:\Users\ayoub\OneDrive\Bureau\mini enreguster"
Remove-Item -Path ".qmake.stash", "Makefile*", "debug", "release" -Recurse -Force -ErrorAction SilentlyContinue
& "$env:QTDIR\bin\qmake.exe" ayoub_project.pro
.\fix-sql-makefiles.ps1
mingw32-make.exe -f Makefile.Debug
```

## Compilation

### Mode Debug
```powershell
$env:QTDIR = "C:\Qt\6.7.3\mingw_64"
$env:PATH = "$env:QTDIR\bin;C:\Qt\Tools\mingw1120_64\bin;$env:PATH"
cd "c:\Users\ayoub\OneDrive\Bureau\mini enreguster"
mingw32-make.exe -f Makefile.Debug
```

### Mode Release
```powershell
$env:QTDIR = "C:\Qt\6.7.3\mingw_64"
$env:PATH = "$env:QTDIR\bin;C:\Qt\Tools\mingw1120_64\bin;$env:PATH"
cd "c:\Users\ayoub\OneDrive\Bureau\mini enreguster"
mingw32-make.exe -f Makefile.Release
```

## Configuration Qt Creator

Pour éviter les problèmes futurs, vous pouvez configurer Qt Creator pour utiliser un kit MinGW avec le bon environnement:
1. Allez dans **Tools → Options → Kits**
2. Sélectionnez votre kit MinGW
3. Vérifiez que le compilateur et le chemin Qt sont corrects
