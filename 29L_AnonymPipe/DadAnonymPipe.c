#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <malloc.h>


int main()
{
    int* pipeDots = calloc(2, sizeof(int));
    if(pipe(pipeDots) == -1) //Если не удалось создать завершаем программу
    {
        _exit(1);
    }
    int pipeRead = pipeDots[0];
    int pipeWrite = pipeDots[1];
    int desc = fork();
    switch (desc)
    {
    case 0:
        close(pipeWrite);
        char* buffer = calloc(256, sizeof(char));
        int numSymbols;
        do
        {
            numSymbols = read(pipeRead, buffer, 256);
            if(numSymbols != 0) printf("Считано - %d\nСообщение - %s\n", numSymbols, buffer);
        } while (numSymbols != 0);
        close(pipeRead);
        printf("Сын закончил считывание!\n");
        getchar();
        _exit(-1);
        break;
    default:
        close(pipeRead);
        write(pipeWrite, "Проверка связи в канале", 44);
        close(pipeWrite);
        wait(NULL);
        printf("Батя дождался сына!\n");
        break;
    }
}