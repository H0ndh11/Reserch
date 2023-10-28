#include "framework.h"
#include "GFwindow.h"
#include "winuser.h"
#include "windows.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    HWND foregroundWindowHandle1 = GetForegroundWindow();
    //2秒停止
    Sleep(2000);
    HWND foregroundWindowHandle2 = GetForegroundWindow();

    while (foregroundWindowHandle1 == foregroundWindowHandle2) {
        Sleep(2000);
        foregroundWindowHandle2 = GetForegroundWindow();
    }

    MessageBox(NULL, TEXT("マルウェアが活性化しました"), TEXT("Time of Attack!"), MB_OK | MB_ICONERROR);

    return 0;
}