# Lab 6: Synchronization

You need to complete [LAB 5](./LAB5.html) in order to do this lab.
You may also want to look back at [Computer Systems A](https://uob-csa.github.io/website/){:target="_blank"}.

**Remote Access:** If you cannot run the lab on your local machine, you may want to use the Linux
Lab Machine remotely. To do so follow [the online instructions](https://uob.sharepoint.com/sites/itservices/SitePages/fits-engineering-linux-x2go.aspx){:target="_blank"}.
If you experience difficulty contact IT service.

## Fill our survey

<iframe width="640px" height= "480px" src= "https://forms.office.com/Pages/ResponsePage.aspx?id=MH_ksn3NTkql2rGM8aQVG5N9pWWUNd5Khd6GR62JgsZUMEZKRUhXRklNT1VKMTJaV0taWkFZUlhPSC4u&embed=true" frameborder= "0" marginwidth= "0" marginheight= "0" style= "border: none; max-width:100%; max-height:100vh" allowfullscreen webkitallowfullscreen mozallowfullscreen msallowfullscreen> </iframe>

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

When you boot OS/161 you should see options to run various thread tests:

```
OS/161 kernel [? for menu]: ?t

OS/161 tests menu
    [at]  Array test                    [cvt1] CV test 1             (1)
    [at2] Large array test              [cvt2] CV test 2             (1)
    [bt]  Bitmap test                   [cvt3] CV test 3             (1*)
    [tlt] Threadlist test               [cvt4] CV test 4             (1*)
    [km1] Kernel malloc test            [cvt5] CV test 5             (1)
    [km2] kmalloc stress test           [rwt1] RW lock test          (1?)
    [km3] Large kmalloc test            [rwt2] RW lock test 2        (1?)
    [km4] Multipage kmalloc test        [rwt3] RW lock test 3        (1?)
    [km5] kmalloc coremap alloc test    [rwt4] RW lock test 4        (1?)
    [tt1] Thread test 1                 [rwt5] RW lock test 5        (1?)
    [tt2] Thread test 2                 [semu1-22] Semaphore unit tests
    [tt3] Thread test 3                 [fs1] Filesystem test
    [sem1] Semaphore test               [fs2] FS read stress
    [lt1]  Lock test 1           (1)    [fs3] FS write stress
    [lt2]  Lock test 2           (1*)   [fs4] FS write stress 2
    [lt3]  Lock test 3           (1*)   [fs5] FS long stress
    [lt4]  Lock test 4           (1*)   [fs6] FS create stress
    [lt5]  Lock test 5           (1*)   [hm1] HMAC unit test

    (1) These tests will fail until you finish the synch assignment.
    (*) These tests will panic on success.
    (?) These tests are left to you to implement.
```

The
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

### (Re)watch videos

There are two videos from [Lecture 5](../lectures/LECTURE5.html){:target="_blank"} that you should have in
mind when starting to work on this lab.
Please, watch them again before going further.

<iframe width="640" height="360" src="https://web.microsoftstream.com/embed/video/4d068d22-3221-440e-8dfe-4d5e2bc6ea85?autoplay=false&amp;showinfo=true" allowfullscreen style="border:none;"></iframe>

<iframe width="640" height="360" src="https://web.microsoftstream.com/embed/video/239dbda0-0d3c-4528-8a25-5d18f50ccdcc?autoplay=false&amp;showinfo=true" allowfullscreen style="border:none;"></iframe>

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

## Extra content

This is extra content if you finished the lab and early and you want to go further.
This will not be examined.

### Implement Reader-Writer Locks

**WARNING:** This task is significantly harder than the previous ones. There is
less hand holding and you will need to think about your design from start to
finish.

Implement reader-writer locks for OS/161. A reader-writer lock is a lock that
threads can acquire in one of two ways: read mode or write mode. Read mode does
not conflict with read mode, but read mode conflicts with write mode and write
mode conflicts with write mode. The result is that many threads can acquire the
lock in read mode, or one thread can acquire the lock in write mode.

Your solution must also ensure that no thread waits to acquire the lock
indefinitely, called starvation. Your implementation must solve many readers,
one writer problem and ensure that no writers are starved even in the presence
of many readers. Build something you will be comfortable using later. Implement
your interface in `synch.h` and your code in `synch.c`, conforming to the interface
that we have provided.

Unlike locks and condition variables, where we have provided you with a test
suite, we are leaving it to you to develop a test that exercises your
reader-writer locks. You will want to edit `kern/main/menu.c` to allow yourself
to run your test as `rwt{x}` from the kernel menu or command line.

## Acknowledgement

This lab was developed thanks to material available at [Harvard 0S/161](http://os161.eecs.harvard.edu/),
[ops-class](https://ops-class.org/) and [OS/161 at UBC](https://sites.google.com/site/os161ubc/home).
