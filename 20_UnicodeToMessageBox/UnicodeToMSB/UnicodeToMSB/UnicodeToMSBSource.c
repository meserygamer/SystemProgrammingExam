#include <Windows.h>
#include <stdio.h>

#define PATH L"Message.txt"
#define BUFFSIZE 512

int main() //� ���� ������� ������������ UNICODE � ����������� �� ��������� UTF8 ��� UTF16 ����������� ������ ������� � �������
		   //��� ��� ��� ���� ����� ��������� UTF16 LE, �� � ����������� ��� wchar_t � ������� � W, ���� � ��� UTF8 ��� ����� 8 ������ ���������,
		   //����������� char � ������� � A
{
	HANDLE file = CreateFileW(PATH, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	wchar_t* buffer = calloc(512, sizeof(wchar_t));
	int* readedBytes = malloc(sizeof(int));
	BOOL isReaded = ReadFile(file, buffer, 512 * sizeof(wchar_t), readedBytes, NULL);
	MessageBoxW(NULL, buffer, L"����� �� �����", MB_OK);
}