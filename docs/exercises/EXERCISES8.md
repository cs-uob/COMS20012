# Exercises sheet 8

**Correction after for revision week.**

**Ask questions on [padlet](https://uob.padlet.org/sanjayrawat/jv0uylswqwh3mga0){:target="_blank"}!**

## Fill our survey

<iframe width="640px" height= "480px" src= "https://forms.office.com/Pages/ResponsePage.aspx?id=MH_ksn3NTkql2rGM8aQVG5N9pWWUNd5Khd6GR62JgsZUMEZKRUhXRklNT1VKMTJaV0taWkFZUlhPSC4u&embed=true" frameborder= "0" marginwidth= "0" marginheight= "0" style= "border: none; max-width:100%; max-height:100vh" allowfullscreen webkitallowfullscreen mozallowfullscreen msallowfullscreen> </iframe>


1. In the context of segment memory allocation research and explain the best fit algorithm.

	**Answer:** Best fit allocates the process to a partition which is the smallest sufficient partition among the free available partitions.
2. In the context of segment memory allocation research and explain the worst fit algorithm.

	**Answer:** Best fit allocates the process to a partition which is the largest partition among the free available partitions.
3. In the context of segment memory allocation research and explain the first fit algorithm.

	**Answer:** In the first fit approach is to allocate the first free partition or hole large enough which can accommodate the process. It finishes after finding the first suitable free partition.
4. Explain the advantage of using multi-level page tables.

	**Answer:** It reduces memory usage when compared to single-level page table as unused indirection need not to be allocated. It also allows to address larger memory in a practical fashion.
5. Research how many level are used in a modern Linux.

	**Answer:** Up to 5 levels, see this [article](https://lwn.net/Articles/717293/).
6. Why do you need TLB when implementing page tables?

	**Answer:** multi-level page table require complex chain of indirections that slow down memory access. TLB cashes address translations to speed up memory access.
7. If you wanted to innovate in the implementation of virtual pages, would x86 architecture or MIPS architecture be more advantageous?

	**Answer:** MIPS.
8. What is a page fault?

	**Answer:** Page faults occur when the virtual-physical address translation is not available in the TLB.
9. Complete the following table using: **Answer:** see [padlet](https://uob.padlet.org/sanjayrawat/jv0uylswqwh3mga0){:target="_blank"}.

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
