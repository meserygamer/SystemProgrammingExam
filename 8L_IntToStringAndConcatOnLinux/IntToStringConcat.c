#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//ДАННЫЙ КОД ВЗЯТ У КСЮШИ КОТКОВОЙ С НЕБОЛЬШИМИ ПРАВКАМИ!
//НЕ ЗАБУДЬТЕ СКАЗАТЬ ЕЙ СПАСИБО

#define HELLO "Привет "
#define WORLD "Мир!"

int lenght(char* str) // длина строки
{
    int lenght = 0;
    while (*str != '\0') // пока не конец строки ходим
    {
        lenght++; // увеличиваем длину
        str++;    // переходим на следующий символ
    }
    str -= lenght - 1; // возвращаемся в начало строки

    return lenght;
}

char* cat(char* str1, char* str2) // склейка
{
    int lenght1 = lenght(str1); // длина 1 строки
    int lenght2 = lenght(str2); // длина 2 строки

    size_t size = lenght1 + lenght2 + 1;       // размер новой строки
    char* newstr = calloc(size, sizeof(char)); // новая строка

    for (int i = 0; i < lenght1; i++) // пишем 1 строку
    {
        newstr[i] = str1[i];
    }

    for (int i = 0; i < lenght2; i++) // пишем 2 строку
    {
        newstr[i + lenght1] = str2[i];
    }
    newstr[lenght1 + lenght2] = '\0';

    return newstr;
}

char* numstr(int n)
{
    switch (n)
    {
    case 0: return "0";
    case 1: return "1";
    case 2: return "2";
    case 3: return "3";
    case 4: return "4";
    case 5: return "5";
    case 6: return "6";
    case 7: return "7";
    case 8: return "8";
    case 9: return "9";
    }
}

char* convert(int num)
{
    char* newstr = calloc(100, sizeof(char));
    newstr = "\0";
    if (num == 0) newstr = cat("0", newstr);
    while (1)
    {
        if (num == 0) break;
        int n = abs(num % 10);
        char* elem = numstr(n);
        newstr = cat(elem, newstr);
        num = num / 10;
    }
    return newstr;
}

int main()
{
    double n = 55;
    char* newnum = convert(n);
    puts(newnum);
    char* newstr = cat(HELLO, WORLD);
    printf("%s\n", newstr);
    return 0;
}