
namespace uefi
{
    #undef TRUE
    #undef FALSE
    #undef NULL
    extern "C"
    {
        #include <Uefi.h>
        #include <Library/UefiBootServicesTableLib.h>
        #include <Library/UefiRuntimeServicesTableLib.h>
    }
    #define U(text) ((uefi::CHAR16*)(##text))
}
