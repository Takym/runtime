@echo off
dotnet script crt.uefi.ListCFiles.csx         > crt.uefi.ListCFiles.log
dotnet script crt.uefi.ListCFiles.csx IA32    > crt.uefi.ListCFiles.IA32.log
dotnet script crt.uefi.ListCFiles.csx X64     > crt.uefi.ListCFiles.X64.log
dotnet script crt.uefi.ListCFiles.csx ARM     > crt.uefi.ListCFiles.ARM.log
dotnet script crt.uefi.ListCFiles.csx AArch64 > crt.uefi.ListCFiles.AArch64.log
