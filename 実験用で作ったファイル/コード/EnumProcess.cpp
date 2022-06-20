#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <psapi.h>
#include <string>

using namespace std;

//DWORDはunsigned longと同じ
void FindSandboxFromProcessName(DWORD processID) {
	//virtualboxを検知する．ここを変えれば他のプロセス名を検知することが可能
	string blacklist[3] = { "vb","vbox", "virtualbox"};

	//TCHARはコンパイルオプションで通常とユニコードを切り替えできるchar型
	//szはunknownで初期化し，最終的にプロセス名が入る
	TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");

	//プロセス名を取得
	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);
	if (NULL != hProcess) {
		HMODULE hMod;
		DWORD cbNeeded;
		if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded)) {
			GetModuleBaseName(hProcess, hMod, szProcessName, sizeof(szProcessName) / sizeof(TCHAR));
		}
	}

	//全てのプロセス名とプロセスIDをターミナル上に表示
	_tprintf(TEXT("%s (PID: %u)\n"), szProcessName, processID);

	CloseHandle(hProcess);
}

//メイン
int main() {
	DWORD aProcesses[1024], cbNeeded, cProcesses;
	unsigned int i;

	/*
	32ビット限定 EnumProcesses
	aProcesses配列にプロセスIDが入る
	cbNeededにバイト数が入る
	*/
	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded)) {
		return 1;
	}

	//プロセスIDがいくつ返されたか計算
	//返されたバイト数/DWORDサイズ(4)
	cProcesses = cbNeeded / sizeof(DWORD);

	//1つずつプロセスIDをPrintProcessNameAndIDに渡す
	for (i = 0; i < cProcesses; i++) {
		if (aProcesses[i] != 0) {
			FindSandboxFromProcessName(aProcesses[i]);
		}
	}

	return 0;
}