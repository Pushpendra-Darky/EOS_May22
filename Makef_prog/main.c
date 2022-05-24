/*PROGRAM FOR CALCULATOR*/
#include<stdio.h>
#include<stdlib.h>
#include "cal_op.h"
/*main function*/
int main()
{
    int num1,num2;
    int ch;
    int ad,sb,ml,dv;
    printf("\nENTER THE TWO NUMBER\n");
    scanf("%d%d",&num1,&num2);
    while(1)
    {
        printf("\nENTER THE OPERATION\n");
        printf("1 FOR ADD\n");
        printf("2 FOR SUB\n");
        printf("3 FOR MUL\n");
        printf("4 FOR DIV\n");
        printf("5 FOR EXIT\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    ad=add(num1,num2);
                    printf("\nADDITION = %d\n",ad);
                    exit(1);
                    break;
            case 2:
                    sb=sub(num1,num2);
                    printf("\nSUBTRACTION = %d\n",sb);
                    exit(1);
                    break;
            case 3:
                    ml=mul(num1,num2);
                    printf("\nMULTIPLICATION = %d\n",ml);
                    exit(1);
                    break;
            case 4:
                    dv=divs(num1,num2);
                    printf("\nDIVISION = %d\n",dv);
                    exit(1);
                    break;
            case 5:
                    printf("\n\nTHANKS FOR USING CALC\n");
                    exit(1);
            default:
                    printf("\nPLEASE ENTER THE RIGHT OPERATION\n\n");
        }
    }
    

    return 0;
}
