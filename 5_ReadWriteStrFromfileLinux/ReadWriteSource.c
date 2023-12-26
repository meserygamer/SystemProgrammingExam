#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

#define InputFilePath "./Input.txt"
#define OutputFilePath "./Output.txt"


int main()
{
    int inputDesc = open(InputFilePath, O_RDONLY);
    char* buffer = calloc(256, sizeof(char));
    int readedBytes = read(inputDesc, buffer, 256);
    close(inputDesc);
    int OutputDesc = open(OutputFilePath, O_CREAT | O_WRONLY, S_IRWXU | S_IRWXG | S_IRWXO);
    write(OutputDesc, buffer, readedBytes);
    close(OutputDesc);
}