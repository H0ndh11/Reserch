#include "framework.h"
#include "MEMsize.h"
#include <windows.h>
#include <iostream>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    //ハードディスクサイズが100GBより大きかった場合に活性化
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfo);
    if (memInfo.ullTotalPhys > 4000000000) {
            MessageBox(NULL, TEXT("マルウェアが活性化しました"), TEXT("Time of Attack!"), MB_OK | MB_ICONERROR);
    }
    return 0;
}
