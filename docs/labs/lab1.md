# Lab 1: Vagrant and Passwords

Hi class. Welcome to your first lab. Hope you will enjoy and have fun! 

If you have questions ask Alma, Joseph or our TAs. 

## 1. Setting up Vagrant
As you will be using Vagrant for you VM management though out your unit, lets learn how to setup a VM with Vagrant. In the next lab session we will learn how to install Kali and other VMs we will be using but they will be inside of Vagrant. \[We assume that Vagrant and VirtualBox VVM is already installed on your host machine. If not, contact IT.\]
You may also want to watch videos from [David's COMS10012](https://cs-uob.github.io/COMS10012/exercises/part1/posix1/install.html){:target="_blank"}.
1. On your host machine, open a terminal in you home directory (or whatever directory you are asigned which has good memory). Make a directory `mkdir CS_vagrant`
2. `cd CS_vagrant` and then make another directory `mkdir seclabs`
3. `cd seclabs`
4. `vagrant init hashicorp/bionic64`.
5. `vagrant up`. First time, this is will download Ubunut 18.04-64. It will take a while. Once done, we are ready to launch this VM.
6. Lets ssh our new VM. `vagrant ssh`
7. You are in your new VM. This VM shares a folder from your host machine, which is the same folder from where you lanched your VM, i.e. `seclab`. This folder is mapped to `/vagrant` in you VM. if you do `cd /vagrant`, you can see the content of your host folder. We will use this folder for all our work (i.e. you can copy your files in seclab folder and access tem from /vagrant folder from VM).
8. This VM is running a fresh Ubuntu. So, we need to get few things installed in this. Lets do it. Run these commands.
9. `sudo apt update`
10. `sudo apt install build-essential` This will install gcc.
11. `sudo apt install gdb` This will install GDB.
12. We will also use (occasionally) x86-32 bit compiled code. Lets setup this so that we can compile and run x86-32 applications. Run these commands.
13. `sudo dpkg --add-architecture i386`
14. `sudo apt-get install libc6:i386 libncurses5:i386 libstdc++6:i386`
15. `sudo apt-get install multiarch-support`
16. `sudo apt-get install gcc-multilib`
17. Now you have all the tools that will be required. To test, run these commends and check if they run properly-- `gcc --version`, `gdb --version`, `objdump --version`
18. When done with your lab, you can `logout` and then in your host machine, you can close the VM-- `vagrant halt`


## 2. Crackme
This part of the lab is a little *crackme*... a program where you have to
figure out how to get to the victory condition.  Source code for all
the files is given at the bottom alongside a [tarball of the source code](https://github.com/cs-uob/COMS20012/raw/master/docs/materials/lab1.tar.gz) if you prefer.

**NOTE** Breaking the *crackme* is optional! If you want to have fun or you are curious, try! Make a stack protection disabled!

**NOTE** If you need a little help on how to use GDB, try GDB cheat sheet [GDB cheat sheet](../materials/lecture1/GDBCheatSheet.pdf){:target="_blank"}. If you want to play with GDB and learn more how it works, try here [GDBadditionLAB1.pdf]([https://github.com/cs-uob/COMS20012/blob/master/docs/materials/lecture1/GDBadditionLAB1.pdf](https://github.com/cs-uob/COMS20012/blob/master/docs/materials/lecture1/GDBadditionLAB1.pdf)){:target="_blank"}
**NOTE:** working from home?  If you need help post a question in the
Teams group for the unit and we'll try and help you from there, but if
at all possible do try and attend the lab where there will be *more* support.

**NOTE:** this weeks lab *should* work on any machine... including
an M1 Mac, a lab machine and anything else you can throw at it... but
you *might* need to tweak things to get it all working; and if in
doubt fall back to `ssh snowy.cs.bristol.ac.uk`

## A simple crackme

You've been given a simple crackme to solve.   The source code has
been given to let you have a look at how it works without having to
resort to assembly (if you'd like a bit more of a challenge... don't
look at the source code).

Compile the code with `CFLAGS=--std=c99 make` or if you enjoy typing things out:

```sh
CFLAGS=--std=c99
cc -o sha512.o ${CFLAGS} sha512.c
cc -o crackme ${CFLAGS} crackme.c sha512.o
```

The crackme will ask you for a password on standard input.  That
password will be hashed with SHA512 and if the hashes match: you win!

**Exercise 1:** compile the code and run it with `./crackme`.  Enter a
password.  Did you get it right?  If you want to feed inputs in from a
script you can do it with a *herestring* in many shells (`./crackme
<<<'my guess'`).

## If in doubt: cheat

Oh dear, trying to reverse a hash value (even a non-cryptographic,
hash that should never be used for password storage like the
SHA-family... has no one ever heard of
[`scrypt`](https://wikipedia.org/wiki/Scrypt)?) sounds tedious!  You
could go and fire up old [John the
Ripper](https://www.openwall.com/john/) or
[hashcat](https://hashcat.net/hashcat/) but who has time for that!

Instead lets cheat!  If you stick the compiled program into
[`nm`](https://www.man7.org/linux/man-pages/man1/nm.1.html) (or look
at the source code) you can see it calls `memcmp` from `libc`.  

Dynamic linking opens up a whole range of posibilities to a deviously
minded programmer.  In particular the `LD_PRELOAD` variable is a
wonderful way to change what a system looks like.  Have a read of the
man page for [`man 8
ld.so`](https://man7.org/linux/man-pages/man8/ld.so.8.html) to find
other devious little options.

Is it *really* as simple as?:

```sh
echo 'int memcmp(const void *s1, const void *s2, int n) { return 0; }' >preload.c
cc ${CFLAGS} -shared -o preload.so preload.c
LD_PRELOAD=$PWD/preload.so ./crackme
```

**NOTE:** Mac users might like to have a look at `man 1 dyld` and in
particular the `DYLD_INSERT_LIBRARIES` variable instead.  Windows
users might like to have a read up on DLL injecting techniques.

**Exercise 2:** Solve the crackme by cheating.

**Exercise 3:** Why does this work and how do you in general stop it?
What happens if you make the `crackme` program a SUID binary (`chmod
+s ./crackme`)?  What happens if you statically link it?  When exactly
does the linking happen (hint: try sticking a `watch` point on the
address in the Global Offset Table (GOT) and Procedure Linkage Table
(PLT))?  What happens if you compile with `-Wl,-z,relro,-z,now` does
that fix things (and if not, why not)?  How would you design a system
to prevent this?  *Chat with your TAs or Joseph if this is interesting to you.*

## Maybe its not as hard as you think

Okay, maybe mucking about with preloading is a little devious.  Lets
try and beat the lab fairly.

Have a look at the code (or the disassembly if you're feeling up for
hard mode).  Can you spot a bug?  What happens if you do something
like:

```sh
./crackme <<<$(perl -e 'print "A"x17')
```

**Exercise 4:** Figure out exactly what you can control and why.  Can
you do arbitrary code execution?  Can you corrupt memory or the
integrity of the program?  What constraints are there (if any) on the your
password input? 

**Exercise 5:** Solve the crackme.

**Hint 1:** `tr B-ZA A-Z <<<"ZPV EPO'U OFFE UP SFWFSTF B XIPMF IBTI CVU UIFSF BSF TPNF DPOEJUJPOT PO XIBU ZPVS IBTI NVTU MPPL MJLF GJHVSF UIFN PVU GJSTU!"`

**Hint 2:** `tr B-ZA A-Z <<<"ZPV DBO PWFSGMPX BMM CVU UXP CZUFT PG UIF IBTI XSJUF B QSPHSBN UP HFOFSBUF SBOEPN JOQVUT BOE TUPQ XIFO ZPV GJOE B IBTI UIBU IBT UIF TBNF UXP CZUFT"`

**Hint 3:** `tr B-ZA A-Z <<<"AFSP CZUFT BSF B QBJO SJHIU!"`

**Hint 4:** `tr B-ZA4-90-3 A-Z0-9 <<<"Doms64456isc4o5"`

# Source code

[https://github.com/cs-uob/COMS20012/raw/master/docs/materials/lab1.tar.gz]

## `crackme.c`

```c
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sha512.h"

#define DEBUGHASH(name) do { debug_hash(#name, name); } while (false)
void debug_hash(char *name, uint64_t hash[STATE_LEN]);

int main(void) {
  uint64_t hashed_guess[STATE_LEN];
  uint64_t solution[STATE_LEN] = {
    0x7AEBDFC5F2B94822,
    0xB9CC57568FC71B5A,
    0x7F034712F5C2903E,
    0xB8ED3DC8194018E7,
    0xB83EEAA0EB36ECFB,
    0x8F26802B89ED0233,
    0x0EF6EA9C3E345645,
    0x84A080B39E8CED90,
  };
  uint8_t guess[16];
  bool success;

  /* Initialise the memory for the guess */
  memset(guess, 0, sizeof guess);
  
  /* Read in their guess */
  printf("Enter your password: ");
  scanf("%78s", guess);

  /* Hash it */
  sha512_hash(guess, sizeof guess, hashed_guess);

  DEBUGHASH(hashed_guess);
  DEBUGHASH(solution);
  
  /* Did you win? */
  success = (bool) (!memcmp(hashed_guess, solution, sizeof solution));
  if (success) printf("[INFO] You win :-D\n");
  else printf("[INFO] You lose!\n");
      
  return success? EXIT_SUCCESS: EXIT_FAILURE;
}

/* Helpful hash printing function. */
void debug_hash(char *name, uint64_t hash[STATE_LEN]) {
  fprintf(stderr, "\n%s = {\n", name);
  for (int i = 0; i < STATE_LEN; i++)
    fprintf(stderr, "  0x%016lX,\n", hash[i]);
  fprintf(stderr, "}\n");
}
```

## `Makefile`

Just type `make` to compile... or `CFLAGS='-Wall -Wextra --std=c11
-pedantic' make` if you'd like to tweak the compilation flags.

```make
crackme: crackme.c sha512.o
```

## `sha512.h`

Little header file containing the prototypes for a SHA512 hash
implementation.  No bugs here (for the purposes of the lab).

```c
#pragma once
#include <stdint.h>
#include <stdio.h>

#define STATE_LEN 8 /* In words */
#define BLOCK_LEN 128 /* In bytes */
#define LENGTH_SIZE 16  // In bytes
#define ROTR64(x, n)  (((0U + (x)) << (64 - (n))) | ((x) >> (n)))  // Assumes that x is uint64_t and 0 < n < 64
#define LOADSCHEDULE(i)                                 \
  schedule[i] = (uint64_t)block[i * 8 + 0] << 56        \
    | (uint64_t)block[i * 8 + 1] << 48                  \
    | (uint64_t)block[i * 8 + 2] << 40                  \
    | (uint64_t)block[i * 8 + 3] << 32                  \
    | (uint64_t)block[i * 8 + 4] << 24                  \
    | (uint64_t)block[i * 8 + 5] << 16                  \
    | (uint64_t)block[i * 8 + 6] <<  8                  \
    | (uint64_t)block[i * 8 + 7] <<  0;
        
#define SCHEDULE(i)                                                     \
  schedule[i] = 0U + schedule[i - 16] + schedule[i - 7]                 \
    + (ROTR64(schedule[i - 15], 1) ^ ROTR64(schedule[i - 15], 8) ^ (schedule[i - 15] >> 7)) \
    + (ROTR64(schedule[i - 2], 19) ^ ROTR64(schedule[i - 2], 61) ^ (schedule[i - 2] >> 6));
        
#define ROUND(a, b, c, d, e, f, g, h, i, k)                             \
  h = 0U + h + (ROTR64(e, 14) ^ ROTR64(e, 18) ^ ROTR64(e, 41)) + (g ^ (e & (f ^ g))) + UINT64_C(k) + schedule[i]; \
  d = 0U + d + h;                                                       \
  h = 0U + h + (ROTR64(a, 28) ^ ROTR64(a, 34) ^ ROTR64(a, 39)) + ((a & (b | c)) | (b & c));

/* Hashes the message of length len and places the hash into hash */
void sha512_hash(const uint8_t message[], size_t len, uint64_t hash[static STATE_LEN]);
```

## `sha512.c`

Small SHA512 implementation taken from the web.  No bugs here (for the
purposes of the lab).

```c
/* 
 * SHA-512 hash in C
 * 
 * Copyright (c) 2017 Project Nayuki. (MIT License)
 * https://www.nayuki.io/page/fast-sha2-hashes-in-x86-assembly
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * - The above copyright notice and this permission notice shall be included in
 *   all copies or substantial portions of the Software.
 * - The Software is provided "as is", without warranty of any kind, express or
 *   implied, including but not limited to the warranties of merchantability,
 *   fitness for a particular purpose and noninfringement. In no event shall the
 *   authors or copyright holders be liable for any claim, damages or other
 *   liability, whether in an action of contract, tort or otherwise, arising from,
 *   out of or in connection with the Software or the use or other dealings in the
 *   Software.
 */

#include <string.h>
#include "sha512.h"

void sha512_compress(uint64_t state[static 8], const uint8_t block[static 128]);

void sha512_hash(const uint8_t message[], size_t len, uint64_t hash[static STATE_LEN]) {
  hash[0] = UINT64_C(0x6A09E667F3BCC908);
  hash[1] = UINT64_C(0xBB67AE8584CAA73B);
  hash[2] = UINT64_C(0x3C6EF372FE94F82B);
  hash[3] = UINT64_C(0xA54FF53A5F1D36F1);
  hash[4] = UINT64_C(0x510E527FADE682D1);
  hash[5] = UINT64_C(0x9B05688C2B3E6C1F);
  hash[6] = UINT64_C(0x1F83D9ABFB41BD6B);
  hash[7] = UINT64_C(0x5BE0CD19137E2179);
   
  size_t off;
  for (off = 0; len - off >= BLOCK_LEN; off += BLOCK_LEN)
    sha512_compress(hash, &message[off]);
    
  uint8_t block[BLOCK_LEN] = {0};
  size_t rem = len - off;
  memcpy(block, &message[off], rem);
    
  block[rem] = 0x80;
  rem++;
  if (BLOCK_LEN - rem < LENGTH_SIZE) {
    sha512_compress(hash, block);
    memset(block, 0, sizeof(block));
  }
    
  block[BLOCK_LEN - 1] = (uint8_t)((len & 0x1FU) << 3);
  len >>= 5;
  for (int i = 1; i < LENGTH_SIZE; i++, len >>= 8)
    block[BLOCK_LEN - 1 - i] = (uint8_t)(len & 0xFFU);
  sha512_compress(hash, block);
}

void sha512_compress(uint64_t state[static 8], const uint8_t block[static 128]) {
        
  uint64_t schedule[80];
  LOADSCHEDULE( 0)
    LOADSCHEDULE( 1)
    LOADSCHEDULE( 2)
    LOADSCHEDULE( 3)
    LOADSCHEDULE( 4)
    LOADSCHEDULE( 5)
    LOADSCHEDULE( 6)
    LOADSCHEDULE( 7)
    LOADSCHEDULE( 8)
    LOADSCHEDULE( 9)
    LOADSCHEDULE(10)
    LOADSCHEDULE(11)
    LOADSCHEDULE(12)
    LOADSCHEDULE(13)
    LOADSCHEDULE(14)
    LOADSCHEDULE(15)
    SCHEDULE(16)
    SCHEDULE(17)
    SCHEDULE(18)
    SCHEDULE(19)
    SCHEDULE(20)
    SCHEDULE(21)
    SCHEDULE(22)
    SCHEDULE(23)
    SCHEDULE(24)
    SCHEDULE(25)
    SCHEDULE(26)
    SCHEDULE(27)
    SCHEDULE(28)
    SCHEDULE(29)
    SCHEDULE(30)
    SCHEDULE(31)
    SCHEDULE(32)
    SCHEDULE(33)
    SCHEDULE(34)
    SCHEDULE(35)
    SCHEDULE(36)
    SCHEDULE(37)
    SCHEDULE(38)
    SCHEDULE(39)
    SCHEDULE(40)
    SCHEDULE(41)
    SCHEDULE(42)
    SCHEDULE(43)
    SCHEDULE(44)
    SCHEDULE(45)
    SCHEDULE(46)
    SCHEDULE(47)
    SCHEDULE(48)
    SCHEDULE(49)
    SCHEDULE(50)
    SCHEDULE(51)
    SCHEDULE(52)
    SCHEDULE(53)
    SCHEDULE(54)
    SCHEDULE(55)
    SCHEDULE(56)
    SCHEDULE(57)
    SCHEDULE(58)
    SCHEDULE(59)
    SCHEDULE(60)
    SCHEDULE(61)
    SCHEDULE(62)
    SCHEDULE(63)
    SCHEDULE(64)
    SCHEDULE(65)
    SCHEDULE(66)
    SCHEDULE(67)
    SCHEDULE(68)
    SCHEDULE(69)
    SCHEDULE(70)
    SCHEDULE(71)
    SCHEDULE(72)
    SCHEDULE(73)
    SCHEDULE(74)
    SCHEDULE(75)
    SCHEDULE(76)
    SCHEDULE(77)
    SCHEDULE(78)
    SCHEDULE(79)
        
    uint64_t a = state[0];
  uint64_t b = state[1];
  uint64_t c = state[2];
  uint64_t d = state[3];
  uint64_t e = state[4];
  uint64_t f = state[5];
  uint64_t g = state[6];
  uint64_t h = state[7];
  ROUND(a, b, c, d, e, f, g, h,  0, 0x428A2F98D728AE22)
    ROUND(h, a, b, c, d, e, f, g,  1, 0x7137449123EF65CD)
    ROUND(g, h, a, b, c, d, e, f,  2, 0xB5C0FBCFEC4D3B2F)
    ROUND(f, g, h, a, b, c, d, e,  3, 0xE9B5DBA58189DBBC)
    ROUND(e, f, g, h, a, b, c, d,  4, 0x3956C25BF348B538)
    ROUND(d, e, f, g, h, a, b, c,  5, 0x59F111F1B605D019)
    ROUND(c, d, e, f, g, h, a, b,  6, 0x923F82A4AF194F9B)
    ROUND(b, c, d, e, f, g, h, a,  7, 0xAB1C5ED5DA6D8118)
    ROUND(a, b, c, d, e, f, g, h,  8, 0xD807AA98A3030242)
    ROUND(h, a, b, c, d, e, f, g,  9, 0x12835B0145706FBE)
    ROUND(g, h, a, b, c, d, e, f, 10, 0x243185BE4EE4B28C)
    ROUND(f, g, h, a, b, c, d, e, 11, 0x550C7DC3D5FFB4E2)
    ROUND(e, f, g, h, a, b, c, d, 12, 0x72BE5D74F27B896F)
    ROUND(d, e, f, g, h, a, b, c, 13, 0x80DEB1FE3B1696B1)
    ROUND(c, d, e, f, g, h, a, b, 14, 0x9BDC06A725C71235)
    ROUND(b, c, d, e, f, g, h, a, 15, 0xC19BF174CF692694)
    ROUND(a, b, c, d, e, f, g, h, 16, 0xE49B69C19EF14AD2)
    ROUND(h, a, b, c, d, e, f, g, 17, 0xEFBE4786384F25E3)
    ROUND(g, h, a, b, c, d, e, f, 18, 0x0FC19DC68B8CD5B5)
    ROUND(f, g, h, a, b, c, d, e, 19, 0x240CA1CC77AC9C65)
    ROUND(e, f, g, h, a, b, c, d, 20, 0x2DE92C6F592B0275)
    ROUND(d, e, f, g, h, a, b, c, 21, 0x4A7484AA6EA6E483)
    ROUND(c, d, e, f, g, h, a, b, 22, 0x5CB0A9DCBD41FBD4)
    ROUND(b, c, d, e, f, g, h, a, 23, 0x76F988DA831153B5)
    ROUND(a, b, c, d, e, f, g, h, 24, 0x983E5152EE66DFAB)
    ROUND(h, a, b, c, d, e, f, g, 25, 0xA831C66D2DB43210)
    ROUND(g, h, a, b, c, d, e, f, 26, 0xB00327C898FB213F)
    ROUND(f, g, h, a, b, c, d, e, 27, 0xBF597FC7BEEF0EE4)
    ROUND(e, f, g, h, a, b, c, d, 28, 0xC6E00BF33DA88FC2)
    ROUND(d, e, f, g, h, a, b, c, 29, 0xD5A79147930AA725)
    ROUND(c, d, e, f, g, h, a, b, 30, 0x06CA6351E003826F)
    ROUND(b, c, d, e, f, g, h, a, 31, 0x142929670A0E6E70)
    ROUND(a, b, c, d, e, f, g, h, 32, 0x27B70A8546D22FFC)
    ROUND(h, a, b, c, d, e, f, g, 33, 0x2E1B21385C26C926)
    ROUND(g, h, a, b, c, d, e, f, 34, 0x4D2C6DFC5AC42AED)
    ROUND(f, g, h, a, b, c, d, e, 35, 0x53380D139D95B3DF)
    ROUND(e, f, g, h, a, b, c, d, 36, 0x650A73548BAF63DE)
    ROUND(d, e, f, g, h, a, b, c, 37, 0x766A0ABB3C77B2A8)
    ROUND(c, d, e, f, g, h, a, b, 38, 0x81C2C92E47EDAEE6)
    ROUND(b, c, d, e, f, g, h, a, 39, 0x92722C851482353B)
    ROUND(a, b, c, d, e, f, g, h, 40, 0xA2BFE8A14CF10364)
    ROUND(h, a, b, c, d, e, f, g, 41, 0xA81A664BBC423001)
    ROUND(g, h, a, b, c, d, e, f, 42, 0xC24B8B70D0F89791)
    ROUND(f, g, h, a, b, c, d, e, 43, 0xC76C51A30654BE30)
    ROUND(e, f, g, h, a, b, c, d, 44, 0xD192E819D6EF5218)
    ROUND(d, e, f, g, h, a, b, c, 45, 0xD69906245565A910)
    ROUND(c, d, e, f, g, h, a, b, 46, 0xF40E35855771202A)
    ROUND(b, c, d, e, f, g, h, a, 47, 0x106AA07032BBD1B8)
    ROUND(a, b, c, d, e, f, g, h, 48, 0x19A4C116B8D2D0C8)
    ROUND(h, a, b, c, d, e, f, g, 49, 0x1E376C085141AB53)
    ROUND(g, h, a, b, c, d, e, f, 50, 0x2748774CDF8EEB99)
    ROUND(f, g, h, a, b, c, d, e, 51, 0x34B0BCB5E19B48A8)
    ROUND(e, f, g, h, a, b, c, d, 52, 0x391C0CB3C5C95A63)
    ROUND(d, e, f, g, h, a, b, c, 53, 0x4ED8AA4AE3418ACB)
    ROUND(c, d, e, f, g, h, a, b, 54, 0x5B9CCA4F7763E373)
    ROUND(b, c, d, e, f, g, h, a, 55, 0x682E6FF3D6B2B8A3)
    ROUND(a, b, c, d, e, f, g, h, 56, 0x748F82EE5DEFB2FC)
    ROUND(h, a, b, c, d, e, f, g, 57, 0x78A5636F43172F60)
    ROUND(g, h, a, b, c, d, e, f, 58, 0x84C87814A1F0AB72)
    ROUND(f, g, h, a, b, c, d, e, 59, 0x8CC702081A6439EC)
    ROUND(e, f, g, h, a, b, c, d, 60, 0x90BEFFFA23631E28)
    ROUND(d, e, f, g, h, a, b, c, 61, 0xA4506CEBDE82BDE9)
    ROUND(c, d, e, f, g, h, a, b, 62, 0xBEF9A3F7B2C67915)
    ROUND(b, c, d, e, f, g, h, a, 63, 0xC67178F2E372532B)
    ROUND(a, b, c, d, e, f, g, h, 64, 0xCA273ECEEA26619C)
    ROUND(h, a, b, c, d, e, f, g, 65, 0xD186B8C721C0C207)
    ROUND(g, h, a, b, c, d, e, f, 66, 0xEADA7DD6CDE0EB1E)
    ROUND(f, g, h, a, b, c, d, e, 67, 0xF57D4F7FEE6ED178)
    ROUND(e, f, g, h, a, b, c, d, 68, 0x06F067AA72176FBA)
    ROUND(d, e, f, g, h, a, b, c, 69, 0x0A637DC5A2C898A6)
    ROUND(c, d, e, f, g, h, a, b, 70, 0x113F9804BEF90DAE)
    ROUND(b, c, d, e, f, g, h, a, 71, 0x1B710B35131C471B)
    ROUND(a, b, c, d, e, f, g, h, 72, 0x28DB77F523047D84)
    ROUND(h, a, b, c, d, e, f, g, 73, 0x32CAAB7B40C72493)
    ROUND(g, h, a, b, c, d, e, f, 74, 0x3C9EBE0A15C9BEBC)
    ROUND(f, g, h, a, b, c, d, e, 75, 0x431D67C49C100D4C)
    ROUND(e, f, g, h, a, b, c, d, 76, 0x4CC5D4BECB3E42B6)
    ROUND(d, e, f, g, h, a, b, c, 77, 0x597F299CFC657E2A)
    ROUND(c, d, e, f, g, h, a, b, 78, 0x5FCB6FAB3AD6FAEC)
    ROUND(b, c, d, e, f, g, h, a, 79, 0x6C44198C4A475817)
    state[0] = 0U + state[0] + a;
  state[1] = 0U + state[1] + b;
  state[2] = 0U + state[2] + c;
  state[3] = 0U + state[3] + d;
  state[4] = 0U + state[4] + e;
  state[5] = 0U + state[5] + f;
  state[6] = 0U + state[6] + g;
  state[7] = 0U + state[7] + h;
}
```

