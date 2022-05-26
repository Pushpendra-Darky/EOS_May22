#include <stdio.h>
#include "arith.h"

int main()
{
    int output=0;
    output=add(35,34);
    printf("\nADDITION OF a & b IS: %d\n",output);
    printf("\nSUBTRACTION OF a & b IS: %d\n",sub(35,34));
    printf("\nMULTIPLICATION OF a & b IS: %d\n",mul(15,10));
    printf("\nDIVISION OF a & b IS: %d\n",div(75,25));

    return 0;
}