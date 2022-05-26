#include<stdio.h>
#include<string.h>

char str[] = "HELLO SIR";
int main()
{
    int a;
    printf("ENTER VALUE OF a\n");
    scanf("%d",&a);
    printf("STRING = %s\n",str);
    int l = strlen(str);
    printf("LENGTH OF STRING %d\n",l);

    printf("Hello, World!\n");
}