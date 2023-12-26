#include <Windows.h>
#include <stdio.h>

int counter = 0;
LPWSTR buffer;

DWORD ShowMessagebox(void* Arguments)
{
	wsprintfW(buffer, L"������� - %d", counter);
	MessageBox(0, buffer, L"��� ��������� �� �������!", MB_OK);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE preInstance, LPSTR lpArgs, int nShowCmd) //������ ����� ����� ������� ����������
{
	buffer = calloc(256, sizeof(WCHAR));
	while (1)
	{
		counter++;
		CreateThread(NULL, 0, ShowMessagebox, NULL, 0, NULL); //���� �� ������ ���� ������ 5 ������, �� ����� �����,
		//��� ��� MessageBox ���������������� ����� ���� ��� �� �������, � ����� ������� �� ��������� ��� ���� ����� ����� � ����� ���,
		//������� �� �����������, ���� �� ����, �� ������ ��������� ��� MessageBox ����
		Sleep(5000);
	}
}