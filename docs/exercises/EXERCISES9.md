# Exercises sheet 9

**Correction after for revision week.**

**Ask questions on [padlet](https://uob.padlet.org/sanjayrawat/nndaw2bef7vf8jgr){:target="_blank"}!**

1. Why would you want to avoid polling when interacting with devices?
2. What is the internal bus? What is the extension bus?
3. What are the type of device registers?
4. How are devices accessed in MIPS?
5. Why seeking sector is especially problematic for performances?
6. ext4 or FAT? Discuss potential trade offs (stay within the high-level view seen in the videos).
7. Explain soft and hard link.
8. What problem you may face if you create a cycle in your directory structure?
9. Hard drives are slow, how would you solve the problem?
10. On a piece of paper, write down all the step involved when executing the following code (assume the file exists):
```
char buffer[14];
inf fd = open("/home/bob/text.txt", O_WRONLY);
write(fd, buffer, 14);
```
