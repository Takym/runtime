// This script does not output a complete CMake file.

string arch = null;
if (Args.Count != 0) {
    arch = Args[0];
}

foreach (string filename in EnumerateCFiles("../../../../modules/edk2/MdePkg")) {
    WriteLine("    ${{UEFI_MDEPKG_DIR}}/{0}", filename);
}

foreach (string filename in EnumerateCFiles("../../../../modules/edk2/MdeModulePkg")) {
    WriteLine("    ${{UEFI_MDEMODULEPKG_DIR}}/{0}", filename);
}

foreach (string filename in EnumerateCFiles("../../../../modules/edk2/ShellPkg")) {
    WriteLine("    ${{UEFI_SHELLPKG_DIR}}/{0}", filename);
}

foreach (string filename in EnumerateCFiles("../../../../modules/edk2-libc/StdLib")) {
    WriteLine("    ${{UEFI_STDLIB_DIR}}/{0}", filename);
}

foreach (string filename in EnumerateCFiles("../../../../modules/edk2/EmbeddedPkg")) {
    WriteLine("    ${{UEFI_EMBEDDEDPKG_DIR}}/{0}", filename);
}

foreach (string filename in EnumerateCFiles("../../../../modules/edk2/ArmPkg")) {
    WriteLine("    ${{UEFI_ARMPKG_DIR}}/{0}", filename);
}

IEnumerable<string> EnumerateCFiles(string baseDir, string searchDir = null)
{
    baseDir = Path.GetFullPath(baseDir);
    searchDir ??= baseDir;
    foreach (string path1 in Directory.EnumerateFileSystemEntries(searchDir))
    {
        if (Directory.Exists(path1)) {
            foreach (string path2 in EnumerateCFiles(baseDir, path1)) {
                yield return path2;
            }
        } else if (File.Exists(path1) && path1.EndsWith(".c")) {
            string path2 = Path.GetRelativePath(baseDir, path1).Replace('\\', '/');
            if ((string.IsNullOrEmpty(arch) && !(
                  path2.Contains("/IA32/",    StringComparison.InvariantCultureIgnoreCase) ||
                  path2.Contains("/IPF/",     StringComparison.InvariantCultureIgnoreCase) ||
                  path2.Contains("/X64/",     StringComparison.InvariantCultureIgnoreCase) ||
                  path2.Contains("/EBC/",     StringComparison.InvariantCultureIgnoreCase) ||
                  path2.Contains("/ARM/",     StringComparison.InvariantCultureIgnoreCase) ||
                  path2.Contains("/AArch64/", StringComparison.InvariantCultureIgnoreCase)
            )) || path2.Contains($"/{arch}/", StringComparison.InvariantCultureIgnoreCase)) {
                yield return path2;
            }
        }
    }
}
