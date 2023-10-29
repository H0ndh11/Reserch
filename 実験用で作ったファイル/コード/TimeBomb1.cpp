#include <windows.h>
#include <ctime>
#include <iostream>
#include <stdio.h>
#pragma warning(disable : 4996)

//この宣言によりstd::coutやstd::endlをcout,endlに省略できる
using namespace std;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

	time_t rawtime;		//時間値を表す型
	struct tm* timeinfo;	//tm構造体のtimeinfoを用意
	char buffer[100];

	//現在の時刻をrawtimeに代入
	time(&rawtime);
	//より分かりやすく変換後tm構造体のtimeinfoへ
	timeinfo = localtime(&rawtime);

	//8月26日に起動する
	//構造体tmの仕様に注意．ex)1月は0で表される
	if (timeinfo->tm_mon == 7 && timeinfo->tm_mday == 26) {
		MessageBox(NULL, TEXT("マルウェアが活性化しました"), TEXT("Time of Attack!"), MB_OK | MB_ICONERROR);
	}
	return 0;
}