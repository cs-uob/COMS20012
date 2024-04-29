Weird Operating Systems
=======================

In this lab we're going to explore some of the features and interfaces from three weird OSs: *Plan 9*, *OpenBSD* and *Temple OS*.  None of this is examinable: try and have fun exploring different ways of doing things with a computer!  Feel free to play with the OSs in any order.

Plan 9
------

Plan 9 still exists as an operating system in its own right, but there are alternative versions of it that are a little more maintained.  [9front](http://www.9front.org/releases/) is a modern reimplementation of Plan 9 that you can install on your own computer.  [plan9port](https://9fans.github.io/plan9port/) is a port of the userland from Plan 9 to Linux. 

Lets install it and have a play...
```.sh
git clone https://github.com/9fans/plan9port plan9
cd plan9
sh INSTALL
# about 4 minutes later...
PLAN9="${HOME}/plan9" export PLAN9
PATH="${PATH}:${PLAN9}/bin" export PATH
```

Plan 9 *should* be installed now.  Check its all working by bringing up the manual:

```.sh
9 man intro | less
```

Assuming it's all working lets bring up the Plan 9 editor `acme`

```.sh
9 acme
```

### The Acme editor

Acme is a *weird* editor that acts as a kind of hybrid between the shell and a text editor.  Unlike other traditional programming editors for UNIX-like systems, you can control it with the mouse.  Each button does a different thing:

- Left mouse button (Button 1): Selects text
- Middle mouse button (Button 2): Executes commands
- Right mouse button (Button 3): Fetches things

To read the intro man page in the terminal we had to use `less` to be able to scroll through it.  Lets open it in Acme instead!

1. Create a new window by *middle clicking* on `New` in the blue bar.
2. In the new yellow window type `man intro`
3. Select the text you just typed using the *middle mouse button*.
4. The man page should appear in a new window.
5. Lets close it by *middle clicking* the `Del` in the blue bar immediately above your new window.

*TODO*: Skim the README for Acme to get a feel for how it works at <https://acme.cat-v.org/readme>.


#### Coding in Acme

Lets see what is in our home folder.

1. Create a new window by *middle clicking* on `New`.
2. At the end of the new window's blue bar type `/home/`*your username*`/` and click on it with the right mouse button.
3. Lets create a new folder. At the start of the new window's blue bar is the path.  Change it to say `mkdir /home/`*your username*`/my-code`, then run it with the middle mouse button, and open it with the right mouse button.
4. Lets make a new file.  Create a new window and add the path `/home/`*your username*`/my-code/hello.c`
6. In the file window write a basic hello world program:

```.c
#include <stdio.h>

int main(void) {
    printf("Hello World!\n");
    return 0;
}
```

7. Middle click `Put` to save it, add `Get` to the blue bar and middle click to open files.

8. Try Right clicking `stdio.h` in your code.  Close the window when you've finished inspecting it.

9. Create a new window and type `9c -o /home/`*your username*`/my-code/hello.o /home/`*your username*`/my-code/hello.c`.  Select it all with the middle mouse button to compile your code.
10. Change it to say `9l -o /home/`*your username*`/hello /home/`*your username*`/hello.o` and run it to link your program (yes its old school compilation).
11. Middle click `/home/`*your username*`/hello` to run your new program.

#### More things to do

Keep exploring in Acme, theres a bunch of things you can do in it and (once you
get a feel for it) it is kinda neat.  Try using it for a week or so to write
all your code... see if you can find a fork of it with Language Server Protocol
(LSP) extensions and see what you think.  If nothing else you'll get nerd
points when people ask what editor you use (and you'll intimidate those smug
Vim and Emacs users).


1. `Del` all the windows and swear at *Rob Pike* for making such a weird tool.
2. Hit `Exit` and go back to Linux land.
3. Google who *Rob Pike* is and marvel at all he's done.
4. Explore other man pages and programs in `plan9/bin` (`cmapcube` and `9term` are interesting).

OpenBSD
-------

OpenBSD is my preferred OS.  It's slow and grumpy, but it also (for the most part) just works and gets on with things and gets out of your way with a minimum of fuss.  Whilst it may seem _similar_ to Linux it is a **completely** different OS and there are differences---even for things like the basic commands (`ls` has different options to the `ls` on Linux!)

Here is a Vagrantfile to bring up a VM for the stable release of it:

```.ruby
Vagrant.configure("2") do |config|
    config.vm.box = "generic/openbsd7"
end
```

Bring up a VM and have a little play.  You'll find there are some obvious differences:

- `pkg_info -Q` searches for software to install.
- `pkg_add` installs new software to install.
- There is no `sudo`, but there is a different command called `doas` that does much the same things; and the `su` command is always available too.

To show what we can do with OpenBSD I want to focus on it's sandboxing mechanisms that let you restrict what a process can do.  These features ensure that if an program is attacked, then an attacker doesn't gain full access to the OS.  This is particularly useful for network facing applications---like a web browser---where an attacker can be remote and the program is expected to compile Javascript code provided by unknown people. 

Lets start by reading the documentation:

1. Read `man 2 pledge`
2. Read `man 2 unveil`

Lets sandbox a small application using these systemcalls! [timg](https://github.com/hzeller/timg) is a small commandline image viewer: lets clone it and add some sandboxing to it.  Specifically we want our sandbox to ensure that:

- It can only access the files it needs and any file passed to it.
- It uses only the system features that it needs---it doesn't need network access!

3. Install dependencies (`doas pkg_add git graphicsmagick cmake ffmpeg libdeflate`).  More dependencies may be needed, the `pkglocatedb` package contains a program `pkglocate` that will let you search for which package contains which missing library.
4. `git clone https://github.com/hzeller/timg`
5. `cd timg; mkdir build; cd build`
6. `cmake ../ -DWITH_LIBSIXEL=Off -DWITH_VIDEO_DECODING=Off -DWITH_TURBOJPEG=Off -DWITH_POPPLER=Off -DWITH_RSVG=Off -DWITH_OPENSLIDE_SUPPORT=Off -DWITH_QOI_IMAGE=Off -DWITH_STB_IMAGE=Off` (hey lets not do more work than we need `;-)`)
7. `make`
8. `src/timg -h` and check it is working.

If it is all good then its time to start modifying the source code.  After `if (filelist.empty()) { }` in the `main()` function in `../src/timg.cc` (around line 930) seems like a good place to start?

Think about:

- What features this program really needs and how they relate to pledges you can make.
- How you will test if the sandbox is working (**hint:** it is fine to trigger a crash deliberately while testing).


Temple OS
---------

Lets have a play with Terry Davis's *Temple OS*!

First things first, lets build a VM for it.

1. Go and download an Install ISO for Temple OS from <http://templeos.org> 
2. Create a new VM in VirtualBox that has *at least* 512MB of RAM and is for a 64bit OS.
3. The ISO should boot.  You can install it if you like or just use it in RAM.
4. Once its up it'll take you through a tutorial... run through it and have a play with some of the games.

Classic Mac OS
--------------

Old versions of Mac OS can be run in a browser at <https://infinitemac.org>!

Go boot up [System 7.5](https://infinitemac.org/1994/System%207.5) and have an explore:

1. Boom in games is a Bomberman clone I spent *ages* playing as a kid.  Snood also took up large portions of time.  Have a play!
2. Can you find the Mac-only precursor to the Halo games?
3. In the Utilities folder there is a program called Graphing Calculator. Have a play then find someone with a Mac and see if you can find it on a current Mac over 30 years later!  Has it changed much?
4. Find a program called ResEdit and marvel at what you can do with it.

Ancient OSs
-----------

The [Interim Computer Museum](https://icm.museum/) hosts many ancient OSs you can explore (and even runs courses on how to use them).

1. `ssh menu@sdf.org` and have an explore.  Can you figure out how to use Unics 1.0?

(**Note:** the ICM sometimes goes down `:-(`)


