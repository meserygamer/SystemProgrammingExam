#include <stdio.h>
#include <stdlib.h>

int main(int count, char* argv[])
{
	system("chcp 1251>nul");
	for (int i = 0; i < count; i++)
	{
		printf("�������� �%d - %s\n", i+1, argv[i]);
	}
	getchar();
}