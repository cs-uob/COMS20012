# Lab 6: Software Vulnerabilities

## Learning Outcomes: 
In this lab you will gain hands on experience on buffer overflow and format string vulnerabilities that we covered theoretically in the lecture "Introduction to Software Security". You will be able to exploit these vulnerabilities and exprience what you can do with them.

**Remote Access:** If you cannot run the lab on your local machine, you may want to use the Linux
Lab Machines remotely. To do so follow [the online instructions](https://uob.sharepoint.com/sites/itservices/SitePages/fits-engineering-linux-x2go.aspx).

If you experience any difficulties contact IT services.



## A. Format String Error

**Description:** The code [format.c](https://github.com/cs-uob/COMS20012/blob/master/docs/code/format.c) contains a format string bug when it calls `printf(welcome)` at line 30. It then asks to enter a pin (line 31-32). If the entered pin equals a randomly generated number (created by calling `rand()`), you are authenticated properly. The secret pin is stored in the `spin` variable, which is on the stack. Your job is to get this pin by using the format string bug. Steps to follow:
1. Start your VM (same vagrant steps, but you don't have to install the VM. Just go to the directory where your Vagrantfile is and `vagrant up` followed by `vagrant ssh`. )
2. In one pane, compile the program `gcc format.c -o format`
3. Run the program `./format`
4. It will ask to enter your name. Use `%x-%x-%x ...` as your name.
5. For each additional `%x`, you will see some hexadecimal number being printed. You need to try each of these additional numbers to see if this is the pin that will "authenticate" you. 

Note: the numbers are printed in hex, but you need to enter pin in decimal. In order to convert the hex to decimal, use `echo $((0xhex_num))` in another terminal. To do so, on a different terminal (lets call it TermB, and the already runing terminal as TermA), run `vagrant ssh`. Use this TermB to convert the number from hex to decimal.

## B. Stack Buffer Overflow

**Description:** The code [bof-admin.c](https://github.com/cs-uob/COMS20012/blob/master/docs/code/bof-admin.c) contains a stack buffer overflow in the `foo()` function, which accepts a string as a parameter and then calls `strcpy` to copy that parameter into a local buffer of fixed length. This code also has an `admin()` function which is supposed to be accessed by admin staff if they know a PIN. Obviously, as a normal user, you do not know the admin PIN, but you still want to access the admin related code. **So, your mission is to exploit the buffer overflow bug to execute the `admin()` function!**
A few tips/steps are as follows:

1. Compile the code as follows

		$ gcc -fno-stack-protector bof-admin.c -o bof
	Note: you can also add option `-ggdb` to make easier to work with gdb.

2. Switch off ASLR (we will learn about this later in the course) by running the following command:

		$ echo 0 | sudo tee /proc/sys/kernel/randomize_va_space

3. Enable GDB to attach to a running process:

		$ echo 0 | sudo tee /proc/sys/kernel/yama/ptrace_scope


4. In this example, the buffer overflow happens when you supply a long input argument which is passed directly to `foo()`. 
As you can see in the buffer size, if the input length is greater than buf (20), it will start overflowing the adjacent memory including the saved return address. You need to find how long the input string should be to precisely overwrite the 8 byte long saved return address. Then you need to find from which offset in the input, you start overflowing the return address. 

**Example** For example, if you use a long string such as AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA as the input, you need to find from which letter, you start overflow return address.  You need to find at which size you start to overflow the buffer. The you need to replace the extra part with the address of the admin() entry point. 

Let us now do this step by step:


5. Start another terminal and ssh Vagrant.

6. Run the binary `bof` with a long input (as suggested above in point 4.).

7. On the second pane (let us call it TerminalB), attach GDB to the running process (follow what you did in last week's lab).

 run `ps -e |grep bof`. Note the PID. The output will be similar to " 3006 pts/1    00:00:00 bof ". PID here is "30006"
 
 Then, run `gdb -p PID`. GDB will be attached to the running process on TerminalA. You will be in GDB shell. 

8. Use `disas admin` to get the entry address of the admin function.
9. You should run the binary by using long input. You can use `run $(perl -e 'print "A"xSize')` where **Size** is the size of the input of your choice. If you choose **Size** to be equal to 50, it will print "A" 50 times as input.
Initially, when you let your binary to run until the end (by continuing in GDB), it will crash and you will see a message in GDB like bellow:

		Program received signal SIGSEGV, Segmentation fault.
		0x000055555555477a in foo ()


This happens because you overflowed the return address and the program is now trying to access memory which is invalid. Now you need to know which of your input bytes really oveflowed the return address.

10. Now you need to change Size until you find where the binary runs normally without triggering a "Segmentation fault". Once you find the right value for Size, change the rest of input with the entry address of the admin function, let us call it Address.

You can use `run $(perl -e 'print "A"xSize, "Address"')`

**Example** Let's assume Address is 0x0000555555554858. 

Then you need to contruct the final input as `run $(perl -e 'print "A"xSize, "\x58\x48\x55\x55\x55\x55"')`. You can ignore the remaining zeros. Also notice that we used \x to so that these are not interpreted as ASCII symbols.


11. On success, your program should print

		**** Welcome to Admin console ****
