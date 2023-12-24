#include <stdio.h>

__declspec(dllexport) double _cdecl minus(double x1, double x2);
__declspec(dllexport) double _cdecl plus(double x1, double x2);

double minus(double x1, double x2)
{
	return x1 - x2;
}

double plus(double x1, double x2)
{
	return x1 + x2;
}