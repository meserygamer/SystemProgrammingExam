#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* CallFactorialFunction(void* args)
{
    //int* factorialNumber = calloc(1, sizeof(int));
	return factorial(*((int*)args)); //Так делать нельзя, мы вместо void* передаём int
    //Но так как мы получаем значение из потока в тип int*, а не void**, то он запихнет наш
    //int в int* и всё ок
}

int factorial(int number)
{
	if (number == 0 || number == 1) return 1;
	return number * factorial(number - 1);
}

void CleanStdin()
{
	while (fgetc(stdin) != '\n') continue;
}

int main()
{
	while (1)
	{
		int number = 0;
		printf("Введите число:\n");
		if (scanf("%d", &number) != 1)
		{
			CleanStdin();
			system("clear");
			continue;
		}
		if (number < 0)
		{
			system("clear");
			printf("Вычислить факториал невозможно!\n");
            continue;
		}
        pthread_t thread;
		pthread_create(&thread, NULL, CallFactorialFunction, &number);
		pthread_join(thread, &number);
		system("clear");
		printf("Факториал введенного числа - %d\n", number);
	}
}