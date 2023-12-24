#include <Windows.h>
#include <stdio.h>
#include <string.h>

typedef struct Coordinates
{
	double x;
	double y;
} Coordinates;

double (*SegmentLengh)(Coordinates dot1, Coordinates dot2);

int main()
{
	HMODULE library = LoadLibrary(L"DLLibrary.dll");

	system("chcp 1251>cls");

	SegmentLengh = GetProcAddress(library, "SegmentLengh");

	Coordinates dot1 = { 1,1 };
	Coordinates dot2 = { 2,2 };

	printf("���������� ����� ������� {1;1} � {2;2} - %lf", SegmentLengh(dot1, dot2));

	FreeLibrary(library);
}