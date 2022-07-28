
if (CLR_CMAKE_TARGET_UEFI_AMD64)
    set(EDK2_LIBC_STDLIB_DIR ${CMAKE_CURRENT_LIST_DIR}/temp/Build/StdLib/RELEASE_VS2019/X64)
elseif(CLR_CMAKE_TARGET_UEFI_X86)
    set(EDK2_LIBC_STDLIB_DIR ${CMAKE_CURRENT_LIST_DIR}/temp/Build/StdLib/RELEASE_VS2019/IA32)
elseif(CLR_CMAKE_TARGET_UEFI_ARM)
    set(EDK2_LIBC_STDLIB_DIR ${CMAKE_CURRENT_LIST_DIR}/temp/Build/StdLib/RELEASE_VS2019/ARM)
elseif(CLR_CMAKE_TARGET_UEFI_ARM64)
    set(EDK2_LIBC_STDLIB_DIR ${CMAKE_CURRENT_LIST_DIR}/temp/Build/StdLib/RELEASE_VS2019/AARCH64)
endif()

list(APPEND LIBRARIES
    ${EDK2_LIBC_STDLIB_DIR}/MdePkg/Library/BaseLib/BaseLib/OUTPUT/BaseLib.lib
    ${EDK2_LIBC_STDLIB_DIR}/MdePkg/Library/BaseMemoryLib/BaseMemoryLib/OUTPUT/BaseMemoryLib.lib
    ${EDK2_LIBC_STDLIB_DIR}/StdLib/BsdSocketLib/BsdSocketLib/OUTPUT/BsdSocketLib.lib
    ${EDK2_LIBC_STDLIB_DIR}/StdLib/EfiSocketLib/EfiSocketLib/OUTPUT/EfiSocketLib.lib
    ${EDK2_LIBC_STDLIB_DIR}/StdLib/LibC/Containers/ContainerLib/OUTPUT/LibContainer.lib
    ${EDK2_LIBC_STDLIB_DIR}/StdLib/LibC/Ctype/Ctype/OUTPUT/LibCtype.lib
    ${EDK2_LIBC_STDLIB_DIR}/StdLib/LibC/gdtoa/gdtoa/OUTPUT/LibGdtoa.lib
    ${EDK2_LIBC_STDLIB_DIR}/StdLib/LibC/LibC/OUTPUT/LibC.lib
    ${EDK2_LIBC_STDLIB_DIR}/StdLib/LibC/Locale/Locale/OUTPUT/LibLocale.lib
    ${EDK2_LIBC_STDLIB_DIR}/StdLib/LibC/Math/Math/OUTPUT/LibMath.lib
    ${EDK2_LIBC_STDLIB_DIR}/StdLib/LibC/NetUtil/NetUtil/OUTPUT/LibNetUtil.lib
    ${EDK2_LIBC_STDLIB_DIR}/StdLib/LibC/Signal/Signal/OUTPUT/LibSignal.lib
    ${EDK2_LIBC_STDLIB_DIR}/StdLib/LibC/Stdio/Stdio/OUTPUT/LibStdio.lib
    ${EDK2_LIBC_STDLIB_DIR}/StdLib/LibC/StdLib/StdLib/OUTPUT/LibStdLib.lib
    ${EDK2_LIBC_STDLIB_DIR}/StdLib/LibC/String/String/OUTPUT/LibString.lib
    ${EDK2_LIBC_STDLIB_DIR}/StdLib/LibC/Time/Time/OUTPUT/LibTime.lib
    ${EDK2_LIBC_STDLIB_DIR}/StdLib/LibC/Uefi/Devices/daConsole/OUTPUT/DevConsole.lib
    ${EDK2_LIBC_STDLIB_DIR}/StdLib/LibC/Uefi/Devices/daShell/OUTPUT/DevShell.lib
    ${EDK2_LIBC_STDLIB_DIR}/StdLib/LibC/Uefi/Devices/daUtility/OUTPUT/DevUtility.lib
    ${EDK2_LIBC_STDLIB_DIR}/StdLib/LibC/Uefi/InteractiveIO/IIO/OUTPUT/LibIIO.lib
    ${EDK2_LIBC_STDLIB_DIR}/StdLib/LibC/Uefi/Uefi/OUTPUT/LibUefi.lib
    ${EDK2_LIBC_STDLIB_DIR}/StdLib/LibC/Wchar/Wchar/OUTPUT/LibWchar.lib
    ${EDK2_LIBC_STDLIB_DIR}/StdLib/PosixLib/Err/LibErr/OUTPUT/LibErr.lib
    ${EDK2_LIBC_STDLIB_DIR}/StdLib/PosixLib/Gen/LibGen/OUTPUT/LibGen.lib
    ${EDK2_LIBC_STDLIB_DIR}/StdLib/PosixLib/Glob/LibGlob/OUTPUT/LibGlob.lib
    ${EDK2_LIBC_STDLIB_DIR}/StdLib/PosixLib/PosixLib/OUTPUT/LibPosix.lib
    ${EDK2_LIBC_STDLIB_DIR}/StdLib/PosixLib/Stringlist/LibStringlist/OUTPUT/LibStringlist.lib
    ${EDK2_LIBC_STDLIB_DIR}/StdLib/UseSocketDxe/UseSocketDxe/OUTPUT/UseSocketDxe.lib
)
