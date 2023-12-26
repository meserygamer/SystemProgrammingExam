#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	printf("Привет, я главный процесс!\n");
	char** comands = calloc(4, sizeof(char*));
    comands[0] = "Hei";
    comands[1] = "Hei";
    comands[2] = "Hei";
    comands[3] = NULL; //Без Null не понимает, где конец у аргументов
	switch(fork())
    {
        case 0:
        {
            execve("./CreateProcessSonOnLinux", comands, NULL);
        }
        default:
        {
            wait(NULL);
        }
    }
}