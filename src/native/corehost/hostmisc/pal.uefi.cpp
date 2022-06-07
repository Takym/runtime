
#include "pal.h"
#include "trace.h"

// This header file should be included in the last
// because this redefines TRUE, FALSE, and NULL.
#include "pal.uefi.h"

// UEFI TODO: pal.uefi.cpp

static int daysOf[] = {
    0,
    31,
    31 + 28,
    31 + 28 + 31,
    31 + 28 + 31 + 30,
    31 + 28 + 31 + 30 + 31,
    31 + 28 + 31 + 30 + 31 + 30,
    31 + 28 + 31 + 30 + 31 + 30 + 31,
    31 + 28 + 31 + 30 + 31 + 30 + 31 + 31,
    31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30,
    31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31,
    31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30,
};

pal::string_t pal::get_timestamp()
{
    uefi::EFI_TIME   time;
    uefi::EFI_STATUS status = uefi::gRT->GetTime(&time, nullptr);

    if (status == EFI_SUCCESS) {
        UINT8  d      = time.Day;
        bool   isLeap = ((time.Year % 400) == 0) || ((time.Year % 4 == 0) && ((time.Year % 100) != 0));
        tm t;
        t.tm_sec   = time.Second;
        t.tm_min   = time.Minute;
        t.tm_hour  = time.Hour;
        t.tm_mday  = time.Day;
        t.tm_mon   = time.Month - 1;
        t.tm_year  = time.Year;
        t.tm_yday  = time.Day + daysOf[t.tm_mon];
        t.tm_isdst = time.Daylight;
        if (!(isLeap && time.Month > 2)) {
            --t.tm_yday;
        }

        // Calculate week of day
        // Reference: https://ja.wikipedia.org/wiki/%E3%83%84%E3%82%A7%E3%83%A9%E3%83%BC%E3%81%AE%E5%85%AC%E5%BC%8F
        // Reference: https://en.wikipedia.org/wiki/Zeller%27s_congruence
        int y = time.Year + 1900;
        int m = time.Month;
        if (m <= 2) {
            --y;
            m += 12;
        }
        int C     = y / 100;
        int Y     = y % 100;
        int gamma = (5 * C) + (C / 4);
        t.tm_wday = ((time.Day + ((13 * (m + 1)) / 5) + Y + (Y / 4) + gamma) % 7) + 1;
        if (t.tm_wday == 7) {
            t.tm_wday = 0;
        }

        const std::size_t elems = 100;
        char_t buf[elems];
        std::wcsftime(buf, elems, _X("%c GMT"), &t);
        return pal::string_t(buf);
    }

    return nullptr;
}

bool pal::getcwd(string_t* recv)
{
    // UEFI TODO: implement a PAL function

    trace::error(_X("The PAL function \"getcwd\" is not supported in the UEFI platform."));
    return false;
}

pal::string_t pal::get_current_os_rid_platform()
{
    return _X("uefi");
}

const void* pal::mmap_read(const pal::string_t& path, size_t* length)
{
    // UEFI TODO: implement a PAL function

    trace::error(_X("The PAL function \"mmap_read\" is not supported in the UEFI platform."));
    return nullptr;
}

void* pal::mmap_copy_on_write(const pal::string_t& path, size_t* length)
{
    // UEFI TODO: implement a PAL function

    trace::error(_X("The PAL function \"mmap_copy_on_write\" is not supported in the UEFI platform."));
    return nullptr;
}

bool pal::touch_file(const pal::string_t& path)
{
    // UEFI TODO: implement a PAL function

    trace::error(_X("The PAL function \"touch_file\" is not supported in the UEFI platform."));
    return false;
}

bool pal::realpath(pal::string_t* path, bool skip_error_logging)
{
    // UEFI TODO: implement a PAL function

    trace::error(_X("The PAL function \"realpath\" is not supported in the UEFI platform."));
    return false;
}

bool pal::file_exists(const pal::string_t& path)
{
    // UEFI TODO: implement a PAL function

    trace::error(_X("The PAL function \"file_exists\" is not supported in the UEFI platform."));
    return false;
}

void pal::readdir(const pal::string_t& path, const pal::string_t& pattern, std::vector<pal::string_t>* list)
{
    // UEFI TODO: implement a PAL function

    trace::error(_X("The PAL function \"readdir\" is not supported in the UEFI platform."));
}

void pal::readdir(const pal::string_t& path, std::vector<pal::string_t>* list)
{
    // UEFI TODO: implement a PAL function

    trace::error(_X("The PAL function \"readdir\" is not supported in the UEFI platform."));
}

void pal::readdir_onlydirectories(const pal::string_t& path, const pal::string_t& pattern, std::vector<pal::string_t>* list)
{
    // UEFI TODO: implement a PAL function

    trace::error(_X("The PAL function \"readdir_onlydirectories\" is not supported in the UEFI platform."));
}

void pal::readdir_onlydirectories(const pal::string_t& path, std::vector<pal::string_t>* list)
{
    // UEFI TODO: implement a PAL function

    trace::error(_X("The PAL function \"readdir_onlydirectories\" is not supported in the UEFI platform."));
}

bool pal::get_own_executable_path(pal::string_t* recv)
{
    // UEFI TODO: implement a PAL function

    trace::error(_X("The PAL function \"get_own_executable_path\" is not supported in the UEFI platform."));
    return false;
}

bool pal::get_own_module_path(pal::string_t* recv)
{
    // UEFI TODO: implement a PAL function

    trace::error(_X("The PAL function \"get_own_module_path\" is not supported in the UEFI platform."));
    return false;
}

bool pal::get_method_module_path(pal::string_t* recv, void* method)
{
    // UEFI TODO: implement a PAL function

    trace::error(_X("The PAL function \"get_method_module_path\" is not supported in the UEFI platform."));
    return false;
}

bool pal::get_module_path(dll_t mod, pal::string_t* recv)
{
    // UEFI TODO: implement a PAL function

    trace::error(_X("The PAL function \"get_module_path\" is not supported in the UEFI platform."));
    return false;
}

bool pal::get_current_module(dll_t* mod)
{
    // UEFI TODO: implement a PAL function

    trace::error(_X("The PAL function \"get_current_module\" is not supported in the UEFI platform."));
    return false;
}

bool pal::getenv(const char_t* name, pal::string_t* recv)
{
    // UEFI TODO: implement a PAL function

    trace::error(_X("The PAL function \"getenv\" is not supported in the UEFI platform."));
    return false;
}

bool pal::get_default_servicing_directory(pal::string_t* recv)
{
    // UEFI TODO: implement a PAL function

    trace::error(_X("The PAL function \"get_default_servicing_directory\" is not supported in the UEFI platform."));
    return false;
}

bool pal::get_dotnet_self_registered_dir(pal::string_t* recv)
{
    // UEFI TODO: implement a PAL function

    trace::error(_X("The PAL function \"get_dotnet_self_registered_dir\" is not supported in the UEFI platform."));
    return false;
}

pal::string_t pal::get_dotnet_self_registered_config_location()
{
    // UEFI TODO: implement a PAL function

    trace::error(_X("The PAL function \"get_dotnet_self_registered_config_location\" is not supported in the UEFI platform."));
    return nullptr;
}

bool pal::get_default_installation_dir(pal::string_t* recv)
{
    // UEFI TODO: implement a PAL function

    trace::error(_X("The PAL function \"get_default_installation_dir\" is not supported in the UEFI platform."));
    return false;
}

bool pal::get_global_dotnet_dirs(std::vector<pal::string_t>* recv)
{
    // UEFI TODO: implement a PAL function

    trace::error(_X("The PAL function \"get_global_dotnet_dirs\" is not supported in the UEFI platform."));
    return false;
}

bool pal::get_default_breadcrumb_store(pal::string_t* recv)
{
    // UEFI TODO: implement a PAL function

    trace::error(_X("The PAL function \"get_default_breadcrumb_store\" is not supported in the UEFI platform."));
    return false;
}

bool pal::is_path_rooted(const pal::string_t& path)
{
    // UEFI TODO: implement a PAL function

    trace::error(_X("The PAL function \"is_path_rooted\" is not supported in the UEFI platform."));
    return false;
}

bool pal::get_default_bundle_extraction_base_dir(pal::string_t& extraction_dir)
{
    // UEFI TODO: implement a PAL function

    trace::error(_X("The PAL function \"get_default_bundle_extraction_base_dir\" is not supported in the UEFI platform."));
    return false;
}

int pal::xtoi(const char_t* input)
{
    int result = 0;
    char ch;
    while ((ch = *input) != '\0') {
        if ('0' <= ch && ch <= '9') {
            result *= 10;
            result += ch - '0';
        } else if (ch != ' ' && ch != '\t' && ch != '\r' && ch != '\n' && ch != '\v') {
            break;
        }
        ++input;
    }
    return result;
}

bool pal::get_loaded_library(const char_t* library_name, const char* symbol_name, /*out*/ pal::dll_t* dll, /*out*/ pal::string_t* path)
{
    // UEFI TODO: implement a PAL function

    trace::error(_X("The PAL function \"get_loaded_library\" is not supported in the UEFI platform."));
    return false;
}

bool pal::load_library(const pal::string_t* path, pal::dll_t* dll)
{
    // UEFI TODO: implement a PAL function

    trace::error(_X("The PAL function \"load_library\" is not supported in the UEFI platform."));
    return false;
}

pal::proc_t pal::get_symbol(dll_t library, const char* name)
{
    // UEFI TODO: implement a PAL function

    trace::error(_X("The PAL function \"get_symbol\" is not supported in the UEFI platform."));
    return nullptr;
}

void pal::unload_library(pal::dll_t library)
{
    // UEFI TODO: implement a PAL function

    trace::error(_X("The PAL function \"unload_library\" is not supported in the UEFI platform."));
}

bool pal::is_running_in_wow64()
{
    return false;
}

bool pal::are_paths_equal_with_normalized_casing(const pal::string_t& path1, const pal::string_t& path2)
{
    // UEFI TODO: implement a PAL function

    trace::error(_X("The PAL function \"are_paths_equal_with_normalized_casing\" is not supported in the UEFI platform."));
    return false;
}
