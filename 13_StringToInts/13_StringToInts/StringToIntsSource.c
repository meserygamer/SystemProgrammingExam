#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	system("chcp 65001>nul"); //Тест смены кодировки с ANSI на UTF-8
	printf("Введите строку из цифр разделенных пробелами:\n");
	char* buffer = calloc(512, sizeof(char));
	gets_s(buffer, 512);
	char* num = strtok(buffer, " ");
	int* ints = calloc(1, sizeof(int));
	int i = 0;
	for (; num != NULL; i++)
	{
		ints[i] = atoi(num);
		num = strtok(NULL, " ");
		ints = realloc(ints, sizeof(int) * (i + 2));
	}
	for (int j = 0; j < i; j++)
	{
		printf("Число №%d - %d\n", j+1, ints[j]);
	}
}