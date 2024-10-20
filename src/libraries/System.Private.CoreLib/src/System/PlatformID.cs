// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.

using System.ComponentModel;

namespace System
{
    public enum PlatformID
    {
        [EditorBrowsable(EditorBrowsableState.Never)] Win32S = 0,
        [EditorBrowsable(EditorBrowsableState.Never)] Win32Windows = 1,
        Win32NT = 2,
        [EditorBrowsable(EditorBrowsableState.Never)] WinCE = 3,
        Unix = 4,
        [EditorBrowsable(EditorBrowsableState.Never)] Xbox = 5,
        [EditorBrowsable(EditorBrowsableState.Never)] MacOSX = 6,
        Other = 7,
        UEFI = 8
    }
}
