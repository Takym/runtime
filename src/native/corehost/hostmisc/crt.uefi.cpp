
#include <inttypes.h>

// This header file should be included in the last
// because this redefines TRUE, FALSE, and NULL.
#include "pal.uefi.h"

extern "C"
void __cdecl _invalid_parameter(wchar_t const* const expression, wchar_t const* const function_name,
    wchar_t const* const file_name, unsigned int const line_number, uintptr_t const reserved)
{
    // UEFI TODO: implement a CRT function

    auto cout = uefi::gST->ConOut;
    cout->OutputString(cout, U(u"Invalid parameter."));
}

void _wassert(wchar_t const* message, wchar_t const* filename, unsigned line)
{
    // UEFI TODO: implement a CRT function
}

int _CrtDbgReport(int reportType, const char *filename, int linenumber, const char *moduleName, const char *format, ...)
{
    // UEFI TODO: implement a CRT function
    return -1;
}

// UEFI TODO: __std_exception_copy, __std_exception_destroy

extern "C"
void __stdcall _CxxThrowException(void* pExceptionObject, /*_ThorwInfo*/ void* pThrowInfo)
{
    // UEFI TODO: implement a CRT function
}
