# Exercises sheet 1

## A. Intro to CIA/AAA/Threat/Security Principles
1. Let us assume tha mayor of Bristol wants to release a public notice on an important issue. Which of the CIA properties should be enforced and why?

	**ANS:** Integrity and Availability. **I** because noone should be able to alter it in unintended way and **A** because it should be available to the public to see.
2. Explain why someone need not worry about being a victim of a social engineering attack through their cell phone if they are inside of a Faraday cage.

	**ANS:** becuase there will be no signal to get connected to the site if that was the intention of the attacker.
3. With respect to the C.I.A. and A.A.A. concepts, what risks are posed by Trojan horses?

	**ANS:** a trojan horse can violate all of the CIA, by leaking info,modifying files, and deleting files. For AAA, it can sabotage authenticity (by design).
4. With respect to the C.I.A. and A.A.A. concepts, what risks are posed by someone making so many download requests from an online music store that it prevents other users from being able to download any songs?

	**ANS:** CIA- availability, AAA- assurance.
5. Give an example of the false sense of security that can come from using the “security by obscurity” approach.

	**ANS:** using a encryption scheme that is not public, thinking that no one will break it if they don't know about. Anothe example is hard coded secrets in the binary thinking that no one will know about them.
6. The HF Corporation has a new refrigerator, the Monitator, which has a camera that takes a picture of the contents of the refrigerator and uploads it to the HF Corporation’s web site. The Monitator’s owner can then access this web site to see what is inside their refrigerator without opening the door. For security reasons, the HF Corporation encrypts this picture using a proprietary algorithm and gives the 4-digit PIN to decrypt this picture to the Monitator’s owner, so he or she can get access to the pictures of their Monitator’s interior. What are the security concerns and principles that this solution does and doesn’t support?

	**ANS:** It is simple desigin, thus *economy of mechanism* prnciple is followed. However, proprietary encryption shceme is a bad idea (*Open design* principle). Protecting it with a PIN is good (confidentiality and Assurance). However, 4-digit PIN may be a weak protection.
7. Suppose an Internet service provider (ISP) has a voice over IP (VoIP) telephone system that it manages and sells. Suppose further that this ISP is deliberately dropping 25% of the packets used in its competitors VoIP system when those packets are going through this ISP’s routers. Describe how a user could discover that his ISP is doing this.

	**ANS:** Using a recorded message, play it on VoIP when calling your friend from *this* ISP and repeat the same activity, but from a different provider and measure the difference between received packets in both of the cases.

## B. Intro to Assembly

1. What is WYSINWYX and how it is related to software security?

	**ANS:** *what you see is not what you execute* is related to transformation of the code written in a higher level language to a lower-level code, like assembly that is actually exeuted by a cpu. For memory unsafe languages, this issue is the center for many low-level memory corruption bugs.
2. What are memory corruption bugs and what causes them?

	**ANS:** see above and memory unsafe language slides.
3. Can you find one instance where a weakness (not the vulnerability) poses violation to CIA?

	**ANS:** Availability issues as a result of a crash, e.g. division by zero or assertion failure.
4. For a x86-32 ISA, what are `cdecl` and `fastcall` calling conventions?

	**ANS:** see slides.
5. For Intel x86 ISA, consider a function **A** calls another function **B**. We denote base/frame point RBP of **A** (resp. of **B**) as RBP<sub>A</sub> (resp. as RBP<sub>B</sub>). Which of the following holds and why:
	RBP<sub>A</sub> > RBP<sub>B</sub>; RBP<sub>A</sub> < RBP<sub>B</sub>; RBP<sub>A</sub> = RBP<sub>B</sub>.

	**ANS:** RBP<sub>A</sub> > RBP<sub>B</sub>. stack growns higher to lower addresses.
6. What  is a *saved return address* and why is it used?

	**ANS:** see slides on assembly.
7. Which general purpose register is used for return value?

	**ANS:** EAX/RAX. see slides for more info.
8. Consider the following C code:

		#include <stdio.h>
		int sum(int a, int b)
		{
		    return a+b;
		}

		void main()
		{
		    int n1,n2,n3,n4,x,y, a,b;
		    char some[]="Something";
		    n1 = 10;
		    a = 10;
		    n3 = 10;
		    char some1[]="Something";
		    n2 = 10;
		    b = 10;
		    n4=10;
		    x=sum(n3,n4);
		    y=sum(n1,n2);
		    printf("Sum are: %d and %d", x,y);
		}
And its disassembly as follows:

		000000000000065e <main>:
		 65e:	55                   	push   %rbp
		 65f:	48 89 e5             	mov    %rsp,%rbp
		 662:	48 83 ec 40          	sub    $0x40,%rsp
		 666:	48 b8 53 6f 6d 65 74 	movabs $0x6e696874656d6f53,%rax
		 66d:	68 69 6e
		 670:	48 89 45 d6          	mov    %rax,-0x2a(%rbp)
		 674:	66 c7 45 de 67 00    	movw   $0x67,-0x22(%rbp)
		 67a:	c7 45 fc 0a 00 00 00 	movl   $0xa,-0x4(%rbp)
		 681:	c7 45 f8 0a 00 00 00 	movl   $0xa,-0x8(%rbp)
		 688:	c7 45 f4 0a 00 00 00 	movl   $0xa,-0xc(%rbp)
		 68f:	48 89 45 cc          	mov    %rax,-0x34(%rbp)
		 693:	66 c7 45 d4 67 00    	movw   $0x67,-0x2c(%rbp)
		 699:	c7 45 f0 0a 00 00 00 	movl   $0xa,-0x10(%rbp)
		 6a0:	c7 45 ec 0a 00 00 00 	movl   $0xa,-0x14(%rbp)
		 6a7:	c7 45 e8 0a 00 00 00 	movl   $0xa,-0x18(%rbp)
		 6ae:	8b 55 e8             	mov    -0x18(%rbp),%edx
		 6b1:	8b 45 f4             	mov    -0xc(%rbp),%eax
		 6b4:	89 d6                	mov    %edx,%esi
		 6b6:	89 c7                	mov    %eax,%edi
		 6b8:	e8 8d ff ff ff       	callq  64a <sum>
		 6bd:	89 45 e4             	mov    %eax,-0x1c(%rbp)
		 6c0:	8b 55 f0             	mov    -0x10(%rbp),%edx
		 6c3:	8b 45 fc             	mov    -0x4(%rbp),%eax
		 6c6:	89 d6                	mov    %edx,%esi
		 6c8:	89 c7                	mov    %eax,%edi
		 6ca:	e8 7b ff ff ff       	callq  64a <sum>
		 6cf:	89 45 e0             	mov    %eax,-0x20(%rbp)
		 6d2:	8b 55 e0             	mov    -0x20(%rbp),%edx
		 6d5:	8b 45 e4             	mov    -0x1c(%rbp),%eax
		 6d8:	89 c6                	mov    %eax,%esi
		 6da:	48 8d 3d 93 00 00 00 	lea    0x93(%rip),%rdi        # 774 <_IO_stdin_used+0x4>
		 6e1:	b8 00 00 00 00       	mov    $0x0,%eax
		 6e6:	e8 35 fe ff ff       	callq  520 <printf@plt>
		 6eb:	90                   	nop
		 6ec:	c9                   	leaveq
		 6ed:	c3                   	retq   
		 6ee:	66 90                	xchg   %ax,%ax

a. Can you identify in the assembly which memory locations (of the form `-0xN(%ebp)`) correspond to which variables in the main function?

**ANS:** `n1=-0x4(%rbp)`; `n2= -0x10(%rbp)`, `n3=-0xc(%rbp)`; `n4=-0x18(%rbp)`; `x=-0x1c(%rbp)`; `y=-0x20(%rbp)`; `a =-0x8(%rbp)` or `-0x14(%rbp)`; `b = -0x14(%rbp)` or `-0x8(%rbp)`

b. . In the C code above, if you compile the code for x86-32 system, at the line `x=sum(n3,n4);`which argument will be pushed onto the stack first?

**ANS:** `n4`.
