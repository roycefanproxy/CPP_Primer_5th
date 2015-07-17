#include "header.h"

int fac(int x)
{
    int ret = 1;
    if(x < 1)
        return 0;
    for(int i = 1; i <= x; i++)
        ret *= i;

    return ret;
}
