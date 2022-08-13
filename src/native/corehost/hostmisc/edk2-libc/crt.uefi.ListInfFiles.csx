// This script does not output a complete dsc file.

string arch = null;
if (Args.Count != 0) {
    arch = Args[0];
}

int n = 0;

foreach (string filename in EnumerateInfFiles("../../../../../modules/edk2/MdePkg")) {
    WriteLine("  mp{0}|MdePkg/{1}", ++n, filename);
}

n = 0;

foreach (string filename in EnumerateInfFiles("../../../../../modules/edk2/MdeModulePkg")) {
    WriteLine("  mmp{0}|MdeModulePkg/{1}", ++n, filename);
}

n = 0;

foreach (string filename in EnumerateInfFiles("../../../../../modules/edk2/ShellPkg")) {
    WriteLine("  sp{0}|ShellPkg/{1}", ++n, filename);
}

n = 0;

foreach (string filename in EnumerateInfFiles("../../../../../modules/edk2-libc/StdLib")) {
    WriteLine("  sl{0}|StdLib/{1}", ++n, filename);
}

n = 0;

foreach (string filename in EnumerateInfFiles("../../../../../modules/edk2/EmbeddedPkg")) {
    WriteLine("  ep{0}|EmbeddedPkg/{1}", ++n, filename);
}

n = 0;

foreach (string filename in EnumerateInfFiles("../../../../../modules/edk2/ArmPkg")) {
    WriteLine("  ap{0}|ArmPkg/{1}", ++n, filename);
}

IEnumerable<string> EnumerateInfFiles(string baseDir, string searchDir = null)
{
    baseDir = Path.GetFullPath(baseDir);
    searchDir ??= baseDir;
    foreach (string path1 in Directory.EnumerateFileSystemEntries(searchDir))
    {
        if (Directory.Exists(path1)) {
            foreach (string path2 in EnumerateInfFiles(baseDir, path1)) {
                yield return path2;
            }
        } else if (File.Exists(path1) && path1.EndsWith(".inf")) {
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
