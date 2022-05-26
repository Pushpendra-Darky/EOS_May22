#include<stdio.h>
#include<stdlib.h>
int a;  
int b=10;
int add(int,int);
int main()
{
    int result=0;
    int *p=NULL;
    p=(int *)malloc(sizeof(int));
    printf("ENTER THE VALUE OF a\n");
    scanf("%d",&a);
    result=add(a,b);
    printf("ADDITION OF a and b %d\n",result);

    return 0;
}
int add(int a, int b)
{
    return (a+b);
}