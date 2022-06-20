#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <psapi.h>
#include <string>

using namespace std;

//DWORD��unsigned long�Ɠ���
void FindSandboxFromProcessName(DWORD processID) {
	//virtualbox�����m����D������ς���Α��̃v���Z�X�������m���邱�Ƃ��\
	string blacklist[3] = { "vb","vbox", "virtualbox"};

	//TCHAR�̓R���p�C���I�v�V�����Œʏ�ƃ��j�R�[�h��؂�ւ��ł���char�^
	//sz��unknown�ŏ��������C�ŏI�I�Ƀv���Z�X��������
	TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");

	//�v���Z�X�����擾
	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);
	if (NULL != hProcess) {
		HMODULE hMod;
		DWORD cbNeeded;
		if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded)) {
			GetModuleBaseName(hProcess, hMod, szProcessName, sizeof(szProcessName) / sizeof(TCHAR));
		}
	}

	//�S�Ẵv���Z�X���ƃv���Z�XID���^�[�~�i����ɕ\��
	_tprintf(TEXT("%s (PID: %u)\n"), szProcessName, processID);

	CloseHandle(hProcess);
}

//���C��
int main() {
	DWORD aProcesses[1024], cbNeeded, cProcesses;
	unsigned int i;

	/*
	32�r�b�g���� EnumProcesses
	aProcesses�z��Ƀv���Z�XID������
	cbNeeded�Ƀo�C�g��������
	*/
	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded)) {
		return 1;
	}

	//�v���Z�XID�������Ԃ��ꂽ���v�Z
	//�Ԃ��ꂽ�o�C�g��/DWORD�T�C�Y(4)
	cProcesses = cbNeeded / sizeof(DWORD);

	//1���v���Z�XID��PrintProcessNameAndID�ɓn��
	for (i = 0; i < cProcesses; i++) {
		if (aProcesses[i] != 0) {
			FindSandboxFromProcessName(aProcesses[i]);
		}
	}

	return 0;
}