#include<stdio.h>

#define STRINGIFY_INNER(x) #x
#define STRINGIFY(x) STRINGIFY_INNER(x)

/*__LINE__ is a built-in macro in compiler*/
void main(void)
{
    printf("%s\n", STRINGIFY_INNER(__LINE__));
    printf("%s\n", STRINGIFY(__LINE__));
}
