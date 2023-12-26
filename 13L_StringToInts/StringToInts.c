#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	printf("Введите строку из цифр разделенных пробелами:\n");
	char* buffer = calloc(512, sizeof(char));
	gets(buffer);
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