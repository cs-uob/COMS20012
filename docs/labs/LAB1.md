# Lab 1: Understanding Assembly Code

**Remote Access:** If you cannot run the lab on your local machine, you may want to use the Linux
Lab Machine remotely. To do so follow [the online instructions](https://uob.sharepoint.com/sites/itservices/SitePages/fits-engineering-linux-x2go.aspx).
If you experience difficulty contact IT service.

## 1. Setting up Vagrant
As you will be using Vagrant for you VM management though out your unit, lets learn how to setup a VM with Vagrant. \[We assume that Vagrant and VirtualBox VVM is already installed on your host machine. If not, contact IT.\]
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

## 2. Understanding Memory layout with GDB

In this part of the lab, we will learn about using GDB to understand the few artifacts of x86 ISA.
0. Do some hands-on by following this documents first [lab1-gdb.pdf](../materials/lecture1/lab1-gdb.pdf). You will need [call-convention.c](../code/call-convention.c) and [GDB cheat sheet](../materials/lecture1/GDBCheatSheet.pdf)
1. Copy c code [memory_layout.c](../code/memory_layout.c) in your seclab directory (so that it is accessible in /vagrant directory of your VM).
2. \[run `vagrant up` to start you VM.\]
3. compile `gcc memory_layout.c -o memory_layout`
4. run the resulting binary. It will halp with a message "Press any key...."
5. On a different terminal (lets call it TermB, and the already runing terminal as TermA), run `ps -e |grep memory_layout`. Note the PID, say P.
6. On TermB, run `gdb -p P`. GDB will be attached to the running process on TermA. You will be in GDB shell. Now on enter commands within gdb shell.  

```
(gdb) disassem main
(gdb) b *main+N \\(instruction where it is going to call func1, use N as per your runtime, which should be 412)
(gdb) disassem func1
(gdb) b *func1+N \\(instruction after the last call to printf, use N as per your runtime, which should be 118)

(gdb) disassem func2
(gdb) b *func2+166 \\(instruction where it is going to call func3, use N as per your runtime, which should be 166)

(gdb) disassem func3
(gdb) b *func3+N \\(instruction after the last call to printf, use N as per your runtime, which should be 279)
(gdb) c  
```

7. On Term A, press Enter to continue. The prog prints frame address of main. how will you find that address in the gdb window?
8. When in func1, it prints return address. Can you check which instruction address in that in the main (disassem main)?
9. On each breakpoint, verify the frame addresses of the functions as you did above.
10. At one point, you will see "Frame addr of caller of func2 (1)". Can you find which function we are talking about as a caller to func2?
11. In the end (your last "continue" on the GDB), you will see  

```
ADDRESS1: 0x5646d1cf5989
ADDRESS2: 0x5646d1cf5b39
```

Can you identify where are these intructions? [Hints: look for disassemblies of functions called before.].

## 3. Crackme
This is a typical reverse engineering task.

Run the given binary [crackme](../code/crackme) in your VM. At one point, it will ask for the key that you (hypothetically) got when you purchased this application. You task is to analyze the binary and find the key.
Help: Use breakpoints at main and then after few calls away. use GDB stepi (si) and nexti (ni) command to run the application step-by-step.
	si- executes 1 instruction at a time.
	ni- executes 1 instruction at a time, but it pass over any call instruction (which means it 	does not follow the called function).
	x/8xw(or b, g) $rbp-x
	watch out *calls*!
Use these two step over functions wisely!!
