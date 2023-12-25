#include <Windows.h>
#include <stdio.h>

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    PKBDLLHOOKSTRUCT hHook = (PKBDLLHOOKSTRUCT)lParam;
    if (wParam == WM_KEYDOWN)
    {
        int iKey = MapVirtualKeyA(hHook->vkCode, NULL);//получение кода клавиши
        wchar_t code[256];
        wsprintfW(code, L"%d", iKey);
        MessageBox(NULL, code, L"Нажали клавишу!", MB_OK);
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

int main()
{
    HHOOK hHook;
    hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0); //Ставим клавиатурный хук
    MSG msg;
    while (GetMessageW(&msg, NULL, 0, 0)) //Получаем сообщение
    {
        TranslateMessage(&msg); // Транслируем сообщения с виртуальным ключом в символьные сообщения
        DispatchMessage(&msg); // Передаём сообщение в callback функцию
    }
    UnhookWindowsHookEx(hHook);
    return 0;
}