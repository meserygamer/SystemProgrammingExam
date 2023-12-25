#include <Windows.h>
#include <stdio.h>

#define MESSAGE L"Hello clipboard!"

int main()
{
	//Считывание старого в MessageBox
	wchar_t* textFromClipboard;
	OpenClipboard(0);
	textFromClipboard = (LPWSTR)GetClipboardData(CF_UNICODETEXT);
	CloseClipboard();
	wchar_t* buffer = calloc(512, sizeof(wchar_t));
	wsprintfW(buffer, L"Текст из буфера обмена - %s", textFromClipboard);
	MessageBoxW(0, buffer, L"Текст из буффера обмена", MB_OK);

	//Установка нового значения
	HGLOBAL Buffhandler = GlobalAlloc(GMEM_MOVEABLE, sizeof(wchar_t) * (wcslen(MESSAGE) + 1));
	memcpy(GlobalLock(Buffhandler), MESSAGE, sizeof(wchar_t) * (wcslen(MESSAGE) + 1));
	GlobalUnlock(Buffhandler);
	OpenClipboard(0);
	EmptyClipboard();
	SetClipboardData(CF_UNICODETEXT, Buffhandler);
	CloseClipboard();
}