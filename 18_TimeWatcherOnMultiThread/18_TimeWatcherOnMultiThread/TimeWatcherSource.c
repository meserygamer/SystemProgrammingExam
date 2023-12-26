#include <Windows.h>
#include <stdio.h>

BOOL isStopped = 0;
BOOL isShowTime = 0;

int Counter = 0;

DWORD TimeWatcher(void* Args) //—екундомер
{
	while (TRUE)
	{
		if (isStopped)
		{
			Sleep(100);
			continue;
		}
		isShowTime = 1;
		Sleep(1000);
		Counter++;
	}
}

DWORD ShowTime(void* Args) //ѕоток дл€ показа времени,
//функци€ system("cls") слишком медленна€ и тормозит секундомер, на дистанции в минуту отставние в 3-4 секунды
//— этим отставание 0-1 секунда на минуту
{
	for (;;)
	{
		if (isShowTime)
		{
			system("cls");
			printf("%d:%d", Counter / 60, Counter % 60);
			isShowTime = 0;
		}
	}
	
}

int main()
{
	HANDLE TimeWatcherThread = CreateThread(NULL, 0, TimeWatcher, NULL, 0, NULL);
	HANDLE ShowTimeThread = CreateThread(NULL, 0, ShowTime, NULL, 0, NULL);

	for (;;) //ƒл€ считывани€ нажати€, при нажатии на enter секундомер ставитс€ на паузу
		//ѕри повторном нажатии снимаетс€ с паузы
	{
		getchar();
		isStopped = !isStopped;
	}
}