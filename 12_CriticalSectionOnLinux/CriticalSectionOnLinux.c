#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

int counter = 0;

pthread_mutex_t Mutex = PTHREAD_MUTEX_INITIALIZER; //Инициализируем мьютекс (Он же критическая секция) 

void* ThreadFunction(void *Args)
{
    pthread_mutex_lock(&Mutex); //Закрываемся от других потоков

    int innerCounter = counter;

    for(int i = 0; i < 100000; i++)
    {
        innerCounter++;
    }

    counter = innerCounter;

    pthread_mutex_unlock(&Mutex); //Открываемся для других потоков
}

int main()
{
    pthread_t thread1, thread2, thread3;
    pthread_create(&thread1, NULL, ThreadFunction, NULL); //Создаем поток 1
    pthread_create(&thread2, NULL, ThreadFunction, NULL); //Создаем поток 2
    pthread_create(&thread3, NULL, ThreadFunction, NULL); //Создаем поток 3
    pthread_join(thread1, NULL); //Ждем поток 1
    pthread_join(thread2, NULL); //Ждем поток 2
    pthread_join(thread3, NULL); //Ждем поток 3
    printf("Потоки закончили работу, счетчик - %d", counter);
    return 0;
}