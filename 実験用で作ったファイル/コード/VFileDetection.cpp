#include <windows.h>
#include <Shlwapi.h>
#include <stdio.h>

#pragma comment(lib, "Shlwapi.lib")

int secret(void) {
	return PathFileExistsA("C:\\Windows\\System32\\VBoxControl.exe");
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);


	if (!secret()) {
        MessageBox(NULL, TEXT("マルウェアだ！"), TEXT("Time of Attack!"), MB_OK | MB_ICONERROR);
	}
    return 0;
}

/*
VirtualBoxに存在しがちなファイルリスト

"C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\StartUp\\agent.pyw",
                     "C:\\WINDOWS\\system32\\drivers\\vmmouse.sys",
                     "C:\\WINDOWS\\system32\\drivers\\vmhgfs.sys",
                     "C:\\WINDOWS\\system32\\drivers\\VBoxMouse.sys",
                     "C:\\WINDOWS\\system32\\drivers\\VBoxGuest.sys",
                     "C:\\WINDOWS\\system32\\drivers\\VBoxSF.sys",
                     "C:\\WINDOWS\\system32\\drivers\\VBoxVideo.sys",
                     "C:\\WINDOWS\\system32\\vboxdisp.dll",
                     "C:\\WINDOWS\\system32\\vboxhook.dll",
                     "C:\\WINDOWS\\system32\\vboxmrxnp.dll",
                     "C:\\WINDOWS\\system32\\vboxogl.dll",
                     "C:\\WINDOWS\\system32\\vboxoglarrayspu.dll",
                     "C:\\WINDOWS\\system32\\vboxoglcrutil.dll",
                     "C:\\WINDOWS\\system32\\vboxoglerrorspu.dll",
                     "C:\\WINDOWS\\system32\\vboxoglfeedbackspu.dll",
                     "C:\\WINDOWS\\system32\\vboxoglpackspu.dll",
                     "C:\\WINDOWS\\system32\\vboxoglpassthroughspu.dll",
                     "C:\\WINDOWS\\system32\\vboxservice.exe",
                     "C:\\WINDOWS\\system32\\vboxtray.exe",
                     "C:\\WINDOWS\\system32\\VBoxControl.exe"
*/