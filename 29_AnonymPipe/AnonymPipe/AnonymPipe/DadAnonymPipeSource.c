#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>

int main()
{
	system("chcp 1251>cls");
	HANDLE READPIPE, WRITEPIPE;
	SECURITY_ATTRIBUTES Sec = { sizeof(LPSECURITY_ATTRIBUTES), NULL, TRUE };
	CreatePipe(&READPIPE, &WRITEPIPE, &Sec, 256); //����� � 256 ����
	char* buffer = calloc(20, sizeof(char));
	sprintf(buffer, "%d %d\0", READPIPE, WRITEPIPE); //������������ ���������� ��������� ������
	STARTUPINFO* SU = calloc(1, sizeof(STARTUPINFO));
	SU->cb = sizeof(STARTUPINFO);
	PROCESS_INFORMATION* PI = calloc(1, sizeof(PROCESS_INFORMATION));
	printf("������ - %u\n������ - %u", READPIPE, WRITEPIPE);
	CreateProcessA("AnonymPipeSon.exe"
				  ,buffer
				  ,NULL
				  ,NULL
				  ,TRUE //TRUE ��� ������������ ������������ �� ��������
				  ,0
		          ,NULL
		          ,NULL
		          ,SU
	              ,PI);
	free(buffer);
	int* testWritenBytes = calloc(1, sizeof(int));
	WriteFile(WRITEPIPE, "�������� ����� � ������", 44, testWritenBytes, NULL);
	printf("\n� ������� - %s\n", "�������� ����� � ������");
	WaitForSingleObject(PI->hProcess, INFINITE);
	int* sonExitCode = calloc(1, sizeof(int));
	GetExitCodeProcess(PI->hProcess, sonExitCode);
	CloseHandle(PI->hProcess);
	CloseHandle(PI->hThread);
	printf("��� ���������� ��������� �������� - %d\n", *sonExitCode);
	system("pause");
}