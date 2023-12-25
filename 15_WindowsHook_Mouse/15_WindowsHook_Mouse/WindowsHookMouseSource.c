#include <Windows.h>
#include <stdio.h>

int LBUTTON_PRESSED_NUM = 0;
int RBUTTON_PRESSED_NUM = 0;
int MBUTTON_PRESSED_NUM = 0;

wchar_t* buffer;

LRESULT CALLBACK MouseCallBack(int code, WPARAM wParam, LPARAM lParam)
{
	if (code == HC_ACTION) //�� ����������� (������� �������� ����, ���� ������ 0, �� �� ����� ������ ���������� �����)
	{
		switch (wParam)
		{
			case WM_LBUTTONDOWN: //�������� �� ������� ����� ������ ����
			{
				LBUTTON_PRESSED_NUM++;
				wsprintfW(buffer, L"����� ������ ���� ������ - %d ���", LBUTTON_PRESSED_NUM);
				MessageBoxW(0, buffer, L"������ ����� ������ ����!", MB_OK);
				break;
			}
			case WM_RBUTTONDOWN: //�������� �� ������� ������ ������ ����
			{
				RBUTTON_PRESSED_NUM++;
				wsprintfW(buffer, L"������ ������ ���� ������ - %d ���", RBUTTON_PRESSED_NUM);
				MessageBoxW(0, buffer, L"������ ������ ������ ����!", MB_OK);
				break;
			}
			case WM_MBUTTONDOWN: //�������� �� ������� ������� ������ ����
			{
				MBUTTON_PRESSED_NUM++;
				wsprintfW(buffer, L"������� ������ ���� ������ - %d ���", MBUTTON_PRESSED_NUM);
				MessageBoxW(0, buffer, L"������ ������� ������ ����!", MB_OK);
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
	while (GetMessageW(&msg, NULL, 0, 0)) //����������� ���������
	{
		TranslateMessage(&msg); //����������� ��������� � ����������� ������ � ���������� ���������
		DispatchMessageW(&msg); //���������� ��������� � ������� ��������� (� ���� �������)
	}
	UnhookWindowsHookEx(hookDesc);
}