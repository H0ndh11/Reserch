//windowsのAPIを使えるように
#include <windows.h>

//windowsのプログラムは通常，WinMainというメイン関数に処理を記述
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow) {
	//WindowsのAPI, IsDebuggerPresent()でデバッガが動いているかbool値で確認できる．
	if (IsDebuggerPresent() == 0) {
		/*
		MessageBoxを表示させる．
		第一引数はオーナー(親)ウィンドウを指定．今回はなし
		第二引数は表示するメインの文字列
		第三引数はフレームに表示されるタイトル
		最後の引数はボタン．MB_OKだとOKボタンのみ表示される．
		*/
		MessageBox(NULL, TEXT("デバッガを検知できませんでした"), TEXT("デバッガチェック"), MB_OK | MB_ICONINFORMATION);
	}
	else {
		MessageBox(NULL, TEXT("デバッガを検知しました！"), TEXT("デバッガチェック"), MB_OK | MB_ICONINFORMATION);
	}
	return 0;
}