/* This is example code to demonstrate control hijacking via over-writing
 * the saved return address on the stack */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* By default some systems use checked string library functions that check for 
 * buffer overflows... good for security; but bad for security labs! 
 */
char *my_strcpy(char *dest, char *src) {
    for (size_t i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    return dest;
}

int admin_pin=2468; // This is admin pin (Yeah, not a good practice to hardcode!)
void foo(char * input)
{
    int random=50;
    char buf[20];
    my_strcpy(buf, input);// this is where the overflow happens
    /* if the input length is greater than buf (20), it will start overflowing 
     * the adjacent memory including the saved return address. You need to find
     * how long the input string should be to precisely overwrite the 8 byte 
     * long saved return address. Then you need to find from which offset in 
     * the input, you start overflowing the return address. For example, if you use
     * AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIHHHHJJJJKKKKLLLLMMMM as the input, you
     * need to find from which letter, you start overflow return address. let us 
     * assume it is HHHHIIII which overflow the return address memory. The you 
     * need to replace HHHHIIII with the address of the admin() entry point. 
     * Let's assume it is 0x0000555555554858. Then you need to contruct the final
     * input as AAAABBBBCCCCDDDDEEEEFFFFGGGG\x58\x48\x55\x55\x55\x55 (notice the 
     * reverse order, which due to the fact that intel is little endian 
     * architecture!). You can ignore the remaining zeros. Also notice that we 
     * used \x to so that these are not interpreted as ASCII symbols. you will 
     * need to use `echo -ne "ABC\x45\x33"` to give such a string on the 
     * command propmt (your shell).
     * */
    printf("Hello %s\n", buf);
}

void admin()
{
    printf("**** Welcome to Admin console ****\n");
}

int main(int argc, char ** argv)
{
    int input;
    if (argc != 2)
    {
        printf("Run prog with one argument...\n ");
        return -1;
    }
    printf("[*] Enter admin pin if you are an admin or enter 0\n");
    scanf("%d", &input);
    if(input == admin_pin){
        admin();
    } else foo(argv[1]);

    return 0;
}

