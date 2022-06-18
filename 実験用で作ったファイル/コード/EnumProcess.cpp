#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <psapi.h>

//DWORDはunsigned longと同じ
void PrintProcessNameAndID(DWORD processID) {
	//プロセス名とプロセス識別子の表示
}

//メイン
int main() {
	DWORD aProcesses[1024], cbNeeded, cProcesses;
	unsigned int i;

	/*
	32ビット限定 EnumProcesses
	aProcesses配列にプロセス名が入る
	cbNeededにバイト数が入る
	*/
	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded)) {
		return 1;
	}

	//プロセス識別子がいくつ返されたか計算
	//返されたバイト数/DWORDサイズ(4)
	cProcesses = cbNeeded / sizeof(DWORD);

	//プロセス名とプロセス識別子の表示
	for (i = 0; i < cProcesses; i++) {
		if (aProcesses[i] != 0) {
			PrintProcessNameAndID(aProcesses[i]);
		}
	}

	return 0;
}