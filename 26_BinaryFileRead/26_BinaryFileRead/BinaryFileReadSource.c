#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int* buffer;

int main()
{
	system("chcp 1251>nul");
	FILE *file = fopen("TestBinaryFile.bin", "wb+"); //��������� �������� ���� (������) ���� wb+ ��� ������ ��� �������� � �������� ����
	buffer = calloc(1, sizeof(int));
	buffer[0] = 42;
	fwrite(buffer, 4, 1, file); //���������� � ����, ��� ��� ������ int - 4 �����, �� 2 �������� 4 
	fclose(file);
	file = fopen("TestBinaryFile.bin", "rb+"); //��������� �������� ����, ���� rb+ ��� ���������� �� ��������� �����
	free(buffer);
	buffer = calloc(1, sizeof(int));
	fread(buffer, 4, 1, file); //��������� 4 ����� �� �����
	printf("����� ��������� �� ����� - %d", buffer[0]);
}