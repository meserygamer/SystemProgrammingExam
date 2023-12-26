#include <stdio.h>
#include <stdlib.h>

int main(int c, char* argv[])
{
	printf("Привет, я дочерний процесс!\n");
	for (int i = 0; i < c; i++)
	{
		printf("аргумент №%d - %s\n", i+1, argv[i]);
	}
}