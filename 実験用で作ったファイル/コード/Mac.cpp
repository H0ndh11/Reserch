#include "framework.h"
#include "Mac.h"
#include "windows.h"
#include "iostream"
#include "iphlpapi.h"   //GetAdaptersAddressesに必要
#include "winsock2.h"   //

#pragma comment(lib, "iphlpapi.lib")

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    PIP_ADAPTER_INFO adapterInfo;
    DWORD            aiSize = 0;
    char             macAddr[64] = "";

    // ネットワーク機器情報のサイズを取得
    GetAdaptersInfo(NULL, &aiSize);
    // 取得した情報分のメモリを確保
    adapterInfo = (PIP_ADAPTER_INFO)malloc(aiSize);

    // 確保した領域に、情報を格納
    if (GetAdaptersInfo(adapterInfo, &aiSize) == NO_ERROR) {
        // Macアドレス取得(ZZ-ZZ-ZZ-ZZ-ZZ-ZZ)
        sprintf_s(macAddr, "%02X-%02X-%02X-%02X-%02X-%02X", adapterInfo->Address[0],
            adapterInfo->Address[1],
            adapterInfo->Address[2],
            adapterInfo->Address[3],
            adapterInfo->Address[4],
            adapterInfo->Address[5]);
    }

    // 確保した領域を解放
    free(adapterInfo);

    macAddr[8] = NULL;
    //VirtualBoxでのmacアドレスは08-00-27から始まる
    if (strcmp(macAddr,"08-00-27")!=0) {
        MessageBox(NULL, TEXT("マルウェアが活性化しました"), TEXT("Time of Attack!"), MB_OK | MB_ICONERROR);
    }
    
    return 0;
}