# Revision Sheet:

Please note that the exercises are in a random order. You can find the answers after the last question.

---

### Question 1
With respect to CIA and AAA concepts, what risks are posed by Trojan horses?

- a. They only violate Availability
- b. They only pose risks to Confidentiality
- c. They violate Confidentiality and Integrity, but not Availability or AAA
- d. They can violate all CIA properties and compromise Authenticity in AAA

---

### Question 2
Which of the following best illustrates a false sense of security from "security by obscurity"?

- a. Using a well-known, peer-reviewed encryption algorithm
- b. Using a proprietary encryption scheme, assuming no one will break it if they don't know how it works
- c. Storing passwords in a salted hash
- d. Enabling two-factor authentication on all accounts

---

### Question 3
The HF Corporation's Monitator refrigerator encrypts photos with a proprietary algorithm and a 4-digit PIN. Which statement **best** describes the security of this design?

- a. It follows all security principles correctly
- b. It is secure because proprietary algorithms are harder to break
- c. Economy of mechanism is followed, but open design and key-strength principles are violated
- d. It provides no security at all


### Question 4
What are the two basic functions used in encryption algorithms?

- a. Hashing and encoding
- b. Diffusion and confusion
- c. Permutation and substitution
- d. Compression and expansion

---

### Question 5
What is the key difference between a Message Authentication Code (MAC) and a one-way hash function?

- a. A hash function always uses a secret key; a MAC does not
- b. A MAC produces a longer output than a hash function
- c. A hash function alone does not provide authentication; a MAC uses a secret key to produce a code specifically for authentication
- d. There is no difference — both achieve the same security goals

---

### Question 6
The current replay window spans from 120 to 530. An incoming authenticated packet has sequence number **105**. What does the receiver do?

- a. Discards the packet; it is to the left of the window. No change to window parameters
- b. Accepts the packet and marks the slot in the window
- c. Advances the window so 105 becomes the left edge
- d. Checks the MAC and, if valid, accepts the packet

---

### Question 7
What is DNS cache poisoning?

- a. An attack that overwhelms a DNS server with excessive requests, causing it to go offline
- b. An attack in which false information is entered into the DNS cache, redirecting users to malicious websites
- c. An attack that encrypts DNS records and demands a ransom for their release
- d. An attack that intercepts DNS queries and delays their responses

---

### Question 8
How does ARP spoofing facilitate a Man-in-the-Middle (MITM) attack?

- a. The attacker floods the network with ARP requests to crash the router
- b. The attacker intercepts DNS responses and substitutes malicious IP addresses
- c. The attacker sends forged ARP replies advertising their own MAC address for the IP addresses of two communicating devices, causing both devices to send traffic to the attacker instead of each other
- d. The attacker exploits an open port on the target to inject packets directly into the TCP stream

---

### Question 9
Where does IPsec reside in the protocol stack?

- a. Above the application layer
- b. At the application layer, alongside HTTP and FTP
- c. Below the transport layer (TCP/UDP), at the network/IP layer
- d. At the data link layer, below the IP layer

---

### Question 10
Which of the following is NOT a typical impact of a successful SQL injection attack?

- a. Unauthorised access to sensitive data such as passwords or credit card details
- b. Obtaining a persistent backdoor into an organisation's systems
- c. Encrypting the target database and demanding a ransom
- d. Subverting application logic by manipulating database queries

---

### Question 11
What is **Stored XSS**?

- a. An XSS attack where the malicious script comes from the current HTTP request
- b. An XSS attack where the malicious script is persistently stored in the website's database and served to other users
- c. An XSS attack that exploits vulnerabilities in client-side JavaScript
- d. An XSS attack that targets server-side rendering engines only

---

### Question 12
What are two common techniques used to protect a password file?

- a. Storing passwords in plaintext and restricting file permissions to root only
- b. Encoding passwords in Base64 and placing the file on a separate server
- c. One-way hashing of stored passwords, and strict access control limiting which accounts can read the password file
- d. Symmetric encryption of the entire file and daily rotation of the encryption key

---

### Question 13
Choose the correct answer: 
 
a.	A Memory-mapping Unit associates virtual address with base and bound register 
b.	A Memory-mapping Unit translates virtual addresses to physical addresses 
c.	A Memory-mapping Unit can be configurable by a user process 
d.	A Memory-mapping Unit provides a virtual memory for each process 
e.	None of the above 

---


### Question 14
What is a spatial safety violation: 
 
a.	An error in the kernel execution leading to data safety violation. 
b.	An error in associating a virtual address with a physical address. 
c.	An error in which a pointer is used to access an object that has already been deallocated. 
d.	An error in which a pointer is used to access the data at a location in memory that is outside the bounds of an allocated object. 
e.	None of the above 
 
---

### Question 15
Choose the False answer:
a.	TLS has been deprecated by Internet Engineering Task Force and replaced by SSL
b.	In  TLS, the data protection phase is implemented by the sub-protocol TLS application data protocol
c.	Compared to SSL 3.0, TLS 1.0 uses HMAC
d.	TLS is used to Establish a Virtual Private Network 
e.	None of the above 

---

### Question 16
Which of the following is correct: 
a)	When division by zero occurs, interrupt is triggered.
b)	Interrupt do not invoke the kernel
c)	System call does not allow to interact with the kernel
d)	When division by zero occurs, trap is triggered.
e)	None of the above

---

### Question 17
Choose the False answer: 
a)	Operating system abstracts the hardware complexity
b)	Operating system is a computer program
c)	Operating system multiplexes hardware resources
d)	In OS, processes, threads are used to abstract the disk
e)	None of the above

---

### Question 18
IPSEC is the only solution to establish a VPN
a)	True
b)	False

---

### Question 19
SSL is recommended by the IETF
a)	False
b)	True 

---

### Question 20
Consider the following code:
void main(){
	int count=0;
	int x;
	char name[20];
	int y;
	int z;
	printf("Enter you name..");
	gets(name);
	printf("your name is: %s", name);
	return 0;
}
Assume that variables are allocated on the stack in the same order as they are declared in the code, i.e. x will be near rbp (ebp) and z wil be near rsp (esp).
Choose the correct answer:

a)	This is a format string 
b)	There is no memory error
c)	This is a memory error and the variables count, x, y and z are corrupted
d)	This is a memory error and the variables count and x are corrupted
e)	None of the above

---

### Question 21
To avoid buffer overflow, you should use safe functions such as fgets: 
a)	False 
b)	True


---

### Question 22
The following table is a memory management table, choose the correct table for LRU policy:
a)	Table 1
| Num    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
|--------|---|---|---|---|---|---|---|---|---|----|----|----|
|Ref	|a	|b	|c	|a	|b	|e	|d	|a	|e	|d	|b	|d|
PP1	a	a	a	a	a	a	d	d	d	d	d	d
PP2		b	b	b	b	b	b	a	a	a	b	b
PP3			c	c	c	e	e	e	e	e	e	e
Fault?	*	*	*	*	*	*	*	*			*	

b)	Table 2
| Num    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
|--------|---|---|---|---|---|---|---|---|---|----|----|----|
|Ref	|a	|b	|c	|a	|b	|e	|d	|a	|e	|d	|b	|d|
|PP1	|a	|a	|a	|a	|a	|e	|e	|e	|e	|e	|b	|b |
|PP2	|	|b	|b	|b	|b	|b	|d	|d	|d	|d	|d	| d|
|PP3	|	|	|c	|c	|c	|c	|c	|a	|a	|a	|a	| a|
|Fault?	|*	|*	|*	|	|	|*	|*	|*	|	|	|*	|  |

c)	Table 3


| Num    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
|--------|---|---|---|---|---|---|---|---|---|----|----|----|
| Ref    | a | b | c | a | b | e | d | a | e | d  | b  | d  |
| PP1    | a | a | a | a | a | a | d | d | d | d  | d  | d  |
| PP2    |   | b | b | b | b | b | b | a | a | a  | b  | b  |
| PP3    |   |   | c | c | c | e | e | e | e | e  | e  | e  |
| Fault? | * | * | * |   |   | * | * | * |   |    | *  |    |

d)	Table 4:
| Num    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
|--------|---|---|---|---|---|---|---|---|---|----|----|----|
|Ref	|a	|b	|c	|a	|b	|e	|d	|a	|e	|d	|b	|d|
|PP1	|a	|a	|a	|a	|a	|a	|d	|d	|d	|d	|d	|d|
|PP2	|	|b	|b	|b	|b	|e	|e	|a	|a	|a	|b	|b|
|PP3	|	|	|c	|c	|c	|c	|c	|c	|c|	c|	|c	|c|
|Fault?	|*	|*	|*	|	|	|*	|*	|*	||	|	|*|	||


e)	None of the above






## Answers

> **Question 1: d** — A Trojan horse can leak information (Confidentiality), modify files (Integrity), delete files (Availability), and sabotage authenticity (AAA). Unlike a simple virus, its hidden nature means it can simultaneously undermine all three CIA properties and AAA.

> **Question 2: b** — Relying on the *secrecy of the design* rather than the *strength of the mechanism* is the hallmark of security by obscurity. A robust system should remain secure even if its design is publicly known (Kerckhoffs's principle).

> **Question 3: c** — The simple, minimal design follows *economy of mechanism*, but using a proprietary (non-public) algorithm violates the *open design* principle (security should not depend on design secrecy), and a 4-digit PIN (only 10,000 possibilities) offers dangerously weak key strength.

> **Question 4: c** — Encryption algorithms are built on two fundamental operations: **permutation** (rearranging the positions of elements) and **substitution** (replacing elements with others). These underpin both classical and modern ciphers. Note that "diffusion and confusion" (option B) are Shannon's design *goals*, not the basic functions themselves.

> **Question 5: c** — A hash function alone produces a digest that anyone can compute; it cannot prove *who* created it. A MAC binds the digest to a secret key, meaning only parties who share the key can generate or verify it — providing both integrity and authentication.

> **Question 6: a** — Sequence number 105 falls to the **left** of the window's lower bound (120), meaning it is either a duplicate or an old replayed packet. The receiver discards it immediately without updating any window parameters. This event should be logged as a potential replay attempt.

> **Question 7: b** — In DNS cache poisoning (also called DNS spoofing), an attacker injects forged DNS records into a resolver's cache. Any user whose query hits that cache is silently redirected to a malicious server — leaving them vulnerable to phishing, malware, and data theft — without any visible warning.

> **Question 8: c** — ARP has no authentication mechanism, so any host can broadcast a forged reply. By poisoning the ARP caches of both the workstation and the router with their own MAC address, the attacker places themselves invisibly in the path of all traffic between the two devices. This is a Layer 2 attack that can bypass higher-layer encryption if TLS is not in use.

> **Question 9: c** — IPsec sits at the **network (IP) layer**, below TCP and UDP. This placement means it can secure all traffic transparently, regardless of the application protocol above it — unlike TLS, which must be explicitly implemented by each application. Note the contrast with SSL/TLS (transport–application boundary) and SSH (application layer).


> **Question 10: c** — Ransomware encryption is a distinct attack type separate from SQL injection. SQL injection works by manipulating database queries, which can result in data theft (A), persistent compromise via backdoors (B), and logic subversion (D) — but not direct file encryption, which requires a different class of malware.

> **Question 11: b** — Stored (or Persistent) XSS is particularly dangerous because the malicious script is saved in the server's database (e.g. via a comment or profile field) and automatically executed for *every* user who views the affected page — not just a single targeted victim. Compare with Reflected XSS (script comes from the URL, affects one user) and DOM-based XSS (never touches the server at all).

> **Question 12: c** — These two controls work in tandem: one-way hashing ensures that even if the file is stolen, passwords cannot be recovered directly; access control limits which accounts can attempt the theft in the first place. Note that Base64 (B) is encoding, not encryption, and provides zero security. Symmetric encryption (D) is reversible and still exposes passwords if the key is compromised.

> **Question 13: b** - A Memory-mapping Unit translates virtual addresses to physical addresses 

> **Question 14: d** - An error in which a pointer is used to access the data at a location in memory that is outside the bounds of an allocated object. 

> **Question 15: a** - TLS has been deprecated by Internet Engineering Task Force and replaced by SSL

> **Question 16: d** - When division by zero occurs, trap is triggered.

> **Question 17: e** - None of the above

> **Question 18: b** - False

> **Question 19: a** - False

> **Question 20: d** - This is a memory error and the variables count and x are corrupted

> **Question 21: b** - True

> **Question 22: c** - Table 3

