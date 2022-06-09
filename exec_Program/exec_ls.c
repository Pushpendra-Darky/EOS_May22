#include<stdio.h>
#include<unistd.h>

int main(int argc, char const *argv[])
{
    printf("Before exec Call\n");

    printf("Used ls In exec: Showing Path's Content Of This Program\n");
    
    execl("/bin/ls","/bin/ls",NULL);

    printf("This Is Not Showing On Console Because exec Executing Above Program\n");

    return 0;
}
