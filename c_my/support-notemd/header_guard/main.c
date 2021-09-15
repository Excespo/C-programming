#include<stdio.h>
#include "multi_included.h"
#include "inter_included.h"

#ifdef __M_I
int main()
{
    run();
    run2();
    return 0;
}
#endif