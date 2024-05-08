# Exercises sheet 8


1. Explain in your own words why abstractions are necessary.

2. Explain what piece of hardware thread, address space and files help to abstract.

3. Processes are not tied to a specific piece of hardware. What is their role?

4. If you wanted to innovate in the implementation of virtual pages, would x86 architecture or MIPS architecture be more advantageous? (this is a reseacrh based question and is NOT examinable)

5. What is a page fault?

6. Complete the following table using: 

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
 
7. Complete the following table using:
   
| Num    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
|--------|---|---|---|---|---|---|---|---|---|----|----|----|
| Ref    | a | b | c | e | b | d | b | f | e | f  |  b |  d | 
| PP1    |   |   |   |   |   |   |   |   |   |    |    |    |
| PP2    |   |   |   |   |   |   |   |   |   |    |    |    |
| PP3    |   |   |   |   |   |   |   |   |   |    |    |    |
| Fault? |   |   |   |   |   |   |   |   |   |    |    |    |

a. FIFO replacement policy

b. Clock replacement policy


## Answers
1.  They are there to make programming simpler. Without them user level program will have to understand the logic of every piece of hardware they may have to interact with. Abstractions also allow separation of concerns, the abstraction present an interface that hides away the logic of the "object" being abstracted. Abstractions also help with portability, indeed, as long as the same interface is presented to software building upon it, the underlying implementation/hardware should not matter.


2. Thread: CPU, address space: RAM, files: disk.

3. They encapsulate other abstractions necessary for the execution of a task (i.e. thread, address space and files)


4. MIPS is more advantageous as a lot of functionalities in X86 are hardware implemented, therefore MIPS is more adapted for implementing virtual pages. For more information check the following reesrach papers: 
https://user.eng.umd.edu/~blj/papers/computer31-6.pdf
https://user.eng.umd.edu/~blj/papers/CEH-chapter.pdf

5. Page faults occur when the virtual-physical address translation is not available in the TLB.

6. a. FIFO replacement policy


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
| PP1    | a | a | a | a | a | a | a | a | a | a  | b  | b  |
| PP2    |   | b | b | b | b | b | d | d | d | d  | d  | d  |
| PP3    |   |   | c | c | c | e | e | e | e | e  | e  | e  |
| Fault? | * | * | * |   |   | * | * |   |   |    | *  |    |

For 11, we can evict a or e to load b as d will be referenced next, so I have chosen to evict a and load b, you can also choose to evict e and load b, it is just a choice as we do not know the next pages to be loaded.

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

7. 

   a. FIFO replacement policy
| Num    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
|--------|---|---|---|---|---|---|---|---|---|----|----|----|
| Ref    | a | b | c | e | b | d | b | f | e | f  | b  |  d | 
| PP1    | a | a | a | e | e | e | e | f | f | f  | f  | f  |
| PP2    |   | b | b | b | b | d | d | d | e | e  | e  | e  |
| PP3    |   |   | c | c | c | c | b | b | b | b  | b  | d  |
| Fault? | * | * | * | * |   | * | * | * | * |    |    | *  |



b. Clock replacement policy

| Num    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
|--------|---|---|---|---|---|---|---|---|---|----|----|----|
| Ref    | a | b | c | e | b | d | b | f | e | f  |  b |  d | 
| PP1    | a | a | a | e | e | e | e | f | f | f  |  f | d  |
| PP2    |   | b | b | b | b | b | b | b | e | e  |  e | e  |
| PP3    |   |   | c | c | c | d | d | d | d | d  |  b | b  |
| Fault? | * | * | * | * |   | * |   | * | * |    | *  | *  |
| Victim |V=1|V=1|V=1|V=2|V=2|V=1|V=1|V=2|V=3|V=3 | V=1| V=2|
|        |   |   |   |   |V=3|   |   |   |   |    |    |    |
