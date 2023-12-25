#include <Windows.h>
#include <stdio.h>

#define MESSAGE L"Hello buffer, I'm Kirill!" //������ ������ � ���������� ���������� � ������

int main()
{
	int MessageLen = wcslen(MESSAGE) + 1; //���������� ������ � �������
	HGLOBAL MemoryDesc = GlobalAlloc(GMEM_MOVEABLE, MessageLen * sizeof(wchar_t)); //��������� �������� ���� ������
	memcpy(GlobalLock(MemoryDesc), MESSAGE, MessageLen * sizeof(wchar_t)); //�������� ������
	GlobalUnlock(MemoryDesc); //������ ��������� ������� ������ ��� ������
	OpenClipboard(0); //��������� �����
	EmptyClipboard(); //�������
	SetClipboardData(CF_UNICODETEXT, MemoryDesc); //�������� ������ �� ����
	CloseClipboard(); //��������� ������
	return 0;
}