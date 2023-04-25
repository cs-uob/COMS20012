# Exercises sheet 8


1. Explain in your own words why abstractions are necessary.

2. Explain in your own the difference between policy and mechanism. How does this relate to abstractions?


3. Explain what piece of hardware thread, address space and files help to abstract.

4. Processes are not tied to a specific piece of hardware. What is their role?

5. What are inter-process and intra-process communications?

6. If you wanted to innovate in the implementation of virtual pages, would x86 architecture or MIPS architecture be more advantageous? (this is a reseacrh based paper and is NOT examinable)

7. What is a page fault?

8. Complete the following table using: 

| Num    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
|--------|---|---|---|---|---|---|---|---|---|----|----|----|
| Ref    | a | b | c | a | b | e | d | a | e | d  | b  | d  |
| PP1    |   |   |   |   |   |   |   |   |   |    |    |    |
| PP2    |   |   |   |   |   |   |   |   |   |    |    |    |
| PP3    |   |   |   |   |   |   |   |   |   |    |    |    |
| Fault? |   |   |   |   |   |   |   |   |   |    |    |    |

	a. FIFO replacement policy
	b. MIN replacement policy
	c. LRU replacement policy
	d. Clock replacement policy

## Answers
1.  They are there to make programming simpler. Without them user level program will have to understand the logic of every piece of hardware they may have to interact with. Abstractions also allow separation of concerns, the abstraction present an interface that hides away the logic of the "object" being abstracted. Abstractions also help with portability, indeed, as long as the same interface is presented to software building upon it, the underlying implementation/hardware should not matter.

2. A policy is a sort of "contract" describing what an interface/piece of software should do, while the mechanism is the implementation effecting this policy.

3. Thread: CPU, address space: RAM, files: disk.

4. They encapsulate other abstractions necessary for the execution of a task (i.e. thread, address space and files)

5. Intra-process communication are achieved through the use of shared memory between the thread of a given process and synchronization primitives. Inter-process communications are used for interaction between different processes, they include pipes, sockets, message queues etc. You can get more explanations [here](https://tldp.org/LDP/tlk/ipc/ipc.html)

6. MIPS is more advantageous as a lot of functionalities in X86 are hardware implemented, therefore MIPS is more adapted for implementing virtual pages. For more information check the following reesrach papers: 
https://user.eng.umd.edu/~blj/papers/computer31-6.pdf
https://user.eng.umd.edu/~blj/papers/CEH-chapter.pdf

7. Page faults occur when the virtual-physical address translation is not available in the TLB.

8. a. FIFO replacement policy


| Num    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
|--------|---|---|---|---|---|---|---|---|---|----|----|----|
| Ref    | a | b | c | a | b | e | d | a | e | d  | b  | d  |
| PP1    | a | a | a | a | a | e | e | e | e | e  | b  | b  |
| PP2    |   | b | b | b | b | b | d | d | d | d  | d  | d  |
| PP3    |   |   | c | c | c | c | c | a | a | a  | a  | a  |
| Fault? | * | * | * |   |   | * | * | * |   |    | *  |    |

b. MIN replacement policy

| Num    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
|--------|---|---|---|---|---|---|---|---|---|----|----|----|
| Ref    | a | b | c | a | b | e | d | a | e | d  | b  | d  |
| PP1    | a | a | a | a | a | a | a | a | a | a  | a  | a  |
| PP2    |   | b | b | b | b | b | b | b | b | b  | b  | b  |
| PP3    |   |   | c | c | c | e | d | d | e | d  | d  | d  |
| Fault? | * | * | * |   |   | * | * |   | * | *  |    |    |

c. LRU replacement policy

| Num    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
|--------|---|---|---|---|---|---|---|---|---|----|----|----|
| Ref    | a | b | c | a | b | e | d | a | e | d  | b  | d  |
| PP1    | a | a | a | a | a | a | d | d | d | d  | d  | d  |
| PP2    |   | b | b | b | b | b | b | a | a | a  | b  | b  |
| PP3    |   |   | c | c | c | e | e | e | e | e  | e  | e  |
| Fault? | * | * | * |   |   | * | * | * |   |    | *  |    |

d.Clock Policy


| Num    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
|--------|---|---|---|---|---|---|---|---|---|----|----|----|
| Ref    | a | b | c | a | b | e | d | a | e | d  | b  | d  |
| PP1    | a | a | a | a | a | e | e | e | e | e  | b  | b  |
| PP2    |   | b | b | b | b | b | d | d | d | d  | d  | d  |
| PP3    |   |   | c | c | c | c | c | a | a | a  | a  | a  |
| Fault? | * | * | * |   |   | * | * | * |   |    | *  |    |
