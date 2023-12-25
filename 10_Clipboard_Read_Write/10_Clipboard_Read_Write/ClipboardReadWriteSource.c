#include <Windows.h>
#include <stdio.h>

#define MESSAGE L"Hello clipboard!"

int main()
{
	//���������� ������� � MessageBox
	wchar_t* textFromClipboard;
	OpenClipboard(0);
	textFromClipboard = (LPWSTR)GetClipboardData(CF_UNICODETEXT);
	CloseClipboard();
	wchar_t* buffer = calloc(512, sizeof(wchar_t));
	wsprintfW(buffer, L"����� �� ������ ������ - %s", textFromClipboard);
	MessageBoxW(0, buffer, L"����� �� ������� ������", MB_OK);

	//��������� ������ ��������
	HGLOBAL Buffhandler = GlobalAlloc(GMEM_MOVEABLE, sizeof(wchar_t) * (wcslen(MESSAGE) + 1));
	memcpy(GlobalLock(Buffhandler), MESSAGE, sizeof(wchar_t) * (wcslen(MESSAGE) + 1));
	GlobalUnlock(Buffhandler);
	OpenClipboard(0);
	EmptyClipboard();
	SetClipboardData(CF_UNICODETEXT, Buffhandler);
	CloseClipboard();
}