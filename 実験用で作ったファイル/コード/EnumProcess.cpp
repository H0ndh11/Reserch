#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <psapi.h>

//DWORD��unsigned long�Ɠ���
void PrintProcessNameAndID(DWORD processID) {
	//�v���Z�X���ƃv���Z�X���ʎq�̕\��
}

//���C��
int main() {
	DWORD aProcesses[1024], cbNeeded, cProcesses;
	unsigned int i;

	/*
	32�r�b�g���� EnumProcesses
	aProcesses�z��Ƀv���Z�X��������
	cbNeeded�Ƀo�C�g��������
	*/
	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded)) {
		return 1;
	}

	//�v���Z�X���ʎq�������Ԃ��ꂽ���v�Z
	//�Ԃ��ꂽ�o�C�g��/DWORD�T�C�Y(4)
	cProcesses = cbNeeded / sizeof(DWORD);

	//�v���Z�X���ƃv���Z�X���ʎq�̕\��
	for (i = 0; i < cProcesses; i++) {
		if (aProcesses[i] != 0) {
			PrintProcessNameAndID(aProcesses[i]);
		}
	}

	return 0;
}