#include <Windows.h>
#include <stdio.h>

int counter = 0;
CRITICAL_SECTION *CS;

DWORD TreadFunction(LPVOID Arguments)
{
	EnterCriticalSection(CS); //��������� ������

	int innerCounter = counter;

	for (int i = 0; i < 100000; i++)
	{
		innerCounter++;
	}

	counter = innerCounter;

	LeaveCriticalSection(CS); //��������� ������
}

int main()
{
	system("chcp 1251>nul");
	CS = calloc(1, sizeof(CRITICAL_SECTION)); //�������� ����� ��� ������
	InitializeCriticalSection(CS); //��������������
	HANDLE thread1 = CreateThread(NULL, 0, TreadFunction, NULL, 0, 0); //������� ������
	HANDLE thread2 = CreateThread(NULL, 0, TreadFunction, NULL, 0, 0);
	HANDLE threads[2] = {thread1,thread2}; 
	WaitForMultipleObjects(2, threads, TRUE, INFINITE); //���� ���������� �����
	printf("������ ��������� ������, �������� �������� - %d", counter);
}