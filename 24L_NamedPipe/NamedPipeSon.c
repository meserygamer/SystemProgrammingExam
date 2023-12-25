#include <stdio.h>
#include <unistd.h>
#include <malloc.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFSIZE 256

#define SERVER_PATH "/tmp/testServerNamedPipe"
#define CLIENT_PATH "/tmp/testClientNamedPipe"
#define MESSAGE_FOR_SERVER "Здесь кто-нибудь есть?"

int main()
{
    remove(CLIENT_PATH);
    mkfifo(CLIENT_PATH, 0664);
    char* buffer = calloc(BUFFSIZE, sizeof(char));
    while(1)
    {
        int ServerFIFODesc = open(SERVER_PATH, O_WRONLY);
        write(ServerFIFODesc, MESSAGE_FOR_SERVER, sizeof(MESSAGE_FOR_SERVER));
        close(ServerFIFODesc);
        int ClientFIFODesc = open(CLIENT_PATH, O_RDONLY);
        read(ClientFIFODesc, buffer, BUFFSIZE);
        printf("Сервер ответил - %s\n", buffer);
        close(ClientFIFODesc);
        sleep(1);
    }
}