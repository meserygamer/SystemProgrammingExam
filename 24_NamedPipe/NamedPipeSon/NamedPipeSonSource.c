#include <stdio.h>
#include <Windows.h>

int main()
{
	char* buffer = calloc(256, sizeof(char));
	while (TRUE)
	{
		system("chcp 1251>nul");
		HANDLE pipe = CreateFileA("\\\\.\\pipe\\MyTestPipe", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
		DWORD NamedPipeArgs = PIPE_READMODE_MESSAGE;
		BOOL isConnecting = SetNamedPipeHandleState(pipe, &NamedPipeArgs, NULL, NULL);
		if (!isConnecting)
		{
			printf("��� ����� � ��������\n");
			CloseHandle(pipe);
			Sleep(1000);
			continue;
		}
		WriteFile(pipe, "����� ���-������ ����?", 41, NULL, NULL);
		ReadFile(pipe, buffer, 256, NULL, NULL);
		printf("������ ����� - %s\n", buffer);
		Sleep(1000);
		CloseHandle(pipe);
	}
}