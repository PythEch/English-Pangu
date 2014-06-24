//            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
//                    Version 2, December 2004
//
// Copyright (C) 2014  PythEch <https://github.com/PythEch>
//
// Everyone is permitted to copy and distribute verbatim or modified
// copies of this license document, and changing it is allowed as long
// as the name is changed.
//
//            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
//   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
//
//  0. You just DO WHAT THE FUCK YOU WANT TO.

#include <stdio.h>
#include <string.h>

#define patch(addr, str) fseek(handle, addr, SEEK_SET), fwrite(str, sizeof(char), strlen(str), handle)

int main()
{
    FILE *handle = fopen("Pangu_v1.0.exe", "r+b");
    if (handle == NULL)
    {
    	perror("Could not open Pangu_v1.0.exe");
    	return -1;
    }

    int whitespace_patches[41] = {0x00220F5C, 0x00220F86, 0x00220FBD, 0x002210A9, 0x002210C4, 0x0022110D, 0x00221155, 0x0022118D, 0x002211E1, 0x00221237, 0x0022128A, 0x00221304, 0x0022135C, 0x00221568, 0x0022157A, 0x002215E2, 0x0022231A, 0x00222446, 0x002224C1, 0x002224D9, 0x002224FC, 0x0022252C, 0x00222577, 0x002225A4, 0x002225C0, 0x002225E8, 0x00222602, 0x00222640, 0x00222684, 0x002226A1, 0x00222711, 0x0022272D, 0x00222762, 0x002227A6, 0x00222A55, 0x00222A6B, 0x00222AFA, 0x00222B13, 0x00222B22, 0x00222B7E, 0x00222BB2};

    int i;
    for (i = 0; i < 41; ++i)
    {
        patch(whitespace_patches[i], "\xa0");
    }

    // version: %s

    patch(0x00221078, "Version");

    // 25pp Checkbox

    patch(0x002212DC, "Install PP25?(Uncheck this)");

    // Fix typo <key>(Not supported,accept iOS 7.1 ~ 7.1.x).</key>
    //                              ^^

    patch(0x00221547, "except");

    // Replace settime_cn.gif with settime_en.gif

    patch(0x00221A40, "settime_en.gif");

    // Done!.\n -> Done!\n

    patch(0x002227E0, "Done!\n\x00");

    fclose(handle);

    printf("Done patching Pangu_v1.0.exe! It should be in English now...\n");

    return 0;
}
