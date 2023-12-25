#include <stdio.h>
#include <unistd.h>
#include <malloc.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFSIZE 256

#define CLIENT_PATH "/tmp/testClientNamedPipe"
#define SERVER_PATH "/tmp/testServerNamedPipe"
#define MESSAGE_FOR_CLIENT "Ваше сообщение принято!"

int main()
{
    remove(SERVER_PATH); //Удаляем предыдущий файл
    mkfifo(SERVER_PATH, 0664); //Задаём права доступа к очереди
    char* buffer = calloc(BUFFSIZE, sizeof(char));
    for(;;)
    {
        int ServDesc = open(SERVER_PATH, O_RDONLY);
        read(ServDesc, buffer, 256);
        close(ServDesc);
        printf("Клиент прислал сообщение - %s\n", buffer);
        int ClientDesc = open(CLIENT_PATH, O_WRONLY);
        write(ClientDesc, MESSAGE_FOR_CLIENT, sizeof(MESSAGE_FOR_CLIENT));
        close(ClientDesc);
    }
}