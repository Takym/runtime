@echo off

setlocal

cd %~dp0
echo Working on: %CD%

set MODULES=%~dp0../../../../../modules/
set WORKSPACE=%~dp0temp
set CONF_PATH=%~dp0

if exist "%WORKSPACE%\" goto build
echo Downloading EDK 2 from the modules directory...
xcopy /E /Y "%MODULES%edk2"                 "%WORKSPACE%\"
xcopy /E /Y "%MODULES%edk2-libc"            "%WORKSPACE%\"
xcopy /E /Y "%MODULES%edk2-BaseTools-win32" "%WORKSPACE%\BaseTools\Bin\Win32\"
echo Downloded

:build
rmdir /S /Q                       "%WORKSPACE%\Edk2LibcForDotNet\"
xcopy /E /Y ".\Edk2LibcForDotNet" "%WORKSPACE%\Edk2LibcForDotNet\"
call "%WORKSPACE%\edksetup.bat"
call build

endlocal
