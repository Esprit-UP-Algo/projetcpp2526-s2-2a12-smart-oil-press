#!/bin/bash
# Qt Creator build script

# Find Qt Creator
QT_CREATOR="C:\Qt\Tools\QtCreator\bin\qtcreator.exe"

# Check if Qt Creator exists
if [ -f "$QT_CREATOR" ]; then
    echo "Opening project in Qt Creator..."
    "$QT_CREATOR" yomnaprojectt2.pro &
else
    echo "Qt Creator not found at $QT_CREATOR"
    echo "Please build the project manually in Qt Creator"
fi
