# Lab 6: Synchronization

You need to complete [LAB 5](./LAB5.html) in order to do this lab.
You may also want to look back at [Computer Systems A](https://uob-csa.github.io/website/).

## Setup

To successfully run the LAB 6 tests you will need to configure your
kernel to use a large amount of memory. We suggest the maximum of 16 MB.
This is because your kernel currently leaks memory allocations that are
larger than a page, and that includes all 4K thread stacks. So you will find
that even if you correctly allocate and deallocate memory in your
synchronization primitives and problems, your kernel will only run a certain
number of tests before it runs out of memory and panics. This is normal.
However, you should make sure that your kernel does not leak smaller
amounts of memory. Your kernel includes tools to help you measure this.

## Concurrency in OS/161

The goal of synchronization is to eliminate any undesirable timing effects—​or
race conditions—on the output of your programs while preserving as much
concurrency as possible.

For the synchronization problems we provide, threads may run in different
orders depending on the order of events, but by using the synchronization
primitives you will build, you should be able to guarantee that they meet
the constraints inherent to each problem (while not deadlocking).

### Built-In Tests

When you boot OS/161 you should see options to run various thread tests. The
thread test code uses the semaphore synchronization primitive. You should trace
the execution of one of these thread tests in GDB to see how the scheduler acts,
how threads are created, and what exactly happens in a context switch. You
should be able to step through a call to thread_switch and see exactly where
the current thread changes.

Thread test 1—​or tt1 at the kernel menu or on the command line—​prints the
numbers 0 through 7 each time each thread loops. Thread test 2 (tt2) prints
only when each thread starts and exits. The latter is intended to show that
the scheduler doesn’t cause starvation—​the threads should all start together,
spin for awhile, and then end together. It’s a good idea to familiarize
yourself with the other thread tests as well.

### Debugging Concurrent Programs

One of the frustrations of debugging concurrent programs is that timing effects
will cause them them to do something different each time. The end result should
not be different—​that would be a race condition. But the ordering of threads
and how they are scheduled may change. Our test drivers in the kern/test
directory will frequently have threads spin or yield unpredictably when starting
tests to create more randomness. However, for the purposes of testing you may
want to create more determinism.

The random number generator used by OS/161 is seeded by the random device
provided by System/161. This means that you can reproduce a specific execution
sequence by using a fixed seed for the random device. You can pass an explicit
seed into random device by editing the random line in your sys161.conf file.
This may be help you create more reproducible behavior, at least when you are
running the exact same series of tests. You have seen how to set this
in [LAB 5](./LAB5.html).

### Exercises

1. What happens to a thread when it calls thread_exit? What about when it sleeps?
2. What function—​or functions—​handle(s) a context switch?
3. What does it mean for a thread to be in each of the possible thread states?
4. What does it mean to turn interrupts off? How is this accomplished? Why is it important to turn off interrupts in the thread subsystem code?
5. What happens when a thread wakes up another thread? How does a sleeping thread get to run again?
6. What function (or functions) choose the next thread to run?
7. How is the next thread to run chosen?
8. What role does the hardware timer play in scheduling?
9. What hardware independent function is called on a timer interrupt?
10. Describe how wchan_sleep and wchan_wakeone are used to implement semaphores.

## Implementing Synchronization Primitives

It is possible to implement the primitives below on top of other primitives—​but
it is not necessarily a good idea. You should definitely read and understanding
the existing semaphore implementation since that can be used as a model for
several of the other primitives we ask you to implement below.

### Implement Locks

Implement locks for OS/161. The interface for the lock structure is defined
in `kern/include/synch.h`. Stub code is provided in `kern/threads/synch.c`.
When you are done you should repeatedly pass the provided `lt{1,2,3}` lock tests.

Note that you will not be able to run any of these tests an unlimited number of
times. Due to limitations in the current virtual memory system used by your
kernel, appropriately called `dumbvm`, your kernel is leaking a lot of memory.
However, your synchronization primitives themselves should not leak memory,
and you can inspect the kernel heap stats to ensure that they do not.

You may wonder why, if the kernel is leaking memory, the kernel heap stats don’t
change between runs of `sy1`, for example, indicating that the semaphore
implementation allocates and frees memory properly. The reason is that the
kernel malloc implementation we have provided is not broken, and it will
correctly allocate, free and reallocate small items inside of the memory made
available to it by the kernel. What does leak are larger allocations like, for
example, the 4K thread kernel stacks, and it is these large items that
eventually cause the kernel to run out of memory and panic.

### Implement Condition Variables

Implement condition variables with Mesa—​or non-blocking—​semantics for OS/161.
The interface for the condition variable structure is also defined in `synch.h`
and stub code is provided in `synch.c`.

We have not discussed the differences between condition variable semantics.
Two different varieties exist: Hoare, or blocking, and Mesa, or non-blocking.
The difference is in how `cv_signal` is handled:

In Hoare semantics, the thread that calls `cv_signal` will block until the
signaled thread (if any) runs and releases the lock.

In Mesa semantics the thread that calls `cv_signal` will awaken one thread
waiting on the condition variable but will not block.

Please implement Mesa semantics. When you are done you should repeatedly
pass the provided `cvt{1,2,3,4}` condition variable tests.

## Acknowledgement

This lab was developed thanks to material available at [Harvard 0S/161](http://os161.eecs.harvard.edu/),
[ops-class](https://ops-class.org/) and [OS/161 at UBC](https://sites.google.com/site/os161ubc/home).
