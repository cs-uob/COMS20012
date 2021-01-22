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

You need a configuration file that we are going to place in `~/os161/root/`:
```
cd ~/os161/root/
wget
```

Have a look through this file, it should
be self explanatory if you ever have to modify it.

Now let's run our kernel:
