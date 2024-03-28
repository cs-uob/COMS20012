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


4. Consider the following code:
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

     
5. What is control hijacking in the context of exploitation? Explain one possible way to hijack control in the presence of stack overflow bug?



6. What is a format string bug? 


## Answers

1. A spatial memory safety violation is where a program accesses memory that would not normally be accessible to it.
2. Because the memory that is being overwritten is allocated. i.e. defined, whereas the definition says that only the access to undefined memory is the problem. Obviously, this does not cover buffer overflows.
3. a) stack buffer overflow. b) `gets(name)` c) `count` and `x` d) use safe functions, like fgets, scanf.
4. The loop runs 201 times, overflowing array variable. this is called off-by-one error. the 1 byte overflow corrupts the variable `x` in such a way that at the end of the loop, the value of the variable becomes less than 200, thereby making the loop condition failed.
5. Control hijacking is taking control of the execution of a program, enabling it to run code or paths through the code that would not normally be taken by standard execution.  One way to hijack control would be to overwrite the return address of a function on the stack to point to code the attacker wishes to run.
6. Format string is a memory bug that can lead to the contents of the stack being leaked. Also, %n causes overwriting a memory location.  

