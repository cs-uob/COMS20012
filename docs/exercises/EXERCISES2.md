# Exercises sheet W2

## Fill our survey

<iframe width="640px" height= "480px" src= "https://forms.office.com/Pages/ResponsePage.aspx?id=MH_ksn3NTkql2rGM8aQVG5N9pWWUNd5Khd6GR62JgsZURFFGVlRYNjFDTDVUWjlQUFpZNFJXVE9NMC4u&embed=true" frameborder= "0" marginwidth= "0" marginheight= "0" style= "border: none; max-width:100%; max-height:100vh" allowfullscreen webkitallowfullscreen mozallowfullscreen msallowfullscreen> </iframe>

## Questions

**There will be no written corrections. Exercises will be discussed during the recorded live Q&A. Come and prepare questions.**

1. Exaplain the difference between design flaw and programming error by giving one example.
	**ANS:** see slides
2. What is a spatial memory safety violation?
	**ANS:** See slides
3. Is buffer overflow error an example of *spatial* or *temporal* safety  violation? Explain your answer.
	**ANS:** spatial. you are writing into a memory location out-of-bound. see slides for more explanation.
4. In the reading [article](http://www.pl-enthusiast.net/2014/07/21/memory-safety/)  by Prof. hicks, he provides a definition of memory safety as *No accesses to undefined memory*. Later he argues that it does not cover buffer overflows. Can you explain why so?
	**ANS:** because the memory that is being overwritten is allocated. i.e. defined, whereas the definition says that only the access to undefined memory is the problem. Obviously, this does not cover buffer overflows. 
	
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
 	**ANS:** stack buffer overflow.
 	b. What is the source of that memory error?
 	**ANS:** `gets(name)`
 	c. Which variables may be corrupted by that error?
 	**ANS:** `count` and `x`
 	d. How can you fix that error?
 	**ANS:** use safe functions, like fgets, scanf.

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
     **ANS:** the loop runs 201 time, thus overflowing array variable. this is called off-by-one error. the 1 byte overflow corrupts the variable `x` in such a way that at the end of the loop, the value of the variable becomes less than 200, thereby making the loop condition failed. 
 
7. What is control hijacking in the context of exploitation? Exaplain one possible way to hijack control in the presence of stack overflow bug?
	**ANS:** see slides

8. Dr. Blahbah claims that buffer overflow attacks via stack smashing are made possible by the fact that stacks grow downwards (to-wards smaller addresses) on most popular modern architectures. Therefore, future architectures should ensure that the stack grows upwards; this would provide a good defense against buffer over-flow. Do you agree or disagree? Why?
	**ANS:** disagree. changing the direction of stack  will only affect which memory locations can be corrupted, but the bug still remains there. it will cause attackers to develop the exploit in a different way. 

9. What is a integer truncation error? Can you provide an example of buggy code where an integer overflow can cause overflow memory corruption? See, for example [this](http://phrack.org/issues/60/10.html)
	**ANS:** see slides. there are couple of examples in the above article. 

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
	**ANS:** len1= 4,294,967,200, len2=100. see slides and article for more info.  
	
11. What is a format string bug? Exaplain by example which of the CIA properties can be violated by a format string bug.
	**ANS:** see slides. information disclosure is the major concern for format string bugs. thus confidetiality is breached. Also, %n causes overwriting a memory location, leading to integrity violation.