#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int main(int num, char* argv[])
{
	HANDLE PIPEREAD, PIPEWRITE;
	PIPEREAD = (HANDLE)atoi(argv[0]);
	PIPEWRITE = (HANDLE)atoi(argv[1]);
	char* buffer = calloc(256, sizeof(char));
	printf("\n�������:\n������ - %u\n������ - %u\n", PIPEREAD, PIPEWRITE);
	ReadFile(PIPEREAD, buffer, 256, NULL, NULL);
	puts(buffer);
	return 5;
}