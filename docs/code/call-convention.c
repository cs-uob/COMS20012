#include <stdio.h>
int func(int a, int b, int c, int d, int e, int f)
{
    int v1, v2;
    v1=a+b+c;//risky
    v2=d+e+f;//risky
    return (v1+v2)/2;
}

int main()
{
    int x;
    printf("IN the main\n");
    x= func(1,2,3,4,5,6);
    printf("X is: %d\n",x);
    return 0;
}
    
