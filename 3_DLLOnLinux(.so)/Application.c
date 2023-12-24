#include <stdio.h>
#include <dlfcn.h>

void (*message)();
double (*plus)(double x1, double x2);
double (*minus)(double x1, double x2);

int main()
{
    void* library = dlopen("./Library.so", RTLD_LAZY);
    message = dlsym(library, "message");
    plus = dlsym(library, "plus");
    minus = dlsym(library, "minus");
    message();
    printf("15 + 10 = %lf\n", plus(10.0, 15.0));
    printf("15 - 10 = %lf\n", minus(15.0, 10.0));
    dlclose(library);
}