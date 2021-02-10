# Exercises sheet W2

## Fill our survey

<iframe width="640px" height= "480px" src= "https://forms.office.com/Pages/ResponsePage.aspx?id=MH_ksn3NTkql2rGM8aQVG5N9pWWUNd5Khd6GR62JgsZURFFGVlRYNjFDTDVUWjlQUFpZNFJXVE9NMC4u&embed=true" frameborder= "0" marginwidth= "0" marginheight= "0" style= "border: none; max-width:100%; max-height:100vh" allowfullscreen webkitallowfullscreen mozallowfullscreen msallowfullscreen> </iframe>

## Questions

**There will be no written corrections. Exercises will be discussed during the recorded live Q&A. Come and prepare questions.**

1. Explain the difference between design flaw and programming error by giving one example.
2. What is a spatial memory safety violation?
3. Is buffer overflow error an example of *spatial* or *temporal* safety  violation? Explain your answer.
4. In the [article](http://www.pl-enthusiast.net/2014/07/21/memory-safety/)  by Prof. Hicks, he provides a definition of memory safety as *no accesses to undefined memory*. Later he argues that it does not cover buffer overflows. Can you explain why it is so?
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
     Compile the code with `gcc -m32 -fno-stack-protector loop.c -o loop32` and run it. On my machine, the code goes in an infinite loop. Can you find a probable cause for thiq?

7. What is control hijacking in the context of exploitation? Explain one possible way to hijack control in the presence of stack overflow bug?

8. Dr. Blahbah claims that buffer overflow attacks via stack smashing are made possible by the fact that stacks grow downwards (to-wards smaller addresses) on most popular modern architectures. Therefore, future architectures should ensure that the stack grows upwards; this would provide a good defense against buffer over-flow. Do you agree or disagree? Why?

9. What is a integer truncation error? Can you provide an example of buggy code where an integer overflow can cause overflow memory corruption? See, for example [this](http://phrack.org/issues/60/10.html)

10. Consider the following code:
```
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
```

As is discussed in this [article](http://phrack.org/issues/60/10.html), there is a integer overflow in the above code which will overflow `mybuf` at line [4] and/or [5]. The problem is at line [3]. what value to `len1` and `len2` you will use to trigger the bug?


11. What is a format string bug? Explain by example which of the CIA properties can be violated by a format string bug.
