#include <windows.h>	//windowsAPI�ɗ��p
#include <ctime>		//time(),localtime()�Ŏg�p
#include <iostream>
#include <stdio.h>
#pragma warning(disable : 4996)	//localtime()�̌x������

//���̐錾�ɂ��std::cout��std::endl��cout,endl�ɏȗ��ł���
using namespace std;

//���C���֐�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow) {
	time_t rawtime;		//���Ԓl��\���^
	struct tm *timeinfo;	//tm�\���̂�timeinfo��p��
	char buffer[100];

	//���݂̎�����rawtime�ɑ��
	time(&rawtime);
	//��蕪����₷���ϊ���tm�\���̂�timeinfo��
	timeinfo = localtime(&rawtime);

	//�b����10�̔{���̎��̂ݓ��삷��
	//������ҏW����ΔC�ӂ̃^�C�~���O�œ��삷��悤�ɂł���
	if (timeinfo->tm_sec%10==0) {
		MessageBox(NULL, TEXT("�}���E�F�A���ڊo�߂܂����I"), TEXT("���������s�t�@�C��"), MB_OK | MB_ICONINFORMATION);		
	}
	else {
		MessageBox(NULL, TEXT("�}���E�F�A�͑����Ђ��߂Ă��܂�..."), TEXT("���������s�t�@�C��"), MB_OK | MB_ICONINFORMATION);
	}
	return 0;
}