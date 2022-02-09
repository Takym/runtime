#include "pal.h"

// UEFI TODO: pal.uefi.cpp

pal::string_t pal::get_timestamp()
{
    // UEFI TODO: implement a PAL function
    return nullptr;
}

bool pal::getcwd(string_t* recv)
{
    // UEFI TODO: implement a PAL function
    return false;
}

pal::string_t pal::get_current_os_rid_platform()
{
    return _X("uefi");
}

const void* pal::mmap_read(const pal::string_t& path, size_t* length = nullptr)
{
    // UEFI TODO: implement a PAL function
    return nullptr;
}

void* pal::mmap_copy_on_write(const pal::string_t& path, size_t* length = nullptr)
{
    // UEFI TODO: implement a PAL function
    return nullptr;
}

bool pal::touch_file(const pal::string_t& path)
{
    // UEFI TODO: implement a PAL function
    return false;
}

bool pal::realpath(pal::string_t* path, bool skip_error_logging = false)
{
    // UEFI TODO: implement a PAL function
    return false;
}

bool pal::file_exists(const pal::string_t& path)
{
    // UEFI TODO: implement a PAL function
    return false;
}

void pal::readdir(const pal::string_t& path, const pal::string_t& pattern, std::vector<pal::string_t>* list)
{
    // UEFI TODO: implement a PAL function
}

void pal::readdir(const pal::string_t& path, std::vector<pal::string_t>* list)
{
    // UEFI TODO: implement a PAL function
}

void pal::readdir_onlydirectories(const pal::string_t& path, const pal::string_t& pattern, std::vector<pal::string_t>* list)
{
    // UEFI TODO: implement a PAL function
}

void pal::readdir_onlydirectories(const pal::string_t& path, std::vector<pal::string_t>* list)
{
    // UEFI TODO: implement a PAL function
}

bool pal::get_own_executable_path(pal::string_t* recv)
{
    // UEFI TODO: implement a PAL function
    return false;
}

bool pal::get_own_module_path(pal::string_t* recv)
{
    // UEFI TODO: implement a PAL function
    return false;
}

bool pal::get_method_module_path(pal::string_t* recv, void* method)
{
    // UEFI TODO: implement a PAL function
    return false;
}

bool pal::get_module_path(dll_t mod, pal::string_t* recv)
{
    // UEFI TODO: implement a PAL function
    return false;
}

bool pal::get_current_module(dll_t* mod)
{
    // UEFI TODO: implement a PAL function
    return false;
}

bool pal::getenv(const char_t* name, pal::string_t* recv)
{
    // UEFI TODO: implement a PAL function
    return false;
}

bool pal::get_default_servicing_directory(pal::string_t* recv)
{
    // UEFI TODO: implement a PAL function
    return false;
}

bool pal::get_dotnet_self_registered_dir(pal::string_t* recv)
{
    // UEFI TODO: implement a PAL function
    return false;
}

pal::string_t pal::get_dotnet_self_registered_config_location()
{
    // UEFI TODO: implement a PAL function
    return nullptr;
}

bool pal::get_default_installation_dir(pal::string_t* recv)
{
    // UEFI TODO: implement a PAL function
    return false;
}

bool pal::get_global_dotnet_dirs(std::vector<pal::string_t>* recv)
{
    // UEFI TODO: implement a PAL function
    return false;
}

bool pal::get_default_breadcrumb_store(pal::string_t* recv)
{
    // UEFI TODO: implement a PAL function
    return false;
}

bool pal::is_path_rooted(const pal::string_t& path)
{
    // UEFI TODO: implement a PAL function
    return false;
}

bool pal::get_default_bundle_extraction_base_dir(pal::string_t& extraction_dir)
{
    // UEFI TODO: implement a PAL function
    return false;
}

int pal::xtoi(const char_t* input)
{
    // UEFI TODO: implement a PAL function
    return 0;
}

bool pal::get_loaded_library(const char_t* library_name, const char* symbol_name, /*out*/ pal::dll_t* dll, /*out*/ pal::string_t* path)
{
    // UEFI TODO: implement a PAL function
    return false;
}

bool pal::load_library(const pal::string_t* path, pal::dll_t* dll)
{
    // UEFI TODO: implement a PAL function
    return false;
}

pal::proc_t pal::get_symbol(dll_t library, const char* name)
{
    // UEFI TODO: implement a PAL function
    return nullptr;
}

void pal::unload_library(pal::dll_t library)
{
    // UEFI TODO: implement a PAL function
}

bool pal::is_running_in_wow64()
{
    return false;
}

bool pal::are_paths_equal_with_normalized_casing(const pal::string_t& path1, const pal::string_t& path2)
{
    // UEFI TODO: implement a PAL function
    return false;
}
