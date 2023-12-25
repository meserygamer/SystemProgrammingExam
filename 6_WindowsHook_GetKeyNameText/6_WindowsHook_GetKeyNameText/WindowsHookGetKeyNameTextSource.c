#include <stdio.h>
#include <windows.h>

LRESULT CALLBACK KeyBoardCallBack(int code, WPARAM wParam, LPARAM lParam)
{
	PKBDLLHOOKSTRUCT HookData = (PKBDLLHOOKSTRUCT)lParam;
	if (wParam == WM_KEYDOWN)
	{
		DWORD iKey = MapVirtualKeyW(HookData->vkCode, NULL) << 16; //Виртуальный код клавишы
		if (!(HookData->vkCode <= 1 << 5)) // 32 (т.к. первые 32 символа являются не печатными)
			iKey |= 0x1 << 24; //Задаём истину для 24 бита
		wchar_t* buffer = calloc(256, sizeof(wchar_t));
		GetKeyNameTextW(iKey, buffer, 256);
		MessageBox(0, buffer, L"Нажали на клавишу!", MB_OK);
	}
	return CallNextHookEx(NULL, code, wParam, lParam);
}

int main()
{
	HHOOK descHook = SetWindowsHookExW(WH_KEYBOARD_LL, KeyBoardCallBack, NULL, 0); 
	MSG msg;
	while (GetMessageW(&msg, NULL, 0, 0)) //Извлекает сообщение из очереди сообщений
	{
		TranslateMessage(&msg); //Преобразует сообщения с виртуальным ключом в символьные сообщения
		DispatchMessageW(&msg); //Отправляет сообщение в оконную процедуру (В нашу функцию)
	}
	UnhookWindowsHookEx(descHook);
}
