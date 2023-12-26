#include <stdio.h>
#include <windows.h>
#include <math.h>

#define STRING L"1"

int lenLPWSTR(LPWSTR string)
{
	int len = 1;
	while (*string != 0)
	{
		len++;
		string++;
	}
	return len;
}

int WCHAR_TO_INT(WCHAR c)
{
	switch (c)
	{
	case 48:
		return 0;
	case 49:
		return 1;
	case 50:
		return 2;
	case 51:
		return 3;
	case 52:
		return 4;
	case 53:
		return 5;
	case 54:
		return 6;
	case 55:
		return 7;
	case 56:
		return 8;
	case 57:
		return 9;
	}
}

int convert(LPWSTR s)
{
	int lenghSTR = lenLPWSTR(s) - 2;
	int razrd = 0;
	int numberres = 0;
	for (int i = lenghSTR; i >= 0; i--)
	{
		numberres += WCHAR_TO_INT(s[i]) * pow(10, razrd++);
	}
	return numberres;
}

int main()
{
	 int res = convert(STRING);
}