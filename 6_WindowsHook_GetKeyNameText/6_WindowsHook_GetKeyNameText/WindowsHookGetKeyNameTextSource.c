#include <stdio.h>
#include <windows.h>

LRESULT CALLBACK KeyBoardCallBack(int code, WPARAM wParam, LPARAM lParam)
{
	PKBDLLHOOKSTRUCT HookData = (PKBDLLHOOKSTRUCT)lParam;
	if (code == HC_ACTION && (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN))
	{
		DWORD iKey = MapVirtualKeyW(HookData->vkCode, NULL) << 16; //����������� ��� �������
		if (!(HookData->vkCode <= 1 << 5)) // 32 (�.�. ������ 32 ������� �������� �� ���������)
			iKey |= 0x1 << 24; //����� ������ ��� 24 ����
		wchar_t* buffer = calloc(256, sizeof(wchar_t));
		GetKeyNameTextW(iKey, buffer, 256);
		MessageBox(0, buffer, L"������ �� �������!", MB_OK);
	}
	return CallNextHookEx(NULL, code, wParam, lParam);
}

int main()
{
	HHOOK descHook = SetWindowsHookExW(WH_KEYBOARD_LL, KeyBoardCallBack, NULL, 0); 
	MSG msg;
	while (GetMessageW(&msg, NULL, 0, 0)) //��������� ��������� �� ������� ���������
	{
		TranslateMessage(&msg); //����������� ��������� � ����������� ������ � ���������� ���������
		DispatchMessageW(&msg); //���������� ��������� � ������� ��������� (� ���� �������)
	}
	UnhookWindowsHookEx(descHook);
}
