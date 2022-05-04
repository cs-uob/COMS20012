# Exercises sheet 8




1. In the context of segment memory allocation research and explain the best fit algorithm.

	
2. In the context of segment memory allocation research and explain the worst fit algorithm.

3. In the context of segment memory allocation research and explain the first fit algorithm.

4. Explain the advantage of using multi-level page tables.

	
5. Research how many level are used in a modern Linux.

6. Why do you need TLB when implementing page tables?

7. If you wanted to innovate in the implementation of virtual pages, would x86 architecture or MIPS architecture be more advantageous?

8. What is a page fault?

9. Complete the following table using: 

| Num    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
|--------|---|---|---|---|---|---|---|---|---|----|----|----|
| Ref    | a | b | c | d | e | a | b | a | b | d  | e  | d  |
| PP1    |   |   |   |   |   |   |   |   |   |    |    |    |
| PP2    |   |   |   |   |   |   |   |   |   |    |    |    |
| PP3    |   |   |   |   |   |   |   |   |   |    |    |    |
| Fault? |   |   |   |   |   |   |   |   |   |    |    |    |

	a. FIFO replacement policy
	b. MIN replacement policy
	c. LRU replacement policy
	d. Clock replacement policy


 **Answers**

 **Answer 1:** Best fit allocates the process to a partition which is the smallest sufficient partition among the free available partitions.
 
 **Answer 2:** Best fit allocates the process to a partition which is the largest partition among the free available partitions.
 
 **Answer 3:** In the first fit approach is to allocate the first free partition or hole large enough which can accommodate the process. It finishes after finding the first suitable free partition.
 
 **Answer 4:** It reduces memory usage when compared to single-level page table as unused indirection need not to be allocated. It also allows to address larger memory in a practical fashion.
 
 **Answer 5:** Up to 5 levels, see this [article](https://lwn.net/Articles/717293/).
 
 **Answer 6:** multi-level page table require complex chain of indirections that slow down memory access. TLB cashes address translations to speed up memory access.
 
 **Answer 7:** MIPS is more advantageous as a lot of functionalities in X86 are hardware implemented (check slides 36 and 37), therefore MIPS is more adapted for implementing virtual pages. 
 
 **Answer 8:** Page faults occur when the virtual-physical address translation is not available in the TLB.
 
**Answer 9:** 

a. FIFO replacement policy
	
| Num    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
|--------|---|---|---|---|---|---|---|---|---|----|----|----|
| Ref    | a | b | c | d | e | a | b | a | b | d  | e  | d  |
| PP1    | a | a | a | d | d | d | b | b | b | b  | b  | b  |
| PP2    |   | b | b | b | e | e | e | e | e | d  | d  | d  |
| PP3    |   |   | c | c | c | a | a | a | a | a  | e  | e  |
| Fault? | * | * | * | * | * | * | * |   |   | *  | *  |    |
 

b. MIN replacement policy

| Num    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
|--------|---|---|---|---|---|---|---|---|---|----|----|----|
| Ref    | a | b | c | d | e | a | b | a | b | d  | e  | d  |
| PP1    | a | a | a | a | a | a | a | a | a | d  | d  | d  |
| PP2    |   | b | b | b | b | b | b | b | b | b  | b  | b  |
| PP3    |   |   | c | d | e | e | e | e | e | e  | e  | e  |
| Fault? | * | * | * | * | * |   |   |   |   | *  |    |    |

	c. LRU replacement policy
	
|Num     | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
|--------|---|---|---|---|---|---|---|---|---|----|----|----|
| Ref    | a | b | c | d | e | a | b | a | b | d  | e  | d  |
| PP1    | a | a | a | d | d | d | b | b | b | b  | b  | b  |
| PP2    |   | b | b | b | e | e | e | e | e | d  | d  | d  |
| PP3    |   |   | c | c | c | a | a | a | a | a  | e  | e  |
| Fault? | * | * | * | * | * | * | * |   |   | *  | *  |    |

	d. Clock replacement policy
	
| Num    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
|--------|---|---|---|---|---|---|---|---|---|----|----|----|
| Ref    | a | b | c | d | e | a | b | a | b | d  | e  | d  |
| PP1    | a | a | a | d | d | d | b | b | b | b  | b  | b  |
| PP2    |   | b | b | b | e | e | e | e | e | d  | d  | d  |
| PP3    |   |   | c | c | c | a | a | a | a | a  | e  | e  |
| Fault? | * | * | * | * | * | * | * |   |   | *  | *  |    |

