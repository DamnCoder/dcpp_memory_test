@echo off

cd..

set BUILD_SCRIPT=.\utilities\CMakeConfigure\scripts\build.bat
set EXECUTABLE=.\utilities\CMakeConfigure\Build\CMakeConfigure.exe

set FILE_OUTPUT_PATH=.\project
set TEMPLATES_PATH=.\utilities\CMakeConfigure\Templates

set PROJECT_NAME=DCGameObjectTest
set PROJECT_TYPE=EXECUTABLE
set PROJECT_ENVIRONMENT=Debug
set PROJECT_EXTERNALS=dcpp_gameobject

echo Build

call %BUILD_SCRIPT%

echo Create the CMakeFile on %FILE_OUTPUT_PATH% directory

%EXECUTABLE% %TEMPLATES_PATH% %FILE_OUTPUT_PATH% %PROJECT_TYPE% %PROJECT_NAME% %PROJECT_ENVIRONMENT% %PROJECT_EXTERNALS%

exit