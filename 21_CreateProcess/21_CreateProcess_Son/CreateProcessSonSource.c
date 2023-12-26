#include <stdio.h>
#include <stdlib.h>

int main(int c, char* argv[])
{
	system("chcp 1251>nul");
	printf("Привет, я дочерний процесс!\n");
	for (int i = 0; i < c; i++)
	{
		printf("Аргумент №%d - %s\n", i+1, argv[i]);
	}
}