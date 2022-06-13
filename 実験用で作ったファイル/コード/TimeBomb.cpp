#include <windows.h>	//windowsAPIに利用
#include <ctime>		//time(),localtime()で使用
#include <iostream>
#include <stdio.h>
#pragma warning(disable : 4996)	//localtime()の警告無視

//この宣言によりstd::coutやstd::endlをcout,endlに省略できる
using namespace std;

//メイン関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow) {
	time_t rawtime;		//時間値を表す型
	struct tm *timeinfo;	//tm構造体のtimeinfoを用意
	char buffer[100];

	//現在の時刻をrawtimeに代入
	time(&rawtime);
	//より分かりやすく変換後tm構造体のtimeinfoへ
	timeinfo = localtime(&rawtime);

	//秒数が10の倍数の時のみ動作する
	//ここを編集すれば任意のタイミングで動作するようにできる
	if (timeinfo->tm_sec%10==0) {
		MessageBox(NULL, TEXT("マルウェアが目覚めました！"), TEXT("怪しい実行ファイル"), MB_OK | MB_ICONINFORMATION);		
	}
	else {
		MessageBox(NULL, TEXT("マルウェアは息をひそめています..."), TEXT("怪しい実行ファイル"), MB_OK | MB_ICONINFORMATION);
	}
	return 0;
}