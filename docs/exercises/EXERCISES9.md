# Exercises sheet 9

**Correction after for revision week.**

**Ask questions on [padlet](https://uob.padlet.org/sanjayrawat/nndaw2bef7vf8jgr){:target="_blank"}!**

1. Why would you want to avoid polling when interacting with devices?

	**Answer:** similarly to spinlock polling will waste CPU cycle. There is very few devices where context switch would outweight the wasted CPU cycles involved in polling.
2. What is the internal bus? What is the extension bus?

	**Answer:** internal bus connect to memories. External bus connect external devices.
3. What are the type of device registers?

	**Answer:** Status, command, data (or a combination of those).
4. How are devices accessed in MIPS?

	**Answer:** devices are memory mapped.
5. Why seeking sector is especially problematic for performances?

	**Answer:** magnetic hard driver involve mechanical steps to access data, this is extremely slow.
6. ext4 or FAT? Discuss potential trade offs (stay within the high-level view seen in the videos).

	**Answer:** ext4 is of the type "collection of extents", FAT is of type "linked list". Check the [slides](https://cs-uob.github.io/COMS20012/slides/W9/notes2.pdf) for the pros and cons of both approaches. As usual there is no "best" solution just different trades-off.
7. Explain soft and hard link.

	**Answer:** soft links are special file containing a path, this path replace the current path during path resolution. Hard links are  "normal" directory entry pointing to an already existing file. Effectively a file may have multiple path.
8. What problem you may face if you create a cycle in your directory structure?

	**Answer:** path resolution becomes impossible. Solution: Mac -> cycle detection, Linux -> no link to directory.
9. Hard drives are slow, how would you solve the problem?

	**Answer:** as always in CS, add some cache ;-).
10. On a piece of paper, write down all the step involved when executing the following code (assume the file exists): **Answer:** check the [last lecture](https://cs-uob.github.io/COMS20012/slides/W9/notes4.pdf).
```
char buffer[14];
inf fd = open("/home/bob/text.txt", O_WRONLY);
write(fd, buffer, 14);
```
