@echo off
setlocal
cd %~dp0

dotnet script crt.uefi.ListInfFiles.csx         > crt.uefi.ListInfFiles.log
dotnet script crt.uefi.ListInfFiles.csx IA32    > crt.uefi.ListInfFiles.IA32.log
dotnet script crt.uefi.ListInfFiles.csx X64     > crt.uefi.ListInfFiles.X64.log
dotnet script crt.uefi.ListInfFiles.csx ARM     > crt.uefi.ListInfFiles.ARM.log
dotnet script crt.uefi.ListInfFiles.csx AArch64 > crt.uefi.ListInfFiles.AArch64.log

endlocal
