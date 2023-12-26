#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


int isStopped = 0;
int isShowTime = 0;

char* buffer;

void* TimeWatcher(void* Args) //Секундомер
{
    int Counter = 0;

	while (1)
	{
		if (isStopped)
		{
			continue;
		}
        system("clear");
        sprintf(buffer, "%d:%d\n", Counter / 60, Counter % 60); //printf не работает
        //, пришлось использовать write
		write(STDOUT_FILENO, buffer, 256);
		sleep(1);
		Counter++;
	}
    return NULL;
}

int main()
{
    buffer = calloc(256, sizeof(char));
    pthread_t TimeWatcherThread, ShowTimeThread;
    pthread_create(&TimeWatcherThread, NULL, TimeWatcher, NULL);
    pthread_detach(TimeWatcherThread);
	while(1) //бесконечный цикл для проверки нажатия пользователем enter,
    // при нажатии таймер останавливается или возобновляется
	{
	    getchar();
	    isStopped = !isStopped;
	}
    return 0;
}