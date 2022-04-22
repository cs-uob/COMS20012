# Exercises sheet 9

<!-- **Correction after for revision week.**

**Ask questions on [padlet](https://uob.padlet.org/sanjayrawat/nndaw2bef7vf8jgr){:target="_blank"}!**-->

1. Why would you want to avoid polling when interacting with devices?

	
2. What is the internal bus? What is the extension bus?

	
3. What are the type of device registers?

4. How are devices accessed in MIPS?

	
5. ext4 or FAT? Discuss potential trade offs (stay within the high-level view seen in the videos).


6. Hard drives are slow, how would you solve the problem?

	






**Answers:**
1. similarly to spinlock polling will waste CPU cycle. There is very few devices where context switch would outweight the wasted CPU cycles involved in polling.
2. internal bus connect to memories. External bus connect external devices.
3. Status, command, data (or a combination of those).
4. devices are memory mapped
5. 	 ext4 is of the type "collection of extents", FAT is of type "linked list". Check the Slides for the pros and cons of both approaches. As usual there is no "best" solution just different trades-off.
6. as always in CS, add some cache.
