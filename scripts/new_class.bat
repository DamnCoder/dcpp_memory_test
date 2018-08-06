@echo off

cd..
set FILE_OUTPUT=.\project
set NEWCLASSBIN=.\utilities\NewClassProject\Build\NewClass.exe
set NEWCLASSBUILDSCRIPT=.\utilities\NewClassProject\scripts\build.bat
set TEMPLATES_PATH=.\utilities\NewClassProject\Templates

set FILE_NAME=gameobjectmanager
set PROJECT_NAME=DCPP_COMPONENTS
set CLASS_NAME=CGameObjectMgr
set NAMESPACE=dc
set FOLDER=managers
set AUTHOR="Jorge López González"

echo Build NewClassProject just if needed

call %NEWCLASSBUILDSCRIPT%

echo Create the class %CLASS_NAME% on %FOLDER% directory

%NEWCLASSBIN% %TEMPLATES_PATH% %FILE_OUTPUT% %FILE_NAME% %PROJECT_NAME% %AUTHOR% %CLASS_NAME% %NAMESPACE% %FOLDER%

exit