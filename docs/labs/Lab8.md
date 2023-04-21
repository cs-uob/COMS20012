# Windows and Linux Who? A Look at the Wild and Wacky Operating Systems Out There
​
# Why and what
​
Today, we'll explore the fascinating world of vintage operating systems! We will take a look at some of the most iconic and unique operating systems of the past. Inclding System7, Plan9 and TempleOS. We'll explore the history, features, and quirks of each system. You'll get hands-on experience with running these operating systems and even learn how to write and compile code in them. By the end of this lab, you'll have a new appreciation for the roots of modern computing and a unique set of skills that probably you will not use anytime soon.
​
# Download Virtualbox images
​
Make sure you have virtual box installed if you want to experiment with Plan9 and TempleOS. Download the virtualbox images for them from [here](https://uob-my.sharepoint.com/:u:/g/personal/dl21421_bristol_ac_uk/EVuv1sfFRXNHmKFM269WOQ4BIxYh6ubO1zFaVS41H7dgMw?e=5ww5Ia) and then import these images and run them.
​
# Plan9
​
Plan 9 is an operating system developed at Bell Labs in the late 1980s and early 1990s. It is named after the science fiction novel "Planets of the Solar Federation" by E. E. Smith. The official development of Plan9 from Bell Labs has stopped, however, there are unofficial active and maintained forks of Plan9 such as 9front which we are using today in the lab.
​
Unlike unix systems at that time, Plan9 was GUI based from the beginning, and most programs there support the mouse, actually they support mouses with 3 buttons since this was the norm back then. 
​
Plan9 was supposed to be a successor to Unix, and lot many of Uni features appeared long before in Plan9, such as the /proc filesystem.
​
![](https://i.imgur.com/j4vQwmj.png)
​
Plan 9 is known for its unique design philosophy, which emphasizes simplicity, consistency, and modularity. This philosophy is reflected in many of the system's features, such as its distributed file system, and its use of a single, simple protocol for inter-process communication. 
​
> The foundations of the system are built on two ideas: a per-process name space and a simple message-oriented file system protocol.
​
— Pike et al.
​
What does that mean? 
​
1. In Plan 9, each process has its own namespace, giving them a unique view of the file system hierarchy. This lets them have their own private resources, hidden from other processes. They interact with the file system using system calls that manipulate their own namespace. Plan 9 also has "mount points" that allow processes to access shared resources in a standardized way, without needing to know their physical location in the file system hierarchy.
2. Plan 9's "message-oriented filesystem" lets processes offer services to each other using virtual files. This expands on Unix's idea of the filesystem as a central point of access to computing resources and provides access to peripheral devices. Plan 9 also allows for connections to server programs using a standardized protocol, simplifying inter-process communication and resource sharing.
​
So an interesting example to that is remote login. In Linux, to this day, we use a text-based interface to remote-login to other computers using the SSH protocol. In Plan9, this is not the case. Plan 9 represents the GUI interface on a terminal by means of three pseudo-files: mouse, cons and bitblt. Remote login in Plan9 relies on the per-process namespaces, allowing client and server processes to communicate across machines. 
​
For example, the cpu command starts a remote session on a computation server. The command exports part of its local namespace, including the user's terminal's devices (mouse, cons, bitblt), to the server, so that remote programs can perform input/output using the terminal's mouse, keyboard and display. This process combines the functionality of both a remote login and a shared network file system. Cool right?
​
Another simillar idea, is that you can debug proccess remotly by simplying  importing /proc into your namespace.
​
**Plan9 cheat sheet**
​
* To open a new terminal, hold the mouse right click, select new by right clicking, and then draw the terminal window while holding the right mouse button.
* To Resize a window, left click on the window border and drag to change the size while holding the left key.
* `ls` to list files and directories.
* `cd` to change directories
* if you want to create files or write anything, do that in the `/tmp` folder.
* Inside the terminal, you can click on any loaction to move the terminal cursor there.
​
**Interesting programs to explore**
​
* The rc shell: to create a new terminal, right click, select new by right clicking, create the window by holding, again, the right click. 
* paint, to paint images, try to draw an image and save it. read the man pages of paint using  `man pain`
* Astro, a program that prints astronomical information.
* GAMES! Plan9 has a collection of games by default, to explore them, 
type `ls /sys/games/lib`. my favorite is sokoban, to run it, type `games/sokoban`.
* The acme text editor: Plan 9 includes a unique and powerful text editor called acme.
​
**Further read**
​
There are many other programs in plan9 that you can experiment with, take a look [here](https://9fans.github.io/plan9port/man/man1/).
​
Yes there are people who use Plan9 as a daily driver, it actually has a webbrowser and you can watch youtube videos in it. [This](https://www.youtube.com/@adventuresin9797/videos) youtube channle has a lot of videos that will teach you how to use Plan9. 
​
# System 7
​
System 7, released by Apple in 1991, was a landmark operating system that brought significant improvements to the Macintosh experience. With its innovative features and user-friendly interface, System 7 paved the way for the modern computing era we enjoy today. From the introduction of multitasking to the addition of color icons and sound effects, System 7 was a major turning point in the history of the Macintosh.
​
![](https://i.imgur.com/PwWOXfg.png)
​
You can experiment with System7 by opening [this](https://infinitemac.org/1996/System%207.5.3) link in your browser.
​
**Things to try**
​
* The graphing calculator (utilities/Graphing Calculator/NuCalc)
* Text editors, compare them to the current mac versions if you have a mac!
* Create art using kidpix in graphics folder.
* ResEdit In Developer folder. In the Mac system, files consisted of two parts: the raw data and a resource fork that contained metadata, as well as images, cursors, and UI elements for applications. By using ResEdit, developers could open these files and explore the various changes that could be made.
* In Games… any of the developers look familiar?  Can you find the precursor to the Halo series
​
# Temple OS
​
![](https://i.imgur.com/y16tqIE.png)
​
TempleOS is a unique lightweight operating system, it was created by a single American programmer named Terry A. Davis. Davis worked alone on the project for over a decade, driven by what he described as a revelation from God following a series of manic episodes. Despite its unconventional origin story and purpose, TempleOS has gained a popularity among developers and enthusiasts who appreciate its minimalist design and unique approach to computing.
​
According to Davis, the system's capabilities, such as its 640x480 resolution, 16-color display, and single-voice audio, were intentionally designed based on direct divine guidance. HolyC, an original variation of the C programming language, was used instead of BASIC, and the operating system included a custom flight simulator, compiler, and kernel.
​
Terry A. Davis (1969–2018) began experiencing regular manic episodes in 1996, leading him to numerous stays at mental hospitals. Initially diagnosed with bipolar disorder, he was later declared schizophrenic. Terry's work is considered to be a piece of art, he created the holy-C compiler, wrote the operating system with it, the graphics libraries, programs and a lot of fun games.
​
​
**TempleOS cheatsheet:**
* `ctrl+alt+t` to open a new terminal
* `ctrl+alt+n` switches windows
* `esc` closes things
* `ctrl+m` open the personal window
* `F1` is the help menu.
* Clicking on files or programs open them in the code editors
* `F5` to run any code when you are inside the editor
​
The terminal language is basically C, where you would type cd ~/Desktop on Linux, you type Cd("~/Desktop"); in TempleOS. Example commands:
​
* `Dir;` is ls
* `Cd;` is cd.
* `DocClear;` is clear
* `Ed` open files in editor
​
**Compiling your first program in TempleOS**
​
* Open a new file with Ed("HelloWorld.HC"); 
Write this hello program in the editor, this is code is in Holy-C
```
U0 HelloWorld() {
  "Hello, world!\n";
}
​
HelloWorld;
```
* While you are in the editor, press F5 to run the code.
* To dissassemble the program, exit the editor by clicking `esc` and type `Uf("Helloworld");`
​
**TempleOS games**
​
There are lot of games built in TempleOS, you can simply access them by pressing `ctrl+m` and double click on any game to run it. To exit the games, click `esc`;
