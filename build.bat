@echo off

REM Configuration de l'environnement MinGW pour Qt 6.7.3

set PATH=C:\Qt\6.7.3\mingw_64\bin;C:\Qt\Tools\mingw1120_64\bin;C:\Qt\Tools\Ninja;C:\Qt\Tools\CMake_64\bin;%PATH%
set MINGW_PATH=C:\Qt\Tools\mingw1120_64
set Qt_PATH=C:\Qt\6.7.3\mingw_64

echo Environment setup complete
echo MinGW: %MINGW_PATH%
echo Qt: %Qt_PATH%

cmd /k "cd /d C:\Users\DARRAGI YOMNA\Documents\projetcpp2526-s2-2a12-smart-oil-press-MACHINES_YOMNA\build && cmake -G Ninja -DCMAKE_PREFIX_PATH=%Qt_PATH% .. && ninja"
