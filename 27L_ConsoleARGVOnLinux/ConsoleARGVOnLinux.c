#include <stdio.h>
#include <stdlib.h>

int main(int count, char* argv[])
{
	for (int i = 0; i < count; i++)
	{
		printf("аргумент №%d - %s\n", i+1, argv[i]);
	}
	getchar();
}