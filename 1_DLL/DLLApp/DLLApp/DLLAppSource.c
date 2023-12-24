#include <stdio.h>
#include <Windows.h>

double (*plus)(double x1, double x2);
double (*minus)(double x1, double x2);

int main()
{
	HMODULE library = LoadLibrary(L"DLLibrary");

	plus = GetProcAddress(library, "plus");
	minus = GetProcAddress(library, "minus");

	printf("2 + 2 = %lf\n", plus(2, 2));
	printf("2 - 2 = %lf\n", minus(2, 2));
}