# Exercises sheet: Intro to Software Security

## Questions


1. What is a spatial memory safety violation?

2. In the reading [article](http://www.pl-enthusiast.net/2014/07/21/memory-safety/)  by Prof. hicks, he provides a definition of memory safety as *No accesses to undefined memory*. Later he argues that it does not cover buffer overflows. Can you explain why so?

	
3. Consider the following code:  
    ```
    void main(){
    	int count=0;
    	int x;
    	char name[20];
    	int y;
    	int z;
    	printf("Enter you name..");
    	gets(name);
    	printf("your name is: %s", name);
    	return 0;
    }
    ```
    **Assume that variables are allocated on the stack in the same order as they are declared in the code, i.e. x will be near `rbp (ebp)` and z wil be near `rsp (esp)`.**

    Answer the following questions.

    	a. What memory error does this code have?

 	b. What is the source of that memory error?

 	c. Which variables may be corrupted by that error?

 	d. How can you fix that error?


6. Consider the following code:
    ```
    //loop.c
    #include <stdio.h>
    int main()
    {
        int x;
        char array[200];
        for(x=0;x<=200;x++)
        {
        	array[x]='A';
        	printf("x: %d", x);
        }
        printf("Done\n");
        return 0;
    }
    ```
     Compile the code with `gcc -m32 -fno-stack-protector loop.c -o loop32` and run it. On my machine, the code goes in an infinite loop. Can you find a probable cause for this?

     
4. What is control hijacking in the context of exploitation? Explain one possible way to hijack control in the presence of stack overflow bug?



5. What is a format string bug? 



