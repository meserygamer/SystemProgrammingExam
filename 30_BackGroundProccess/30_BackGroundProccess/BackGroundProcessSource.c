#include <Windows.h>
#include <stdio.h>

int counter = 0;
LPWSTR buffer;

DWORD ShowMessagebox(void* Arguments)
{
	wsprintfW(buffer, L"Счетчик - %d", counter);
	MessageBox(0, buffer, L"Вас поставили на счетчик!", MB_OK);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE preInstance, LPSTR lpArgs, int nShowCmd) //Особая точка входа фоновых приложений
{
	buffer = calloc(256, sizeof(WCHAR));
	while (1)
	{
		counter++;
		CreateThread(NULL, 0, ShowMessagebox, NULL, 0, NULL); //Если вы хотите прям каждые 5 секунд, то имеет смысл,
		//так как MessageBox приостанавливает поток пока его не закроют, А таким образом мы открываем для него новый поток и отдаём ему,
		//Главный не блокируется, Если не надо, то просто вставляем код MessageBox сюда
		Sleep(5000);
	}
}