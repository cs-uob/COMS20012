# Exercises sheet 2

## Intro to Cryptography 

1. What are the two basic functions used in encryption algorithms?
2. How many keys are required for two people to communicate via a cipher?
3. What is the difference between a block cipher and a stream cipher?
4. What are the two general approaches to attacking a cipher?
5. What is a trap-door one-way function?
6. What requirements must a public-key cryptosystems fulfill to be a secure algorithm?
7. What is the difference between a message authentication code and a one-way hash function?


## Answers
- **ANS A.1:** Permutation and substitution. 
- **ANS A.2:** One key for symmetric ciphers, two keys for asymmetric ciphers.
- **ANS A.3:** A stream cipher is one that encrypts a digital data stream one bit or one byte at a time. A block cipher is one in which a block of plaintext is treated as a whole and used to produce a ciphertext block of equal length.
- **ANS A.4:** Cryptanalysis and brute force.
- **ANS A.5:** A trap-door one-way function is easy to calculate in one direction and infeasible to calculate in the other direction unless certain additional information is known. With the additional information the inverse can be calculated in polynomial time.
- **ANS A.6:** It is computationally easy for a party B to generate a pair (public key PUb, private key PRb). It is computationally easy for a sender A, knowing the public key and the message to be encrypted, M, to generate the corresponding ciphertext: C = E(PUb, M). It is computationally easy for the receiver B to decrypt the resulting ciphertext using the private key to recover the original message: M = D(PRb, C) = D(PRb, E(PUb, M)). It is computationally infeasible for an opponent, knowing the public key, PUb, to determine the private key, PRb. It is computationally infeasible for an opponent, knowing the public key, PUb, and a ciphertext, C, to recover the original message, M. 
- **ANS A.7:** A hash function, by itself, does not provide message authentication. A secret key must be used in some fashion with the hash function to produce authentication. A MAC, by definition, uses a secret key to calculate a code used for authentication.


## Intro to Networking 

1. What is the difference between ISO/OSI model and TCP/IP model? Elaborate!
2. Explain difference between Physical Links, Data Links, and Routes!
3. Which is a security attack at layer 1 of the OSI model?
4. What is a replay attack?
5. Suppose that the current replay window spans from 120 to 530.
a. If the next incoming authenticated packet has sequence number 105, what will the receiver do with the packet, and what will be the parameters of the window after that?
b. If instead the next incoming authenticated packet has sequence number 440, what will the receiver do with the packet, and what will be the parameters of the window after that?
c. If instead the next incoming authenticated packet has sequence number 540, what will the receiver do with the packet, and what will be the parameters of the window after that?

## Answers
- **ANS A.1:** OSI model is a generic model that is based upon functionalities of each layer. TCP/IP model is a protocol-oriented standard.
OSI model distinguishes the three concepts, namely, services, interfaces, and protocols. TCP/IP does not have a clear distinction between these three.
OSI model gives guidelines on how communication needs to be done, while TCP/IP protocols layout standards on which the Internet was developed. So, TCP/IP is a more practical model. In OSI, the model was developed first and then the protocols in each layer were developed. In the TCP/IP suite, the protocols were developed first and then the model was developed. The OSI has seven layers while the TCP/IP has four layers.
- **ANS A.2:** At the physical layer, a link between a host and a switch or between switches is called a physical link. A single path a frame takes across a single network is called a data link. A single path a packet takes across an internet is called a route.
- **ANS A.3:** Layer 1 refers to the physical aspect of networking disrupting this service, primarily resulting in Denial of Service (DoS) attacks. Network vulnerabilities/threats which occur at this level are the following: 1)Access Control 2)Damage data bits 3)Environmental issues 4)Disconnection of Physical Links.
- **ANS A.4:** A replay attack is one in which an attacker obtains a copy of an authenticated packet and later transmits it to the intended destination. The receipt of duplicate, authenticated IP packets may disrupt service in some way or may have some other undesired consequence. Simple replay: The opponent simply copies a message and replays it later. Repetition that can be logged: An opponent can replay a timestamped message within the valid time window. Repetition that cannot be detected: This situation could arise because the original message could have been suppressed and thus did not arrive at its destination; only the replay message arrives. Backward replay without modification: This is a replay back to the message sender. This attack is possible if symmetric encryption is used and the sender cannot easily recognize the difference between messages sent and messages received on the basis of content.
- **ANS A.5:** a) The received packet is to the left of the window, so the packet is discarded; this is an auditable event. No change is made to window parameters. b) The received packet falls within the window. If it is new, the MAC is checked. If the packet is authenticated, the corresponding slot in the window is marked. If it is not new, the packet is discarded. In either case, no change is made to window parameters. c) The received packet is to the right of the window and is new, so the MAC is checked. If the packet is authenticated, the window is advanced so that this sequence number is the right edge of the window, and the corresponding slot in the window is marked. In this case, the window now spans from 120 to 540.

