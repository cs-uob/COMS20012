# Lab 5: Introduction to OS/161

## Some notes

Please, make sure you understand what the commands you are using in this lab do.
The objective of this lab is to get you familiar with the development environment
that you will be using for the next three labs.

You should work setup groups of two students from within the groups that were setup at the beginning of the unit. Please,
for your own benefit do not simply copy solutions from other groups, but instead
understand what is going on. The labs are entirely formative this year, but it
remains important to understand their content and to develop the related skills.
Later in this lab, you will be asked to create a repository on github. This is
how you will share code with the lecturers, your TA and your colleagues. When
asking technical questions provide links to this repository, ideally pointing
to the relevant portion of code.

If you spot errors in the lab instructions, please, do drop an e-mail at
[thomas.pasquier@bristol.ac.uk](emailto:thomas.pasquier@bristol.ac.uk). We will
endeavor to fix any issue quickly.

Finally, make sure you do the **exercises** properly.

## Tools

You are second year computer science students and we expect some autonomy
in using the "tools of the trade".
You should be familiar (or familiarize yourself) with the following tools:
1. [Vagrant](https://learn.hashicorp.com/tutorials/vagrant/getting-started-index?in=vagrant/getting-started);
2. [VirtualBox](https://www.virtualbox.org/manual/ch01.html);
3. [git](https://git-scm.com/docs/gittutorial);
4. [GDB]().

Please, make sure those tools are installed and that you know how to use them.
You should have used them in previous labs in this unit, and others.
Do get in touch with your TA if you are facing issues.

## Setting up vagrant image

It is recommended to setup a virtual environment to go through the lab. To do
so, follow this instructions:
```
git clone https://github.com/tfjmp/vagrant-os161.git
cd vagrant-os161
vagrant up
```

## Getting the source

OS-161 has been developed and is maintained by [David Holland](http://www.hcs.harvard.edu/~dholland/) from [Harvard University](http://os161.eecs.harvard.edu/).
We sorted the dependencies you will need in git repositories.

First you need to `ssh` in your guest virtual machine:
```
vagrant ssh
```

Then you need to move to the `shared` folder which is synced with your host machine:
```
cd shared
```

Now all that is left for you to do is to access the OS-161 source code:
```
git clone https://github.com/tfjmp/os161.git
```

### Exercise

1. Delete this repository and create your own fork on github. You will need it
to track your changes and share your code with classmates and TA.

## Configure OS-161 source tree

This step is necessary to setup the location where your kernels and various
binaries will be created in later stages. It should run fairly quickly and need
to be done only once (or when you completely deleted your source tree).
Run `./configure --help` to fidn our more including available options.

## Building userland

**Note:** You may be familiar with GNU make. However, OS-161 uses BSD make which
has a different syntax. To avoid confusion, BSD make has been installed as `bmake`
on your lab VM.

You first need to build a bunch of userland dependencies:
```
bmake
bmake install
```

## Configuration OS-161 kernel

Now we need to configure the kernel. You can see the configurations in `kern/conf`.
We are going to use `LAB5` configuration:
```
cd kern/conf
./config LAB5
```

Have a look at the content of `LAB5` and `conf.kern`. In particular, `conf.kern`
determine what files get built. You may need to modify this in later assignments.

## Building OS-161 kernel

Once you have configured your source tree and your kernel.
You are ready to build the kenrel!

```
cd ../compile/LAB5
bmake depend
bmake
bmake install
```

## Running OS-161 kernel

Now that your kernel is built, we are going to run it. To do so we are going to
use [Sys-161](http://os161.eecs.harvard.edu/) maintained by
[David Holland](http://www.hcs.harvard.edu/~dholland/) from
[Harvard University](http://os161.eecs.harvard.edu/).
System-161 is a machine simulator that provides a simplified but still realistic
environment to run OS-161. Apart from floating point support and certain issues
relating to RAM cache management, it provides an accurate emulation of a
MIPS processor.

You need a [configuration file](./sys161.conf) that we are going to place in `~/os161/root/`:
```
cd ~/os161/root/
wget https://cs-uob.github.io/COMS20012/labs/sys161.conf
```

Have a look through this file, it should
be self explanatory if you ever have to modify it.

Now let's run our kernel:
```
sys161 kernel
```

What just happened? You ran one computer program (sys161) that loaded your
kernel (from the kernel) file. Your kernel is itself a program expressed as
a series of MIPS r3000 instructions, which were interpreted by sys161 and
simulated as if they had executed on real hardware. Of course, this includes
the ability read from and write to a console device, allowing you to
interact with your running kernel.

Your kernel should now be up and running! Play around a bit in the menu and see
what you can do. Once you are done, you can shut it down simply by typing
`exit`.

### Exercises

Examine the output produced by your kernel as it boots and shuts down.
You should be able to answer the following questions:
1. Which version of System/161 and OS/161 are you using?
2. Where was OS/161 developed and copyrighted?
3. How much memory and how many CPU cores was System/161 configured to use?
4. What configuration was used by your running kernel?
5. How many times has your kernel been compiled?

Now let's try to play with configuration:
1. Boot your OS/161 kernel with 8 cores.
2. Try booting with 256K of memory. What happens?
3. Configure System/161 to use a fixed value to initialize its random number
    generator. (This can be helpful when debugging non-deterministic
    kernel behavior.)

## Exploring OS-161

One of the challenges in this series of lab is working with a relatively large
and unfamiliar code base. Worry not, we are now going to try to understand it
a bit better.

OS-161 contains around 40,000 lines of codes, 25,000 lines of comments spread
across 570 C, headers and assembly files. It would take too much time to looks
through all of it let alone understand it.

Luckily, you do not need to understand most of the code. There is only a small
fraction that you need to be familiar with and an even smaller fraction that you
need to understand in details. Being able to distinguish between those categories
is a very important skills. It will serve you for the next few labs,
in [COMSM0049 in year 4](https://cs-uob.github.io/COMSM0049/) where you will
do some Linux kernel development, but maybe also in your future career.

To become familiar with a code base, there is no substitute for actually
poking around. Browse through the tree a bit to get a sense of how things are
structured. Glance through some source code for files that look interesting.
OS-161 is also very well commented, as befits a pedagogical code base.

Some parts of the code may seem confusing since we have not discussed how any
OS-161 subsystems work. However, it is still useful to review the code now and
get a high-level idea of what is happening in each subsystem. If you do not
understand the low-level details now, that is fine.

### The top of the source directory

Your OS/161 source directory contains the following files:
* `CHANGES`: describes the evolution of OS/161 and changes in previous versions.
* `configure`: the top-level configuration script that you ran previously.
* `Makefile`: the top-level Makefile used to build the user space binaries.

The source directory contains the following subdirectories:
* `common/`: code used both by the kernel and user programs, mostly standard C library functions.
* `design/`: contains design documents describing several OS/161 components.
* `kern/`: the kernel source code, and the subdirectory where you will spend most of your time.
* `man/`: the OS/161 man pages appear here. The man pages document (or specify) every program, every function in the C library, and every system call. You will use the system call man pages for reference in the course of [LAB6](./LAB6.html). The man pages are HTML and can be read with any browser.
* `mk/`: fragments of Makefiles used to build the system.
* `userland/`: user space libraries and program code.

If you have previously configured and built in this directory there are also some additional files and directories that have been created, such as `defs.mk` and `build/`.

### User Land

In the `userland/` source subdirectory, you will find:
* `bin/`: all the utilities that are typically found in `/bin/` such as `cat`, `cp`, `ls`, etc.
Programs in `/bin/` are considered fundamental utilities that the system needs to run.
* `include/`: these are the include files that you would typically find in /usr/include (in our case, a subset of them). These are user include files, not kernel include files.
* `lib/`: library code lives here. We have only two libraries: `libc`, the C standard library, and `hostcompat`, which is for recompiling OS/161 programs for the host UNIX system. There is also a `crt0` directory, which contains the startup code for user programs.
* `sbin/`: this is the source code for the utilities typically found in `/sbin` on a typical UNIX installation. In our case, there are some utilities that let you halt the machine, power it off, and reboot it, among other things.
* `testbin/`: you can ignore this subdirectory.

You don’t need to understand the files in `userland/bin/`, `userland/sbin/` now, but you certainly will later on. Eventually, you will want to modify these or write your own utilities and these are good models. Similarly, you need not read and understand everything in `userland/lib` and `userland/include` but you should know enough about what’s there to be able to get around the source tree easily.

### Kernel Sources

Now let’s navigate to the kern/ source subdirectory. Once again, there is a
Makefile. This Makefile installs header files but does not build anything.
In addition, we have more subdirectories for each component of the kernel as
well as some utility directories and configuration files.

#### kern/arch

## Acknowledgement

This lab was developed thanks to material available at [Harvard 0S/161](http://os161.eecs.harvard.edu/),
[ops-class](https://ops-class.org/) and [OS/161 at UBC](https://sites.google.com/site/os161ubc/home).
