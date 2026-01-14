# Lab 8: Processes and Memory Management


Please provide your feedback on the unit before starting the lab

Link to access the evaluation: https://evaluation.bristol.ac.uk/home/so-eng.html


In this lab, you will get familiar with processes and memory management in Linux.

**Remote Access:** If you cannot run the lab on your local machine, you may want to use the Linux
Lab Machine remotely. To do so follow [the online instructions](https://uob.sharepoint.com/sites/itservices/SitePages/fits-engineering-linux-x2go.aspx).
If you experience difficulty contact the IT service.

                                                                
 ## 1. Setting up Vagrant (you have already done this part in previous labs, it should be straightforward)

The rest of labs in this course are designed to run in *virtual machines* on the lab machines setup via Vagrant. Expect to spend the first 10 minutes
of any lab redownloading the VM images. If you have an X86-based Linux machine of your own, you might get away with using your own machine; if you have a Mac you will need to use the lab machines. If you have Windows you *might* get away with it.


1. On your host machine, open a terminal in your home directory (or whatever directory you are asigned which has good memory). Make a directory `mkdir CS_vagrant`
2. `cd CS_vagrant` and then make another directory `mkdir seclabs`
3. `cd seclabs`
4. `vagrant init hashicorp/bionic64`.
5. `vagrant up`. First time, this is will download Ubuntu 18.04-64. It will take a while. Once done, we are ready to launch this VM.
6. Lets ssh our new VM. `vagrant ssh`


## Part 1: Processes

In this part, you will manipulate processes and understand their interactions with OS.

Let us see some processes:

1. Run `ps`, comment on what you see. 

2. Now run a `memory_layout` program, steps are as follows:

Copy c code [memory_layout.c](https://github.com/cs-uob/COMS20012/blob/master/docs/code/memory_layout.c) into your seclab directory (so that it is accessible in /vagrant directory of your VM).

Compile the c prog and call it `mem` by running 
`gcc memory_layout.c -o mem`

Run the resulting binary

3. On a different terminal (lets call it TermB, and the already runing terminal as TermA), run `ps`. What do you see ? can you see your program in the processes list ?


4. Refer to ps manual (run `man ps`) and find out the option you need to use to list all processes that are running. Once you use the right option, you will be able to a process called "mem" in the list.

#### Questions:

Refering to the ps manual, answer the following questions:

- How can you get details of all the running processes?

- When you visualise the full list of processes with their details, Which order are the above processes sorted by? Can you sort them using same criteria but opposite order?

- You can sort processes using other criteria, try `ps --sort=-%cpu -au` to sort them by CPU usage order.
Find out how to sort processes based on memory usage.


5. You can also use ps to to find unique users:

 Run `ps -eo user --no-header | sort -u`.

6. You can find number of processes per user.

Run `ps -eo user --no-header | sort | uniq -c`.

7. Find PID for the process "mem", then run `ps -C mem`

8. You should now find the process parent:

  Run `ps -o ppid= -p PID`. Example: If the child has PID 1234, run `ps -o ppid= -p 1234`.

#### Questions:

- Find another way to figure out the process parent. Always check `man ps`. Hint: you will be able to visualise all processes parents.

- Use -o to output PID, PPID:

 Run `ps -o pid,ppid`. 

 Based on the above check the parent of "mem" using three different methods.


- Find running time to "mem"

Hint: For running time of single process (suppose PID is 1) run `ps -p 1 -o etime`. Apply the same approach to find the running time for "mem".



9. You can Sort processes in decreasing order of running time:

Run  `ps -eo pid,etime,cmd --sort=-etime -e`

#### Questions:

- Now sort processes in increasing order of running time.

10. Use watch utility to perform real-time monitoring over ps.

Run `watch -n 1 'ps -eo pid,ppid,cmd,%mem,%cpu --sort=-%mem | head'`. -n 1 specifies the refresh rate to be 1 second.


#### Questions:

- Change the monitoring period of watch.

## Part 2: Memory Management

1. The first Linux tool you should check out is the very simple tool free. First, type `man free` and read its entire manual page.

2. Now, run `free` , perhaps using some of the arguments that might be useful (e.g., -m, to display memory totals in megabytes). How much memory is in your system? How much is free? Do these numbers match your intuition?

3. Next, we'll create a little program that uses a certain amount of memory, called [memory-user.c](https://github.com/cs-uob/COMS20012/blob/master/docs/code/memory-user.c). This program can take one or two command line arguments: the number of megabytes of memory it will use and, optionally, the minimum number of seconds to run. When run, it should allocate an array, and constantly stream through the array, touching each entry. The program should do this indefinitely, or for a certain amount of time if specified at the command line.

4.  After compiling this program (`gcc memory-user.c -o memory-user`), just run with two arguments. The first argument is the number of MB to reserve and the second is the minimum number of seconds to run the program for. For example, if you use `./memory-user 100 30` 100 means that the program will be reserved 100MB of memory and will run for 30 seconds.

5. Now, while running your memory-user program, also (in a different terminal window, but on the same machine) run the "free" tool. Do not forget to choose a long running time so you can watch the "free" tool behaviour. You will need to Keep a watch on the memory using `watch -n 1 free -m` while running the program so you can see changes in memory usage. 

#### Questions:

- How do the memory usage totals change when your program is running? 
- How about when you kill the memory-user program? Do the numbers match your expectations? 
- Try this for different amounts of memory usage. What happens when you use really large amounts of memory?

6. Let us try one more tool, known as "pmap". Spend some time, and read the "pmap" manual page in detail.

7. To use pmap, you have to know the process ID of the process you are interested in. Thus, first run `ps auxw` to see a list of all processes; then, pick an interesting one, such as a browser. You can also use your memory-user program in this case (indeed, you can even have that program call getpid() and print out its PID for your convenience).

8. Now run pmap on some of these processes, using various flags (like -x or -X) to reveal many details about the process. What do you see? How many different entities make up a modern address space, as opposed to our simple conception of code/stack/heap?

9. Finally, let us run pmap on your "memory-user" program, with different amounts of used memory. What do you see here? Does the output from pmap match your expectations?

 






