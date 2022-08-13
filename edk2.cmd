@echo off
if "%1"=="setup" call        modules\edk2\edksetup.bat
if "%1"=="build" call        src\native\corehost\hostmisc\edk2-libc\build-edk2-libc.cmd
if "%1"=="linfs" call        src\native\corehost\hostmisc\edk2-libc\crt.uefi.ListInfFiles.bat
if "%1"=="clean" rmdir /S /Q src\native\corehost\hostmisc\edk2-libc\temp
