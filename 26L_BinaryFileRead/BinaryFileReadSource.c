#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int* buffer;

int main()
{
	FILE *file = fopen("TestBinaryFile.bin", "wb+"); 
	buffer = calloc(1, sizeof(int));
	buffer[0] = 42;
	fwrite(buffer, 4, 1, file); 
	fclose(file);
	file = fopen("TestBinaryFile.bin", "rb+");
	free(buffer);
	buffer = calloc(1, sizeof(int));
	fread(buffer, 4, 1, file);
	printf("Число считанное из файла - %d", buffer[0]);
}