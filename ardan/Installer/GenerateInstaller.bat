@echo off
set PROJ_NAME=CUAS
echo\
echo Generating Installer for %PROJ_NAME% GCU Data Logger...
echo\
echo Coping \Release\GcuDataLogger.exe file to \packages\gd.ots.root\data folder
copy ..\Release\GcuDataLogger.exe .\packages\gd.ots.root\data\*
echo Running Qt binarycreator...
C:\Qt\Tools\QtInstallerFramework\4.8\bin\binarycreator --offline-only -c config/config.xml -p packages %PROJ_NAME%_GcuDataLogger_Installer
echo         done.
echo\
pause