//windowsのAPIを使えるように
#include <windows.h>

BOOL Manual_IsDebuggerPresent();

//windowsのプログラムは通常，WinMainというメイン関数に処理を記述
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow) {
	//WindowsのAPI, IsDebuggerPresent()でデバッガが動いているかbool値で確認できる．
	//if (IsDebuggerPresent() == 0) {
	if(Manual_IsDebuggerPresent() == 0){
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

//IsDebuggerPresent()と同じ機能をAPIを利用せず実装してみる
//これにより解析時に見つかりにくくなるかもしれない
BOOL Manual_IsDebuggerPresent() {
	BOOL ret_beingDebugged = FALSE;
	/*
	以下にアセンブリを記述
	TEBの0x30先のPEBアドレスをeaxへ
	PEBの0x2先のアドレス内にあるデバッガの有無(bool)をeaxへ
	eaxの値をret_beingDebuggedへ
	*/
	__asm {
		mov eax, dword ptr fs:[0x30]
		movzx eax, byte ptr ds:[eax + 0x2]
		mov ret_beingDebugged, eax
	}
	return ret_beingDebugged;
}