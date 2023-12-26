#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int* buffer;

int main()
{
	system("chcp 1251>nul");
	FILE *file = fopen("TestBinaryFile.bin", "wb+"); //Открываем бинарный файл (создаём) флаг wb+ для записи или создания в бинарный файл
	buffer = calloc(1, sizeof(int));
	buffer[0] = 42;
	fwrite(buffer, 4, 1, file); //Записываем в файл, так как размер int - 4 байта, то 2 аргумент 4 
	fclose(file);
	file = fopen("TestBinaryFile.bin", "rb+"); //Открываем бинарный файл, флаг rb+ для считывания из бинарного файла
	free(buffer);
	buffer = calloc(1, sizeof(int));
	fread(buffer, 4, 1, file); //Считываем 4 байта из файла
	printf("Число считанное из файла - %d", buffer[0]);
}