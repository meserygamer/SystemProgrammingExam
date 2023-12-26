#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int counter=0;
char* buffer;

int main()
{
    daemon(0,0);
    buffer = calloc(256, sizeof(char));
    while(1)
    {
        sprintf(buffer,"notify-send \"Счетчик - %d\"",++counter);
        system(buffer);
        sleep(5);
    }  
}