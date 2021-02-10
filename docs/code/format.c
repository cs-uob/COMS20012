#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_pin()
{
    return rand();// assume that this is a secret number retrieve from some DB
                // Also as it is called without a seed, it will print the same
                // random number, which is intentional. this works as a hint
                // for your lab.
}


int check(int upin, int spin)
{
    if (upin == spin)
        return 1;
    else return -1;
}
int main(int argc, char *argv[])
{
    
    int spin, upin,auth;
    char name[100];
    char welcome[110]="Hello ";
    spin=get_pin();
    printf("Enter you name..\n");
    scanf("%99s",name);
    strcat(welcome, name);
    printf(welcome);// format string bug site!!!!
    printf("Enter you pin:");
    scanf("%d",&upin);
    
    auth=check(upin,spin);
    //printf(welcome);
    if(auth==-1)
    {
        printf("Sorry, try again...\n");
        exit(0);
    }
    printf("Authenticated...\n");
    return 0;
}
    
        
