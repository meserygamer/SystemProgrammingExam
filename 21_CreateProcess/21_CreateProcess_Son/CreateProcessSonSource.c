#include <stdio.h>
#include <stdlib.h>

int main(int c, char* argv[])
{
	system("chcp 1251>nul");
	printf("������, � �������� �������!\n");
	for (int i = 0; i < c; i++)
	{
		printf("�������� �%d - %s\n", i+1, argv[i]);
	}
}