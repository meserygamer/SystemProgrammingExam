#include <Windows.h>
#include <stdio.h>

int main()
{
	system("chcp 1251>nul");
	printf("������, � ������������ �������!\n");
	LPSTR comands = "��������1 ��������2 ��������3";
	STARTUPINFOA *startUP = calloc(1, sizeof(STARTUPINFOA));
	startUP->cb = sizeof(STARTUPINFOA);
	LPPROCESS_INFORMATION procInfo = calloc(1, sizeof(PROCESS_INFORMATION));
	CreateProcessA("21_CreateProcess_Son.exe", comands, NULL, NULL, TRUE, NULL, NULL, NULL, startUP, procInfo);
}