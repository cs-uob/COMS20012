# Exercises sheet 5

**Correction around Easter.**

## Fill our survey

<iframe width="640px" height= "480px" src= "https://forms.office.com/Pages/ResponsePage.aspx?id=MH_ksn3NTkql2rGM8aQVG5N9pWWUNd5Khd6GR62JgsZUQjhUWlZOQ1c2V1A5WExWU0hUVjdZMldBSC4u&embed=true" frameborder= "0" marginwidth= "0" marginheight= "0" style= "border: none; max-width:100%; max-height:100vh" allowfullscreen webkitallowfullscreen mozallowfullscreen msallowfullscreen> </iframe>

## A brief history of Operating Systems

1. Look at the photo in first lecture videos. Identify the persons and read about them (check the caption in the slides).
2. Computing was a very feminine profession in its early days. It changed in the 70s. Read about this.

## OS structure

1. Explain in your own words the concept of interrupt and trap.
3. Explain the concept of rings on Intel architecture. Compare to privilege level on MIPS architecture.
2. Explain what is a Privilege Level and the Current Privilege Level.
4. What is a trap handler?


## Synchronization primitives

1. What does it mean for an instruction to be atomic?
2. Write pseudocode for the TAS instruction.
3. Write pseudocode for the CAS instruction.
4. Why spinlock should only be used when resource will be held for a very short time?
5. This problem demonstrates the use of semaphores to coordinate three types of processes [there will be a solution video uploaded on week 8]. Santa Claus sleeps in his shop at the North Pole and can only be wakened by either

    a. all nine reindeer being back from their vacation in the South Pacific, or

    b. by some of the elves having difficulties making toys.

    To allow Santa to get some sleep, the elves can only wake him when three of them have problems. While three elves are having their problems solved, any other elves wishing to visit Santa must wait for those elves to return. If Santa wakes up to find three elves waiting at his shop's door, along with the last reindeer having come back from the tropics, Santa has decided that the elves can wait until after Christmas, because it is more important to get his sleigh ready. (It is assumed that the reindeer don't want to leave the tropics, and therefore they stay there until the last possible moment.) The last reindeer to arrive must get Santa while the others wait in a warming hut before being harnessed to the sleigh.
