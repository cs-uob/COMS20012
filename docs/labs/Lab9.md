# Lab 7: Introduction to Operating Systems (OS/161 as case study)

In this lab, you will get familiar with processes and memory management in Linux.

**Remote Access:** If you cannot run the lab on your local machine, you may want to use the Linux
Lab Machine remotely. To do so follow [the online instructions](https://uob.sharepoint.com/sites/itservices/SitePages/fits-engineering-linux-x2go.aspx).
If you experience difficulty contact the IT service.

                                                                
 ## 1. Setting up Vagrant (you have already done this part in previous labs, it should be straightforward)

The rest of labs in this course are designed to run in *virtual machines* on the lab machines setup via Vagrant. Expect to spend the first 10 minutes
of any lab redownloading the VM images. If you have an X86-based Linux machine of your own, you might get away with using your own machine; if you have a Mac you will need to use the lab machines. If you have Windows you *might* get away with it.


1. On your host machine, open a terminal in you home directory (or whatever directory you are asigned which has good memory). Make a directory `mkdir CS_vagrant`
2. `cd CS_vagrant` and then make another directory `mkdir seclabs`
3. `cd seclabs`
4. `vagrant init hashicorp/bionic64`.
5. `vagrant up`. First time, this is will download Ubunut 18.04-64. It will take a while. Once done, we are ready to launch this VM.
6. Lets ssh our new VM. `vagrant ssh`


## Part 1: Processes

run ps, comment on what you see

Now run memory_layout program, steps are as follows:

Copy c code mem.c in your seclab directory (so that it is accessible in /vagrant directory of your VM).

compile gcc mem.c -o mem
run the resulting binary
On a different terminal (lets call it TermB, and the already runing terminal as TermA), run ps. What do you see ? can you see your program in the processes list ?


Refer to ps manual (run man ps) and find out the option you need to use to list all processes that are running. Make sure you find mem in the list.

Questions:
Refering to ps manual, answer the following questions:

1/ How can you get details of all the running processes?
2/ Which order are the above processes sorted by? Can you sort them using same criteria but opposite order?

3/ You can sort processes using other criteria, try ps --sort=-%cpu -au to sort them by CPU usage order.
Find out how to sort processes based on memory usage.


You can also use ps to to find unique users:
 Run ps -eo user --no-header | sort -u.

You can find number of processes per user.

Run ps -eo user --no-header | sort | uniq -c.



Questions:

4/ Find PID for the process "mem", run ps PID
5/ You should now find the process parent:
  Run ps -o ppid= -p PID. If the child has PID 1234, run ps -o ppid= -p 1234.
Find another way to figure out the process parent. check man ps. Hint: you will be able to visualise all processes parents.

Use -o to output PID, PPID:
 Run ps -o pid,ppid. 

6/ Based on the above check the parent of "mem" using three different methods.


7/ Find running time to "mem"

Hint: For running time of single process (suppose PID is 1) run ps -p -1 -o etime. 


You can Sort processes in decreasing order of running time:

Run  ps -eo user --sort=-etime -e

8/ Now sort processes in increasing order of running time.

9/ Use watch utility to perform real-time monitoring over ps.

Run watch -n 1 'ps -eo pid,ppid,cmd,%mem,%cpu --sort=-%mem | head'. -n 1 specifies the refresh rate to be 1 second.

10/ Change the monitoring period of watch




 






