#include<stdio.h>
#include<unistd.h>

int main(int argc, char const *argv[])
{
    printf("Before exec Call\n");

    printf("Used pwd in exec: Showing Path Of Program\n");
    
    execl("/bin/pwd","/bin/pwd",NULL);

    printf("This Is Not Showing On Console Because exec Executing Above Program\n");

    return 0;
}
