# Lab 2: Software Vulnerabilities

**Remote Access:** If you cannot run the lab on your local machine, you may want to use the Linux
Lab Machines remotely. To do so follow [the online instructions](https://uob.sharepoint.com/sites/itservices/SitePages/fits-engineering-linux-x2go.aspx){:target="_blank"}.

If you experience any difficulties contact IT services.

## A. Format String Error

**Description:** The code [format.c](../code/format.c){:target="_blank"} contains a format string bug when it calls `printf(welcome)` at line 30. It then asks to enter a pin (line 31-32). If the entered pin equals a randomly generated number (created by calling `rand()`), you are authenticated properly. The secret pin is stored in the `spin` variable, which is on the stack. Your job is to get this pin by using the format string bug. Steps to follow:
1. Start your VM (same vagrant steps, but you don't have to install the VM. Just go to the directory where your Vagrantfile is and `vagrant up` followed by `vagrant ssh`. )
2. `cd /vagrant`. Use `tmux` and split the terminal, you can do this by first running `tmux` and then pressing `Ctrl+B` followed by `%` (i.e., not at the same time), you navigate between the terminals (or 'panes') with `Ctrl+B` and then the left or right key. See [this](https://tmuxcheatsheet.com/){:target="_blank"} for more tmux commands. It is also possible to use `vagrant ssh` in another video as in the previous lab.
3. In one pane, compile the program `gcc format.c -o format`
4. Run the program `./format`
5. It will ask to enter your name. Use `%x-%x-%x ...` as your name.
6. For each additional `%x`, you will see some hexadecimal number being printed. You need to try each of these additional numbers to see if this is the pin that will "authenticate" you. 

Note: the numbers are printed in hex, but you need to enter pin in decimal. In order to convert the hex to decimal, use `echo $((0xhex_num))` on the other pane.

## B. Stack Buffer Overflow

**Description:** The code [bof-admin.c](../code/bof-admin.c){:target="_blank"} contains a stack buffer overflow in the `foo()` function, which accepts a string as a parameter and then calls `strcpy` to copy that parameter into a local buffer of fixed length. This code also has an `admin()` function which is supposed to be accessed by admin staff if they know a PIN. Obviously, as a normal user, you do not know the admin PIN, but you still want to access the admin related code. **So, your mission is to exploit the buffer overflow bug to execute the `admin()` function!**
A few tips/steps are as follows:

1. Compile the code as follows

		$ gcc -fno-stack-protector bof-admin.c -o bof
	Note: you can also add option `-ggdb` to make easier to work with gdb.

2. Switch off ASLR (we will learn about this later in the course) by running the following command:

		$ echo 0 | sudo tee /proc/sys/kernel/randomize_va_space

3. Enable GDB to attach to a running process:

		$ echo 0 | sudo tee /proc/sys/kernel/yama/ptrace_scope


4. In this example, the buffer overflow happens when you supply a long input argument which is passed directly to `foo()`. Read the comments in the source code of [bof-admin.c](../code/bof-admin.c){:target="_blank"} to get some clues on this.
5. Use `tmux` to have a two-pane terminal to make your life easier.
6. Run the binary `bof` with a long input (as suggested in the source code).
7. On the second pane, attach GDB to the running process (follow what you did in the first lab).
8. Use `disas admin` to get the entry address of the admin function.
9. Initially, when you let your binary to run until the end (by continuing in GDB), it will crash and you will see a message in GDB like bellow:

		Program received signal SIGSEGV, Segmentation fault.
		0x000055555555477a in foo ()

10. This happens because you overflowed the return address and the program is now trying to access memory which is invalid. Now you need to know which of your input bytes really oveflowed the return address. How will you do that? **\[Hint\]**: Look at the content of `rsp` register (this is what is moved into the rip register on return).
11. Now you know the two most crucial pieces of information. The address of the admin() function and the length of the overflowing input bytes. Form your final input as described in the source code. On success, your program should print

		**** Welcome to Admin console ****
