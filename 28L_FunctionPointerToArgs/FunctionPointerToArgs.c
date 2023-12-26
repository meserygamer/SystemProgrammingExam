#include <stdio.h>

typedef double (*MathFunc)(double, double);

double plus(double x1, double x2);
double minus(double x1, double x2);
double calculator(double x1, double x2, MathFunc func);

int main()
{
	printf("2 + 2  = %lf\n", calculator(2, 2, plus));
	printf("2 - 3  = %lf\n", calculator(2, 3, minus));
}

double calculator(double x1, double x2, MathFunc func)
{
	return func(x1, x2);
}

double plus(double x1, double x2)
{
	return x1 + x2;
}

double minus(double x1, double x2)
{
	return x1 - x2;
}