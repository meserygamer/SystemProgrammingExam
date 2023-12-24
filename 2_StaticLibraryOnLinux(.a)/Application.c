#include <stdio.h>

double plus(double, double);
double minus(double, double);

int main()
{
    printf("2 + 2 = %lf\n", plus(2.0, 2.0));
    printf("2 - 3 = %lf\n", minus(2.0, 3.0));
}