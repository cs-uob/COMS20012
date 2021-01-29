# Lab 7: System Calls and Processes

You need to complete [LAB 6](./LAB6.html)  in order
to do this lab.

**Note:** this lab runs over two weeks (Week 22 and 23).

**Remote Access:** If you cannot run the lab on your local machine, you may want to use the Linux
Lab Machine remotely. To do so follow [the online instructions](https://uob.sharepoint.com/sites/itservices/SitePages/fits-engineering-linux-x2go.aspx).
If you experience difficulty contact IT service.

## Introduction

In this assignment you will add process and system call support to your
OS/161 kernel.

Currently no support exists for running user processes—​the tests you have run up
to this point have run in the kernel as kernel threads. By the time you finish
LAB 7 you will have the ability to launch a simple shell and enter a
somewhat-familiar UNIX environment. Indeed, future tests will be run as user
processes, not from the kernel menu.

In contrast to [LAB 6](./LAB6.html), LAB 7 requires a great deal more thought
and planning. You will be writing a lot more code. We are not giving you many
examples. We have not designed your data structures for you. You will need
to determine what needs to be implemented, where to put the code required,
how the data structures are designed and implemented, and how everything fits
together. We just care that your system calls meet the interface specification.

As a final piece of advice, you will produce code bases that are
large, complex, and potentially very difficult to debug. You do not want to
introduce bugs into your kernel because they will be very hard to remove. Our
advice—​slow down, design, think, design again, discuss with your partner,
and slow down again. Then write some code.

## Lab objectives

In this lab, you must implement the interface between user-mode programs—​or user
land—​and the kernel. As usual, we provide part of the code you will need.
Your job is to identify, design and build the missing pieces.

The first step is to read and understand the parts of the system that we have
written for you. Our code can run one user-level C program at a time as long as
it doesn’t want to do anything but shut the system down. We have provided sample
user programs that do this (`sbin/{reboot,halt,poweroff`), as well as others that
make use of features you will be adding in this and future assignments.

So far, all the code you have written for OS/161 has only been run within, and
only been used by, the operating system kernel. In a real operating system, the
kernel’s main function is to provide support for user-level programs. Most such
support is accessed via system calls.

However, before looking at how to implement system calls, we first walk you
through how the kernel gets to run. Remember, that the kernel is just like most
programs except that it is the first program that gets to run.

## Design documents

The design document is a very important part of this lab. You should discuss it
in depth with your partner, discuss among the tuples within your TA groups, and
with your TA. While the lab are not assessed this year, doing this exercise properly
is extremely important to get the most out of this unit.

A design document should clearly reflect the development of your solution, not
merely explain what you programmed. If you try to code first and design later,
or even if you design hastily and rush into coding, you will most certainly end
up confused and frustrated. Don’t do it! Work with your partner to plan
everything you will do. Don’t even think about coding until you can precisely
explain to each other what problems you need to solve and how the pieces relate
to each other.

Note that it can often be hard to write (or talk) about new software design—​you
are facing problems that you have not seen before, and therefore even finding
terminology to describe your ideas can be difficult. There is no magic solution
to this problem, but it gets easier with practice. The important thing is to go
ahead and try. Always try to describe your ideas and designs to your partner.
In order to reach an understanding, you may have to invent terminology and
notation. This is fine, just be sure to document it in your design. If you do
this, by the time you have completed your design, you will find that you have
the ability to efficiently discuss problems that you have never seen before.

Your design document can be as long as you like. It should include both English
definitions and explanations of core functions and interfaces as well as
pseudocode and function definitions where appropriate. We suggest that you use a
markup language to format your design nicely (e.g. an MD file in a github repo).

The contents of your design document should include (but not be limited to):
1. A description of each new piece of functionality you need to add for Lab 7.
2. A list and brief description of any new data structures you will have to add to the system.
3. Indications of what, if any, existing code you may model your solution off of.
4. A description of how accesses to shared state will be synchronized, if necessary.
