#include <windows.h>
#include <stdio.h>

#define INPUT "Input.txt"
#define OUTPUT "Output.txt"

int main()
{
	HANDLE fileInputHandle = CreateFileA(INPUT, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
	char* buffer = calloc(256, sizeof(char));
	ReadFile(fileInputHandle, buffer, 256, NULL, NULL);
	CloseHandle(fileInputHandle);
	HANDLE fileOutputHandle = CreateFileA(OUTPUT, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, NULL, NULL);
	WriteFile(fileOutputHandle, buffer, 256, NULL, NULL);
	CloseHandle(fileOutputHandle);
}