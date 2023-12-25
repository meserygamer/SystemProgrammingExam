#include <windows.h>
#include <stdio.h>

#define KeyValue L"������, ��� � ���� ������������ ����"

int main()
{
	HKEY key = NULL;
	if (RegOpenKeyW(HKEY_CURRENT_USER, NULL, &key) != ERROR_SUCCESS) //��������� ������ HKEY_CURRENT_USER
	{
		return -1;
	}
	HKEY ResultKey = NULL;
	if (RegCreateKeyW(key, L"TestKey", &ResultKey) != ERROR_SUCCESS)
	{
		return -1;
	}
	if (RegSetValueExW(ResultKey, L"test", 0, REG_SZ, KeyValue, 37 * sizeof(WCHAR)) != ERROR_SUCCESS) // ������� �������� ���������� ���������
	{
		return -1;
	}
	//������� ����������, ��������� ���� �� �������� ������ �����
	/*HGLOBAL mem = GlobalAlloc(GMEM_MOVEABLE, 76);
	void* lMem = GlobalLock(mem);
	DWORD size = 76;
	if (RegGetValueW(ResultKey, NULL, L"Test", RRF_RT_REG_SZ, NULL, lMem, &size) == ERROR_SUCCESS)
	{
		MessageBoxW(0, lMem, L"�������� �����", MB_OK);
	}*/
	DWORD size = 76;
	wchar_t *string = calloc(38, sizeof(wchar_t));
	if (RegGetValueW(ResultKey, NULL, L"Test", RRF_RT_REG_SZ, NULL, string, &size) == ERROR_SUCCESS)
	{
		MessageBoxW(0, string, L"�������� �����", MB_OK);
	}
}