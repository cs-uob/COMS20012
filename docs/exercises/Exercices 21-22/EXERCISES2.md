# Exercises sheet W2

## Questions

1. Explain the difference between design flaw and programming error by giving one example.
2. What is a spatial memory safety violation?
3. Is buffer overflow error an example of *spatial* or *temporal* safety  violation? Explain your answer.
4. In the reading [article](http://www.pl-enthusiast.net/2014/07/21/memory-safety/)  by Prof. hicks, he provides a definition of memory safety as *No accesses to undefined memory*. Later he argues that it does not cover buffer overflows. Can you explain why so?

	
5. Consider the following code:  
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

     
7. What is control hijacking in the context of exploitation? Explain one possible way to hijack control in the presence of stack overflow bug?


8. Dr. Blahbah claims that buffer overflow attacks via stack smashing are made possible by the fact that stacks grow downwards (to-wards smaller addresses) on most popular modern architectures. Therefore, future architectures should ensure that the stack grows upwards; this would provide a good defense against buffer over-flow. Do you agree or disagree? Why?


9. What is a integer truncation error? Can you provide an example of buggy code where an integer overflow can cause overflow memory corruption? See, for example [this](http://phrack.org/issues/60/10.html)

10. Consider the following code:


		int catvars(char *buf1, char *buf2, unsigned int len1,
			unsigned int len2){
		    char mybuf[500];

		    if((len1 + len2) > 500){    /* [3] */
			return -1;
		    }

		    memcpy(mybuf, buf1, len1);      /* [4] */
		    memcpy(mybuf + len1, buf2, len2);  /* [5] */

		    do_some_stuff(mybuf);

		    return 0;
		}



	As is discussed in this [article](http://phrack.org/issues/60/10.html){:target="_blank"}, there is a integer overflow in the above code which will overflow `mybuf` at line [4] and/or [5]. The problem is at line [3]. what value to `len1` and `len2` you will use to trigger the bug?




11. What is a format string bug? Exaplain by example which of the CIA properties can be violated by a format string bug.


## Answers

1. A design flaw is a weakness in the code that, whilst not incorrect can lead to the program entering an incorrect state.  A programming error is a flaw in the code that introduces incorrectness.
2. A spatial memory safety violation is where a program accesses memory that would not normally be accessible to it.
3. Spatial. you are writing into a memory location out-of-bound.
4. Because the memory that is being overwritten is allocated. i.e. defined, whereas the definition says that only the access to undefined memory is the problem. Obviously, this does not cover buffer overflows.
5. a) stack buffer overflow. b) `gets(name)` c) `count` and `x` d) use safe functions, like fgets, scanf.
6. the loop runs 201 times, overflowing array variable. this is called off-by-one error. the 1 byte overflow corrupts the variable `x` in such a way that at the end of the loop, the value of the variable becomes less than 200, thereby making the loop condition failed.
7. Control hijacking is taking control of the execution of a program, enabling it to run code or paths through the code that would not normally be taken by standard execution.  One way to hijack control would be to overwrite the return address of a function on the stack to point to code the attacker wishes to run.
8. Disagree. Changing the direction of stack  will only affect which memory locations can be corrupted, but the bug still remains there. it will cause attackers to develop the exploit in a different way.
9. `unsigned int x; unsigned char y; y = (unsigned char) x;`. If x > 256 it will be truncated to fit
10. len1= 4,294,967,200, len2=100. See and article for more info.  
11. Information disclosure is the major concern for format string bugs: missing arguments will still be printed if there is a format specifier for them.  This can lead to the contents of the stack being leaked and confidetiality being breached. Also, %n causes overwriting a memory location, leading to integrity violation.  Using %n to write to a NULL pointer can lead to crashes and availability issues too!


