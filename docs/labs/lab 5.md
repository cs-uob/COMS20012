# Lab 5: Memory Layout and Assembly Refresher

In this lab, you will be introduced to Assembly and memory layout using GDB. You will need this unerstanding for the coming labs and also to better comprehend the coming lectures.


## 1. Setting up Vagrant 

The rest of labs in this course are designed to run in *virtual machines* on the lab machines setup via Vagrant. Expect to spend the first 10 minutes
of any lab redownloading the VM images. If you have an X86-based Linux machine of your own, you might get away with using your own machine; if you have a Mac you will need to use the lab machines. If you have Windows you *might* get away with it.


1. On your host machine, open a terminal in you home directory (or whatever directory you are asigned which has good memory). Make a directory `mkdir CS_vagrant`
2. `cd CS_vagrant` and then make another directory `mkdir seclabs`
3. `cd seclabs`
4. `vagrant init hashicorp/bionic64`.
5. `vagrant up`. First time, this is will download Ubunut 18.04-64. It will take a while. Once done, we are ready to launch this VM.
6. Lets ssh our new VM. `vagrant ssh`
7. You are in your new VM. This VM shares a folder from your host machine, which is the same folder from where you lanched your VM, i.e. `seclab`. This folder is mapped to `/vagrant` in you VM. if you do `cd /vagrant`, you can see the content of your host folder. We will use this folder for all our work (i.e. you can copy your files in seclab folder and access tem from /vagrant folder from VM).
8. This VM is running a fresh Ubuntu. So, we need to get few things installed in this. Lets do it. Run these commands.
9. `sudo apt update`
10. `sudo apt install build-essential` This will install gcc.
11. `sudo apt install gdb` This will install GDB.
12. We will also use (occasionally) x86-32 bit compiled code. Lets setup this so that we can compile and run x86-32 applications. Run these commands.
13. `sudo dpkg --add-architecture i386`
14. `sudo apt-get install libc6:i386 libncurses5:i386 libstdc++6:i386`
15. `sudo apt-get install multiarch-support`
16. `sudo apt-get install gcc-multilib`
17. Now you have all the tools that will be required. To test, run these commends and check if they run properly-- `gcc --version`, `gdb --version`, `objdump --version`
18. When done with your lab, you can `logout` and then in your host machine, you can close the VM-- `vagrant halt`


## Understanding Memory layout with GDB
### Part 1. Using GDB 

1.	Compile the following c prog [call-convention.c](https://github.com/cs-uob/COMS20012/blob/master/docs/code/call-convention.c) by running 
```gcc -o call-conv64 call-convention.c```
Check what ```gcc -g -o call-conv64 call-convention.c``` did? Comment on your findings.
 2. Objdump: As part of the compilation process, compile (GCC) converts the source code into the assembly instruction and then the assembler takes in assembly instructions and encodes them into the binary form understood by the hardware. Disassembly is the reverse process that converts binary-encoded instructions back into human-readable assembly. objdump is a tool that operates on object files (i.e. files containing compiled machine code).
- A. Run ```objdump --help``` to see all the avaialble options.
- B. Run the objdump as follows and then scroll upto the point when you see main.
`objdump -d call-conv64`
This extracts the instructions from the object file and outputs the sequence of binary-encoded machine instructions alongside the assembly equivalent. 
If the object file was compiled with debugging information, adding the `-S` flag to objdump will intersperse the original C source. 
Run `objdump -d -S call-conv64` to see the source code together with the assembly.
3. GDB:
GDB stands for GNU Project Debugger and is a powerful debugging tool for C(along with other languages like C++). It helps you to monitor C programs while they are executing and also allows you to see what exactly happens when your program crashes. You can get the values of the registers and memory (e.g. stack). It allows you to set breakpoints at a certain point in your program execution. Though GDB is a commandline based program, you can, however, invoke its TUI (text user interface) to have separate windows displaying the values of registers, for example.
- A. Run the GDB with the following command.
You need to first run the program call-conv64
then you run
``` gdb call-conv64```
- B. This will take you to the gdb command promt (see the Fig. 2). In that command prompt, type [For intel syntax type ```set disassembly-flavor intel```]

```layout regs```

```focus cmd```

```b main```

```run```

```disassemble main```

- C. At this stage, all the panes will have some values. The top most pane gives you values to all the register. The middle pane shows the assembly code being executed. And the botton pane is for the GDB commandline. You can note the value of `RIP` and the address of the current highlighted line! In the pane C, each line starts with anl address, followed by the relative position marker and the instruction.
- D. The execution will halt at the entry of main function, bacause you set a breakpoint at the `main` (`b main`). Breakpoints can be set either by using the `b *address` OR `b *main+N`. Breakpoints are very useful when you want to analyse the values of register and memory.
Try setting a breakpoint at some later point, say `b *main+60` and then run.
- E. The program will halt when it reaches main+60. Now you can read the value of register, either by looking in the Pane R or by typing GDB command: `info reg`
- F. You can also read the memory content by
```x/8xb $rbp-0x4``` (remember, rbp is the base point, which also points to the stack. In this case you will read 8 bytes starting from EBP-4. If you want to read entire stack, you can also use RSP. Use ni and si commands to observe how GDB executes next instruction. 
- Try and get youself familiar with GDB (see the attached [GDB cheatsheet](https://github.com/cs-uob/COMS20012/blob/master/docs/materials/lecture1/GDBCheatSheet.pdf))!
#### Exercise:
Compile the given c code (call-convention.c) with the following commands. [Note: see the appendix A to make sure that your multi-arch compilation support is made available!] 
1. ```gcc -m32 -o call-conv32 call-convention.c```
2. ```gcc -o call-conv64 call-convention.c```
- The above two steps will create two binary files, viz. call-conv32 and call-conv64. Check they exist by using the right command.
3. Open `call-conv32 with objdump`
4. Look out for the disassembly of main
5. Observe the parameter passing just before the call <func>
6. Look out for the disassembly of func
7. Observe how those parameters (arguments) are used.
 

Repeat the above steps for call-conv64.
1. Open call-conv64 with objdump 
2. Look out for the disassembly of main
3. Observe the parameter passing just before the call <func>
4. Look out for the disassembly of func
5. Observe how those parameters (arguments) are used.
  
## Part 2. Understanding Memory layout with GDB
1. Copy c code [memory_layout.c](https://github.com/cs-uob/COMS20012/blob/master/docs/code/memory_layout.c)) in your seclab directory (so that it is accessible in /vagrant directory of your VM).
2. run `vagrant up` to start you VM.Do not forget to ssh your VM.
3. compile `gcc memory_layout.c -o memory_layout`
4. run the resulting binary. It will halt with a message "Press any key...."
5. On a different terminal (lets call it TermB, and the already runing terminal as TermA), run `ps -e |grep memory_layout`. Note the PID (PID is the process ID that is returned from the command).
6. On TermB, run `gdb -p PID`. GDB will be attached to the running process on TermA. You will be in GDB shell. Now on enter commands within gdb shell. NOTE: if GDB does not attach, run: `echo 0 | sudo tee /proc/sys/kernel/yama/ptrace_scope`
```
(gdb) disassem main
(gdb) b *main+N \\(instruction where it is going to call func1, use N as per your runtime, which should be around 412)
(gdb) disassem func1
(gdb) b *func1+N \\(instruction after the last call to printf, use N as per your runtime, which should be around 118)

(gdb) disassem func2
(gdb) b *func2+N \\(instruction where it is going to call func3, use N as per your runtime, which should be around 166)

(gdb) disassem func3
(gdb) b *func3+N \\(instruction after the last call to printf, use N as per your runtime, which should be around 279)
(gdb) c  
```
7. On Term A, press Enter to continue. The prog prints frame address of main. how will you find that address in the gdb window?
8. When in func1, it prints return address. Can you check which instruction address in that in the main (`disassem main`)?
9. On each breakpoint, verify the frame addresses of the functions as you did above.
10. At one point, you will see "Frame addr of caller of func2 (1)". Can you find which function we are talking about as a caller to func2?
11. In the end (your last "continue" on the GDB), you will see  
```
ADDRESS1: 0x5646d1cf5989
ADDRESS2: 0x5646d1cf5b39
```
Can you identify where are these intructions? [Hints: look for disassemblies of functions called before.].

  ##	Assembly Refresher
### Part 1. Getting familiar with Assembly
  
### Hello World

 Create a text file called `hello64.S` and write the following:

``` asm
; hello64.S: a first step into assembly programming!
global _start

  section .text

  _start:
          mov rax, 1
          mov rdi, 1
          mov rsi, msg
          mov rdx, len
          syscall

          mov rax, 60
          mov rdi, 0
          syscall

  section .rodata
  msg: db "Hello, World!", 10
  len: equ $ - msg
```

Compile, link and run it as follows:

``` shell
nasm -f elf64 -o hello64.o hello64.S
ld -o hello64 hello64.o
./hello64
```

#### Question 1

Comment every line of `hello64.S` and describe what each line does.
Focus on the *indented lines* to begin with.

- What is a `syscall`?
- What is `mov`?
- What are all those magic numbers?
- What is `rax`, `rdi`, `rsi` and `rdx` and why are things being moved
  into them?

To help you, you need to refer to the following bits of documentation:

- `man 2 intro` and `man 2 write`
- [The Intel 64 and IA-32 Architectures Software Developer's Manual:
  Volume
  2](https://www.intel.com/content/www/us/en/architecture-and-technology/64-ia-32-architectures-software-developer-instruction-set-reference-manual-325383.html)
- `/usr/src/linux-headers-4.19.0-21-amd64/arch/x86/include/generated/uapi/asm/unistd_64.h`

#### Question 2

Disassemble the binary you just made with:

``` shell
objdump -d hello64
```

Look at the output of the command. How does it relate to the code you
just wrote? What about if you run:

``` shell
objdump -D hello64
```

#### NOTE

As you're hopefully discovering there are multiple syntaxes for assembly
programming. The GNU tools use by default the AT&T syntax; NASM uses Intel. You need to be able to read
both. If it bothers you that much, try running:

``` shell
objdump -Mintel -d hello64
```

Similar options are available for GDB and all the other tools you'll
ever meet. If in doubt, use the `man` command.

### Hello World 32bit

Assembly programs are not portable between different operating systems, different computer
architectures, and even different versions of the same OS on the
same computer! The `hello64` program we wrote was for 64-bit Linux, but
we can also run 32-bit Linux programs on a 64-bit system! Let rewrite
the same *hello world* program for 32-bit Linux! Save the following into
`hello32.S`:

``` asm
; hello64.S: a first step into assembly programming!
global _start

  section .text

  _start:
          mov eax, 4
          mov ebx, 1
          mov ecx, msg
          mov edx, len
          int 0x80

          mov eax, 1
          mov ebx, 0
          int 0x80

  section .rodata
  msg: db "Hello, World!", 10
  len: equ $ - msg
```

Then compile, link, run and disassemble with:

``` shell
nasm -f elf32 -o hello32.o hello32.S
ld -melf_i386 -o hello32 hello32.o
./hello32
objdump -d hello32
```

#### Question 3

What has changed and why? What is the calling convention for a 32bit
Linux system call compared to a 64bit Linux System call?


 # Optional Part: (if you are done quickly with the previous parts, you can try to do the rest)
 
### Hello World C

We can compile and decompile a program now and we can see that the
system call convention changes between systems. What does this look like
in C? That should compile to much the same code right? Let try, save the
following as `hello.c`:

``` c
#include <stdio.h>

int main(void) {
  printf("Hello World!\n");
  return 0;
}
```

Compile the program and lets look at the disassembly:

``` shell
cc -o hello-c hello.c
objdump -d hello-c
```

 If you look at the disassembly of the `main` function you should
see that it is calling `puts`. If you look at `man 3` puts or recall
your C programming days, you'll see thats the function used to print
strings… so that makes sense.

Lets see what systemcalls the program makes with the `strace` command

``` shell
strace ./hello-c
```

Check that the `write` system call still happens as you expect.

#### Question 4

Lets look at the library call to `puts` in the `main` function. You'll
notice that C functions use a completely different calling convention!
Go look up what it is for 64bit Linux and make a note of it.

Recompile the C hello world for 32bit Linux: what's the calling
convention now?

``` shell
cc -m32 -o hello-c-32.o hello-c
objdump -d hello-c-32.o
```

Windows has 4 different calling conventions for C functions in x86!
Google what they are and what the ones commonly used for 64bit systems
are (they simplified it a bit). Make a note of them! This is going to
turn up again and again…

### Translating between C and Assembly

So far we've been just looking at Hello World. Lets try looking at
something a little more complicated! Here's a simple C program:

``` c
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool check_password(char *password) {
  char buffer[15];
  char solution[15] = "DPNTN115:JTGVO"; 
  int result;

  strncpy(buffer, password, 14);
  for (size_t i = 0; i < 14; i++)
    buffer[i] += 1;
  result = strncmp(buffer, solution, 14);

  return result? false : true;
}

int main(int argc, char *argv[]) {
  if (argc > 1)
    printf("You %s!\n", check_password(argv[1])? "win" : "lose");
  return 0;
}
```

Compile it and disassemble as normal; but you might want to pipe the
output to `less` this time so you can scroll.

``` shell
make translate-me
objdump -d translate-me | less
```

This time our program has variables, but in assembly languages we don't
(typically) have variables, instead we have space on the stack and CPU
registers for holding values we're immediately working on.

Instead of struggling on with `objdump` lets try using something a bit
easier! The [Godbolt Compiler Explorer](https://godbolt.org) lets
you see what C code compiles into and will show you which lines of C
produced which bits of assembly. Try compiling with x86-64 GCC and with
no extra flags. Coloured blocks in the C code on the left, correspond to
the same coloured lines of assembly on the right (there are colorblind
settings under *More* then *Settings* if that is helpful).

The first line of the `check_password` function starts by creating
enough room on the stack for all the variables in the function, and the
last line of the function returns the result.

When a register (i.e. `rbp`) contains a *pointer* then `[rbp]`
dereferences it (i.e. `*ptr` in C), and `[rbp+1]` dereferences it with
an offset (i.e. `ptr[1]`. Stare at the code and try and read it. Check
that it roughly makes sense and that you can follow it!

 Try and work line by line and check your understanding. You
*do not* need to understand *everything*, but you need to have a high
level gist of what is going on, even if that is just at the level of
*"it's doing something with whatever is in that pointer then calling
`strcmp` with these arguments"*. 

#### Question 5

Okay lets test what you read.

1.  How many bytes are allocated on the stack in `check_password` to
    hold all the variables?
2.  What do `rbp` and `rsp` point to? Which is bigger and which is
    smaller?
3.  Those are some big scary numbers in your disassembly! What are they?
    (Hint go look at an ASCII table).
4.  What is the address of the `char buffer[]` relative to the base
    pointer in `check_password`?
5.  What is the address of the `char solution[]` relative to the base
    pointer in `check_password`?
6.  What is the address of `argc` in `main`?
7.  Where does `argv` point to initially and why does it add 8 to it
    instead of 1 in `main`?
8.  What is the password?

### Assembly Comprehension

Let us move away from reading real programs and try and figure out
what little snippets of code do.

#### Question 6

What does this snippet of code do?

``` asm
xor      eax,eax
lea      rbx,[0]
loop     $
mov      rdx,0
and      esi,0
sub      edi,edi
push     0
pop      rbp
```

You might need to look things up in [The Intel 64 and IA-32
Architectures Software Developer's Manual: Volume
2](https://www.intel.com/content/www/us/en/architecture-and-technology/64-ia-32-architectures-software-developer-instruction-set-reference-manual-325383.html)
if you aren't familiar with an operation.

#### Question 7

What about this snippet?

``` asm
.loop:
            xadd rax, rdx
            loop .loop
```

Hint  
Try writing a program using these instructions (look up inline assembly
in C). Good initial values for `rax` and `rdx` might be to set them to
`1` and to see what happens as `rcx` is 1, 2, 3, 4 or 5!

### Writing code

Enough reading: lets try and write something!

#### Question 8

Look up the `execve` system call (`man 2 execve`). Write a program in
assembly language that uses `execve` to run the following shell command:

    wc -w /usr/share/dict/words


