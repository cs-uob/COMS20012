# Lab 2: Software Vulnerabilities

**Remote Access:** If you cannot run the lab on your local machine, you may want to use the Linux
Lab Machine remotely. To do so follow [the online instructions](https://uob.sharepoint.com/sites/itservices/SitePages/fits-engineering-linux-x2go.aspx).
If you experience difficulty contact IT service.


**Tips:** As you use ssh to login to your VM, you are able to use only one terminal at a time. In order to get another terminal, you need to login to VM in a separate ssh sesssion. You can use another utility that allows you to get another terminal with the same ssh session. Use the command `tmux`. You will see a status bar at the bottom which tells that tmux is running. Now you press `ctrl + b` followed by `%`. you will see your terminal is devided  into two panes. You can use `ctrl + b` followed by right/left arrows to nevigate between the panes. See [this](https://tmuxcheatsheet.com/) for more tmux commands.

## A. Format String Error

**Descritpion:** The code [format.c](../code/format.c) contains a format string bug when it calls `printf(welcome)`  at line 30. It then asks to enter a pin (line 31-32). If pin equals a number (in this example, we simply simulated a secret pin by calling rand() to generate a random number), you are authenticated properly. The secret pin is read in `spin` variable, which is on the stack. You job is to get this pin by using the format string bug. Steps to follow:
1. Start you VM (same vagrant steps, but you don't have to install the VM. Just go to the directory where your Vagrantfile is and `vagrant up` followed by `vagrant ssh`. )
2. `cd /vagrant`. Use `tmux` and split the terminal. 
3. In one pane, compile the program `gcc format.c -o format`
4. run the program `./format`
5. it will ask to enter your name. Use %x-%x-%x ..........as name. 
6. For each additional %x, you will see some hexadecimal number being printed. You need to try each of these additional hexadecimal to see if this is the pin that will "authenticate" you. Note: the numbers are printed in hex, but you need to enter pin in decimal. In order to convert the hex to decimal, use `echo $((0xhex_num))` on the other pane. 

##B. Stack Buffer Overflow

**Description:** The code [bof-admin.c](../code/bof-admin.c) containts a stack buffer overflow in the foo() function, which accepts a string as parameter and then calls `strcpy` to copy that parameter inot a local buffer of fixed length. This code also has admin() function which is supposed to be accessed by admin staff if they know a PIN. Obviously, as a normal user, you do not know the admin PIN, but you want to still access admin related code. **So, you mission is to exploit the buffer overflow bug to execute admin() function!** 
Few tips/steps are as follow:

1. Compile the code as follows

		$ gcc -fno-stack-protector bof-admin.c -o bof
	Note: you can also add option `-ggdb` to make easier to work with gdb.
		
2. Switch off ASLR (we will lear about later in the course) by running the following command:

		$ echo 0 | sudo tee /proc/sys/kernel/randomize_va_space

3. Enable GDB to attach to a running process:
		
		$ echo 0 | sudo tee /proc/sys/kernel/yama/ptrace_scope
		
		
4. In this example, buffer overflow happens when you supply a long input argument which is passed directly to the foo(). Read the comments in the source code of [bof-admin.c](../code/bof-admin.c) to have ideas about how to do this.
5. Use `tmux` to have a two-pane terminal to make your life easier.
6. Run the binary `bof` with a long input (as suggested in the source code).
7. On the second pane, attach GDB to the running process (follow what you did in the 1st lab).
8. Use disas admin to know the entry address of this function.
9. initially, when you let your binary to run till the end (b continuing in GDB), it will crash and you will see a message in the GDB like bellow:
	
		Program received signal SIGSEGV, Segmentation fault.
		0x000055555555477a in foo ()

10. This happens because you overflowed the return address and now it is trying to access a memory which is invalid. Now you need to know which of your input bytes really oveflowed the return address. How will you do that? **\[Hint\]**: Look at the content of `rsp` register (this is what is moved into the rip register on return).
11. Now you know two most crucial information. Address of the admin() function and overflowing input bytes. Form you final input as described in the source code. On success, your program should print

		**** Welcome to Admin console ****
		
