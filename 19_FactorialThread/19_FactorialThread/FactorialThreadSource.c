#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

DWORD CallFactorialFunction(void* args)
{
	return factorial(*((int*)args));
}

int factorial(int number)
{
	if (number == 0 || number == 1) return 1;
	return number * factorial(number - 1);
}

void CleanStdin()
{
	while (fgetc(stdin) != '\n') continue;
}

int main()
{
	system("chcp 1251>nul");
	while (1)
	{
		int number = 0;
		printf("Введите число факториал, которого желаете узнать\n");
		if (scanf("%d", &number) != 1)
		{
			CleanStdin();
			system("cls");
			continue;
		}
		if (number < 0)
		{
			system("cls");
			printf("Вычислить факториал невозможно\n");
			continue;
		}
		HANDLE handle = CreateThread(NULL, 0, CallFactorialFunction, &number, 0, NULL);
		WaitForSingleObject(handle, INFINITE);
		GetExitCodeThread(handle, &number);
		system("cls");
		printf("Результат вычислений - %d\n", number);
	}
}