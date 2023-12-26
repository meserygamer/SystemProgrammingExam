#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    switch (fork())
    {
    case 0:
        printf("Я сын\n");
        break;
    
    default:
        printf("Я батя\n");
        break;
    }

    int* ints = calloc(10000, sizeof(int));
    if(ints == NULL)
    {
        printf("Память не удалось выделить\n");
    }

    if(open("test", O_WRONLY) == -1)
    {
        printf("Не удалось открыть файл\n");
    }
}