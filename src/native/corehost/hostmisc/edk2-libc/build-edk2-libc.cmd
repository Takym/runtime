@echo off

setlocal

set MODULES=%~dp0../../../../../modules/

set EDK_TOOLS_PATH=%MODULES%edk2/BaseTools
set EDK_TOOLS_BIN=%MODULES%edk2-BaseTools-win32
set WORKSPACE=%~dp0temp
set CONF_PATH=%~dp0

xcopy /E /Y "%MODULES%edk2\ArmPkg"                          "%WORKSPACE%\ArmPkg\"
xcopy /E /Y "%MODULES%edk2\MdeModulePkg"                    "%WORKSPACE%\MdeModulePkg\"
xcopy /E /Y "%MODULES%edk2\MdePkg"                          "%WORKSPACE%\MdePkg\"
xcopy /E /Y "%MODULES%edk2\ShellPkg"                        "%WORKSPACE%\ShellPkg\"
xcopy /E /Y "%MODULES%edk2-libc\AppPkg"                     "%WORKSPACE%\AppPkg\"
xcopy /E /Y "%MODULES%edk2-libc\StdLib"                     "%WORKSPACE%\StdLib\"
xcopy /E /Y "%MODULES%edk2-libc\StdLibPrivateInternalFiles" "%WORKSPACE%\StdLibPrivateInternalFiles\"
call %MODULES%edk2/edksetup.bat
call build

rem rmdir /S /Q %WORKSPACE%

endlocal
