#include <Windows.h>
#include <stdio.h>

int main()
{
	OpenClipboard(0); //��������� �����
	wchar_t* message = (LPWSTR)GetClipboardData(CF_UNICODETEXT); //��������� Unicode ������ �� ������
	CloseClipboard(); //���������
	MessageBoxW(0, message, L"��������� �� ������!", MB_OK);
}