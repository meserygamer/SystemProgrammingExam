#include <Windows.h>
#include <stdio.h>

int LBUTTON_PRESSED_NUM = 0;
int RBUTTON_PRESSED_NUM = 0;
int MBUTTON_PRESSED_NUM = 0;

wchar_t* buffer;

LRESULT CALLBACK MouseCallBack(int code, WPARAM wParam, LPARAM lParam)
{
	if (code == HC_ACTION) //Не обязательно (Правило хорошего тона, если меньше 0, то мы сразу должны передавать далее)
	{
		switch (wParam)
		{
			case WM_LBUTTONDOWN: //Проверка на нажатие левой кнопки мыши
			{
				LBUTTON_PRESSED_NUM++;
				wsprintfW(buffer, L"Левая кнопка мыши нажата - %d раз", LBUTTON_PRESSED_NUM);
				MessageBoxW(0, buffer, L"Нажата левая кнопка мыши!", MB_OK);
				break;
			}
			case WM_RBUTTONDOWN: //Проверка на нажатие правой кнопки мыши
			{
				RBUTTON_PRESSED_NUM++;
				wsprintfW(buffer, L"Правая кнопка мыши нажата - %d раз", RBUTTON_PRESSED_NUM);
				MessageBoxW(0, buffer, L"Нажата правая кнопка мыши!", MB_OK);
				break;
			}
			case WM_MBUTTONDOWN: //Проверка на нажатие средней кнопки мыши
			{
				MBUTTON_PRESSED_NUM++;
				wsprintfW(buffer, L"Средняя кнопка мыши нажата - %d раз", MBUTTON_PRESSED_NUM);
				MessageBoxW(0, buffer, L"Нажата Средняя кнопка мыши!", MB_OK);
				break;
			}
		}
	}
	return CallNextHookEx(NULL, code, wParam, lParam);
}

int main()
{
	HHOOK hookDesc = SetWindowsHookExW(WH_MOUSE_LL, MouseCallBack, NULL, 0);
	buffer = calloc(256, sizeof(wchar_t));
	MSG msg;
	while (GetMessageW(&msg, NULL, 0, 0)) //Вытаскивает сообщение
	{
		TranslateMessage(&msg); //Преобразует сообщения с виртуальным ключом в символьные сообщения
		DispatchMessageW(&msg); //Отправляет сообщение в оконную процедуру (В нашу функцию)
	}
	UnhookWindowsHookEx(hookDesc);
}