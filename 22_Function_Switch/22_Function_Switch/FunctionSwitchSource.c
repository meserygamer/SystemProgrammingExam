#include <stdio.h>
#include <Windows.h>

int main()
{
	system("chcp 1251>nul");
	if (!CreateProcessW(L"", NULL, NULL, NULL, FALSE, NULL, NULL, NULL, NULL, NULL))
	{
		printf("����� ��������, ��� ������� �� ��������!\n");
	}
	PHANDLE handle = CreateFileW("", NULL, NULL, NULL, NULL, NULL, NULL);
	if (handle == INVALID_HANDLE_VALUE)
	{
		printf("����� ��������, ��� ���� �� ��������!\n");
	}
	PHANDLE in, out;
	in = calloc(1, sizeof(HANDLE));
	out = calloc(1, sizeof(HANDLE));
	if (LoadLibraryW("NULL") == NULL)
	{
		printf("����� ��������, ���� ���������� �� ���������!");
	}
}