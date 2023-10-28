#include "framework.h"
#include "USB.h"
#include "windows.h"
#include "string"
#include "iostream"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // システム上で使用可能なすべてのドライブのビットマスクを取得．ex)Cドライブのみなら0000 0100，つまり4と出力される．右からA,B,C...と，存在するドライブに1が立つ
    UINT drives = GetLogicalDrives();
    bool trigger = 0;
    
    //存在するドライブ各種を調べ，リムーバブルドライブ(USB)であればマルウェアが活性化する．
    //GetDriveTypeAの引数はLPCSTR型に変換する必要がある．
    std::string drive = std::string("A:\\");
    for (int i = 0; i < 26; i++) {
        drive[0] = 'A' + i;
        if ((drives & (1 << i)) && GetDriveTypeA(drive.c_str()) == DRIVE_REMOVABLE) {
            trigger = 1;
        }
    }

    if (trigger) {
        MessageBox(NULL, TEXT("マルウェアが活性化しました"), TEXT("Time of Attack!"), MB_OK | MB_ICONERROR);
    }

    return 0;
}