# Lab 7: Introduction to Operating Systems (OS/161 as case study)

In this lab, you will get familiar with Operating Systems, explore OS/161 which an operating system made for teaching purposes. You will get to know how to configure and build operating systems.

You need to complete [LAB 5](https://github.com/cs-uob/COMS20012/blob/master/docs/labs/lab%205.md) in order to do this lab.

**Remote Access:** If you cannot run the lab on your local machine, you may want to use the Linux
Lab Machine remotely. To do so follow [the online instructions](https://uob.sharepoint.com/sites/itservices/SitePages/fits-engineering-linux-x2go.aspx).
If you experience difficulty contact the IT service.


## Tools

You are second year computer science students and we expect some autonomy
in using the "tools of the trade".
You should be familiar (or familiarise yourself) with the following tools:
1. [Vagrant](https://learn.hashicorp.com/tutorials/vagrant/getting-started-index?in=vagrant/getting-started);
2. [VirtualBox](https://www.virtualbox.org/manual/ch01.html);
3. [git](https://git-scm.com/docs/gittutorial);
4. GDB, see [LAB 5](https://github.com/cs-uob/COMS20012/blob/master/docs/labs/lab%205.md).
Please, make sure those tools are installed and that you know how to use them.
You should have used them in previous labs in this unit, and others.
Do get in touch with your TA if you are facing issues.

## Installation

 - (On Windows) Download https://git-scm.com/download/[Git for Windows].

This includes a `bash` shell which you should use in lieu of the terrible
Windows shell.

 - (Required) If you already have https://www.virtualbox.org/[VirtualBox]
installed, upgrade to the latest version.

 - (Required) https://docs.vagrantup.com/v2/installation/[Install Vagrant]

- (Suggested) Install two Vagrant plugins:

 `vagrant plugin install vagrant-vbguest`.

This ensure that your VirtualBox Guest Additions are up to date.

 `vagrant plugin install vagrant-timezone`.

This synchronizes time between your VM guest and host.

Note that these plugins may be required to get certain Windows systems to
work.

## Setting up vagrant image

It is *strongly recommended* to setup a virtual environment to go through the lab, and to use the lab machines for this one. To do
so, follow these instructions:
```
git clone https://github.com/uob-jh/vagrant-os161.git
cd vagrant-os161
vagrant up
vagrant reload
```
During these instructions you might encounter some errors and some failures to access security updates. Ignore these and as soon as its all finished do `vagrant ssh`. The process will also open another window titled: "OS-labs [Running]"; you can ignore this box. The work is done in the original CLI.
## Getting the source

[OS/161](http://os161.eecs.harvard.edu/) has been developed and is maintained by [David Holland](http://www.hcs.harvard.edu/~dholland/) from [Harvard University](http://os161.eecs.harvard.edu/).
It was spearheaded by [Margo Seltzer](https://www.seltzer.com/margo/) for use in her famous Harvard course on operating systems, CS161.
Since then, OS/161 has been adopted for teaching in many universities around the world.
Operating systems courses that use OS/161 are known to be demanding, yet incredibly enriching and rewarding.

We sorted the dependencies you will need in git repositories.
First you need to `ssh` in your guest virtual machine:
```
vagrant ssh
```
The default user and hostname is trinity@zion. 

Now all that is left for you to do is to access the OS/161 source code:
```
cd ~
git clone https://github.com/uob-jh/os161.git
```

## Configure OS/161 source tree

This step is necessary to setup the location where your kernels and various
binaries will be created in later stages. It should run fairly quickly and needs
to be done only once (or when you completely deleted your source tree).
Run `./configure --help` to find more including available options.

## Building userland

**Note:** You may be familiar with GNU make. However, OS/161 uses BSD make which
has a different syntax. To avoid confusion, BSD make has been installed as `bmake`
on your lab VM.

You first need to build a bunch of userland dependencies:
```
cd os161
bmake
bmake install
```

## Configuration OS/161 kernel

Now we need to configure the kernel. You can see the configurations in `kern/conf`.
We are going to use `LAB5` configuration:
```
cd kern/conf
./config LAB5
```

Have a look at the content of `LAB5` and `conf.kern`. In particular, `conf.kern`
determine what files get built. You may need to modify this in later assignments.

## Building OS/161 kernel

Once you have configured your source tree and your kernel.
You are ready to build the kernel!

```
cd ../compile/LAB5
bmake depend
bmake
bmake install
```

## Running OS/161 kernel

Now that your kernel is built, we are going to run it. To do so we are going to
use [Sys-161](http://os161.eecs.harvard.edu/).
System/161 is a machine simulator that provides a simplified but still realistic
environment to run OS/161. Apart from floating point support and certain issues
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
1. Boot your OS/161 kernel with a different number of cores (say... 4)
2. Try booting with 256K of memory. What happens?


## Exploring OS/161

One of the challenges in this series of lab is working with a relatively large
and unfamiliar code base. Worry not, we are now going to try to understand it
a bit better.

OS/161 contains around 40,000 lines of codes, 25,000 lines of comments spread
across 570 C, headers and assembly files. It would take too much time to looks
through all of it let alone understand it.

Luckily, you do not need to understand most of the code. There is only a small
fraction that you need to be familiar with and an even smaller fraction that you
need to understand in details. Being able to distinguish between those categories
is a very important skill.

To become familiar with a code base, there is no substitute for actually
poking around. Browse through the tree a bit to get a sense of how things are
structured. Glance through some source code for files that look interesting.
OS/161 is also very well commented, as befits a pedagogical code base.

Some parts of the code may seem confusing since we have not discussed how any
OS/161 subsystems work. However, it is still useful to review the code now and
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
* `man/`: the OS/161 man pages appear here. The man pages document (or specify) every program, every function in the C library, and every system call. You will use the system call man pages for reference in the course of [LAB 7](./LAB7.html). The man pages are HTML and can be read with any browser.
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

#### `kern/arch`

This is where architecture-specific code goes. By architecture-specific, we mean the code that differs depending on the hardware platform on which you’re running. There are two directories here: mips which contains code specific to the MIPS processor and sys161 which contains code specific to the System/161 simulator.

* `kern/arch/mips/conf/conf.arch`: this file tells the kernel configuration script where to find the machine-specific, low-level functions it needs (throughout `kern/arch/mips/`).
* `kern/arch/mips/include/`: this folder and its subdirectories include files for the machine-specific constants and functions.
* `kern/arch/mips/`: The other directories contain source files for the machine-dependent code that the kernel needs to run. Most of this code is quite low-level.
* `kern/arch/sys161/conf/conf.arch`: Similar to `mips/conf/conf.arch`.
* `kern/arch/sys161/include`: These files are include files for the System/161-specific hardware, constants, and functions.

#### `kern/compile/`

This is where you build kernels. In the compile directory, you will find one
subdirectory for each kernel configuration target you have used you want to
build. For example, if you configure your kernel with the LAB5, a LAB5
subdirectory will be created in `kern/compile` where you can compile your kernel.
This directory and build organization is typical of UNIX installations and
is not universal across all operating systems.

* `kern/conf/config`: is the script that takes a configuration file, like `GENERIC`, and creates the corresponding build directory.

#### `kern/test/`

This directory contains kernel tests that evaluate multiple parts of your system.

#### `kern/dev/`

This is where all the low level device management code is stored. Unless you
are really interested, you can safely ignore most of this directory.

#### `kern/include/`

These are the include files that the kernel needs. The kern subdirectory
contains include files that are visible not only to the operating system itself,
but also to user programs.

#### `kern/lib/`

These contain library code used throughout the kernel: `arrays`, `kernel printf`
, etc.

#### `kern/main/`

This is where the kernel is initialized and where the kernel main function and
menu are implemented.

#### `kern/thread/`

This directory contains the code implementing the thread abstraction and
synchronization primitives.

#### `kern/syscall/`

This is where you will add code to create and manage user level processes.
As it stands now, OS/161 runs only kernel threads—​there is no support for user
level code. (Try running the shell from the OS/161 menu and see what happens.)


#### `kern/vm/`

This directory is also fairly vacant at the moment.

#### `kern/vfs/`

The file system implementation has two directories which we will present in turn.
`kern/vfs` is the file system independent layer. `vfs` stands for virtual file
system. It establishes a framework into which you can add new file systems
easily. You will want to go look at `vfs.h` and `vnode.h` before looking at
this directory.

#### `kern/fs/``

This is where the actual file system implementations go. The subdirectory `sfs`
contains the implementation of the simple file system.

### Exercises

You may find standard UNIX utilities like `find` and `grep` useful when
searching through your OS/161 source code.

1. What function initializes the kernel during boot, and what subsystems are currently initialized?
2. OS/161 has a system for printing debugging messages to the console. How does it work? How could it be useful?
3. What do copyin and copyout do? What is special about these functions compared to other approaches to copying memory in C, like [memmove](http://www.cplusplus.com/reference/cstring/memmove/)?

## Using GDB

We are reaching the end of the lab. We are going to see how to use GDB to debug
our kernel. You should be familiar with GDB from [LAB 1](./LAB1.html).

First you need to boot your kernel and wait for a GDB connection:
```
cd ~/os161/root/
sys161 -w kernel
```

Now you need to open a second terminal (... and `vagrant ssh` in your guest)
and do the following:
```
cd ~/os161/root/
os161-gdb kernel
```

Now in the GDB prompt type the following:
```
target remote unix:.sockets/gdb
```

If you see the following error message:
```
Remote debugging using unix:.sockets/gdb
__start () at ../../arch/sys161/main/start.S:54
54      ../../arch/sys161/main/start.S: No such file or directory.
```
You can ignore it and continue.


On your first terminal you should see the following message:
```
sys161: New debugger connection
```

### Trying GDB

We are going to set our first breakpoint within the `gdb` prompt:
```
break kmain
```

You should see the following:
```
Breakpoint 1 at 0x8000d174: file ../../main/main.c, line 212.
```

Now enter the `c` and `s` commands. You should be stopped at the boot function:
```
(gdb) c
Continuing.

Breakpoint 1, kmain (arguments=0x8002aea0 "") at ../../main/main.c:212
212     {
(gdb) s
213             boot();
```

If you type `s` again, it should bring you to the first line of boot:
```
(gdb) s
boot () at ../../main/main.c:100
100             kprintf("\n");
```

You can step over this call with `n`:
```
(gdb) n
101             kprintf("OS/161 base system version %s\n", BASE_VERSION);
```

You can get the surrounding code with `list`:
```
(gdb) list
96               * anything at all. You can make it larger though (it's in
97               * dev/generic/console.c).
98               */
99
100             kprintf("\n");
101             kprintf("OS/161 base system version %s\n", BASE_VERSION);
102             kprintf("%s", harvard_copyright);
103             kprintf("\n");
104
105             kprintf("Put-your-group-name-here's system version %s (%s #%d)\n",
```

You'll notice that even though there are several calls to `kprintf` here, nothing actually comes out on the console. Single-step with n over the next few lines (first some `kprintf` calls, then calls for bootstrapping various kernel subsystems) until you get to `mainbus_bootstrap`.

When you step over `mainbus_bootstrap`, suddenly all the console messages print out. This is because nothing can actually come out of the console until the kernel searches for and finds the console hardware; this happens inside `mainbus_bootstrap`. This is important to remember: if the kernel hangs or dies without printing anything, it does not mean that something inexplicably horrible happened before that first `kprintf`, it just means that something happened before the call to `mainbus_bootstrap`. You will be writing code that happens before there, so chances are this will happen to you at least once. One of the reasons GDB is important: tracking such problems down with GDB is pretty easy. Tracking them down without GDB, when you can't print anything out, is very hard.

Now tell GDB to execute through to the end of boot with `finish`:
```
(gdb) finish
Run till exit from #0  boot () at ../../main/main.c:121
kmain (arguments=0x8002aea0 "") at ../../main/main.c:215
215             menu(arguments);
```

Add a breakpoint to `sys_reboot`:
```
(gdb) break sys_reboot
Breakpoint 2 at 0x8000d0cc: file ../../main/main.c, line 175.
```

And continue:
```
(gdb) c
Continuing.
```

The menu should have popped up in your other terminal. We are going to use
the poweroff utility to shutdown the machine:
```
OS/161 kernel [? for menu]: p /sbin/poweroff
```

If you step through this you'll see that after attending to various shutdown
tasks, it calls `mainbus_poweroff` to shut off the electricity on the system
board. At that point System/161 will exit, and GDB will print
`Remote connection closed` and you're done.



## Extra content

This is extra content if you finished the lab and early and you want to go further.
This will not be examined.

### Building the Linux Kernel

We learned how to build the OS/161 kernel. Let's see now how to build the world
most popular kernel and the world largest open source project. You will see that
it is surprisingly easy.

First you need to ensure some dependencies are installed:
```
sudo apt-get update -qq
sudo apt-get install -y build-essential
sudo apt-get install -y flex bison bc 
sudo apt-get install -y libncurses-dev wget
sudo apt-get install -y git libssl-dev bc patch libedit-dev libelf-dev
sudo apt-get install -y module-init-tools
```

As before we need to download the Linux kernel source code:
```
cd ~/build

git clone -b v5.16.12 --single-branch git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux-stable.git
```
You could replace "v5.16.12" by the kernel release of your choice. You can check
the longterm and stable releases on this [website](https://www.kernel.org/)}.

The next step is to configure the kernel:
```
cd linux-stable
make defconfig
make menuconfig
```
The second line generate a configuration based of your current kernel configuration.
The last line open an interactive menu to configure your kernel. In a first instance,
you should left the configuration untouched (feel free to explore the options later).

Now, we need to build and install the kernel (this will take a while):
```
make -j 16
sudo make headers_install INSTALL_HDR_PATH=/usr
sudo make modules_install
sudo make install
```
The first line compile the kernel over 16 threads. You can change this option
to align with the number of cores available on the machine you are running the
compilation. The following lines install headers, modules (e.g. drivers) and the
kernel.

Reboot your machine with `sudo reboot now` and make sure you pick the right kernel
in the boot menu when the machine starts. You can check the version of the kernel
currently running using the command `uname -r`

### Exercises

1. It has taken significantly longer to build the Linux kernel. Research how large the project is.
2. Based on the directory structure of OS/161, can you understand Linux kernel directory structure?

We hope you enjoyed this short introduction to Linux.

## Acknowledgement

This lab was developed thanks to material available at [Harvard 0S/161](http://os161.eecs.harvard.edu/),
[ops-class](https://ops-class.org/) and [OS/161 at UBC](https://sites.google.com/site/os161ubc/home).
