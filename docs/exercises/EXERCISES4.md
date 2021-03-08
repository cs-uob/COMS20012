# Exercises sheet 4

**There will be no written corrections. Exercises will be discussed during the recorded live Q&A. Come and prepare questions.**

## Authentication Methods

1. Explain in your own words what:
* authentication means;
* authorization means;
* accountability means.

    **ANS:** authentication: verifying the identify of a user; authorization: verifying the privileges of an identified user; accountability: keeping track of the actions/accesses made by a user.

2. Pick on of your favourite online services (Google, Twitter, Facebook etc.)
Check and discuss their recovery mechanism.

    **ANS:** for twitter you can check [here](https://help.twitter.com/en/managing-your-account/forgotten-or-lost-password-reset){:target="_blank"}.

3. Research on Goolge why SMS recovery is not suitable anymore to protect against targeted attack.
A general audience article from Forbes can be found [here](https://www.forbes.com/sites/zakdoffman/2020/10/11/apple-iphone-imessage-and-android-messages-sms-passcode-security-update/){:target="_blank"}.

    **ANS:** it is possible to launch some form of *targeted* attack against SMS password recovery mechanisms.

4. Building on [Bonneau et al. S&P paper](../materials/lecture4/2012-sp.pdf){:target="_blank"} provided as lecture material. Discuss why it is difficult to replace passwords.

5. Building on [Bonneau et al. S&P paper](../materials/lecture4/2012-sp.pdf){:target="_blank"} and [Cheon et al. S&P paper](../materials/lecture4/2020-sp.pdf){:target="_blank"} suggest a (simple) framework to compare authentication via pin code and gesture on smartphone.
**Discuss your frameworks within your lab groups**.
You should agree on a lab-group level framework, **be ready to discuss your frameworks during Friday Q&A**.

    **ANS:** To be discussed in Q&A.

## Network Security

1. Can two network interfaces have the same MAC address? Why or why not?

	**ANS:** If they are in the same subnet, no as this will cause confusion, which results in the disruption of the network services. On the different subnet, this *may* not cause a problem as the network level router/switch will fisrt route the packet to the subnet and only then a ARP request will be made for the final recipent of the packet.

2. Discuss why installing static ARP tables on the machines of a local-area network does not prevent a malicious machine from intercept-ing traffic not intended for it.

	**ANS:** By changing the MAC to that on the victim, an attcker can still intercept the packets. This can also be acheved by puting the machine in promiscuous mode. See [this](https://en.wikipedia.org/wiki/Promiscuous_mode)

3. TCP connections require a lot of overhead, as compared to UDP. Explain why web sites and file transfers are nevertheless typically transmitted over TCP instead of UDP.

	**ANS:** TCP is more reliable than UDP. If you expect large data exchange, using TCP makes more sense as such data need to be sent over several packets. In the case of UDP, it may be hcallenging to keep track of which packets have arrived/acknowledged.

4. How is it that a machine of a private network behind a NAT router can make a connection with a web server on the public Internet?

	**ANS:** See slides on NAT/PAT. basically, NAT changes the private IP into a public IP before sending it to the public network.

5. Suppose you suspect that your session with a server has been intercepted in a man-in-the-middle attack. You have a key, K, that you think you share with the server, but you might be only sharing it with an attacker. But the server also has a public key, K<sub>P</sub>, which is widely known, and a private secret key, K<sub>S</sub>, that goes with it. Describe how you can either confirm you share K with the server or discover that you share it only with a man-in-the-middle. Also, be sure your solution will not be discovered by a packet sniffer.

	**ANS:** Send the server a message by encrypting it with `K`-- Can you sign the secret `K` with your private key? As this is encrypted, no one will be able to read this. When server sends the response,you can verify this by using its public key, if the signature is valid. Clearly, only the real server that produce a valid signature.

6. Explain how a stateless firewall would block all incoming and outgoing HTTP requests.

	**ANS:** The firewall can block packets where the destination port is 80.  For the incoming HTTP traffic (i.e. packets related to a requests, the firwall can block packets where the source port is 80. this case should not arise as all the requests are blocked already!).

7. Explain how a port scan might be a preliminary indication that another attack is on its way.

	**ANS:** in the real-world, attacks are multi-stage activities. An attacker needs to know which ports are open to know what kind of services and thus applications are accessible from the outside. Port scanning is one such activities to know which applications to target.

8. Describe the types of rules that would be needed for a rule-based intrusion detection system to detect an ARP spoofing attack.

	**ANS:** An ARP reply for which no ARP request was made in a given time interval. ARP responses where there are two identical MAC with different IPs.

9. During TLS enabled connection, why do we use DH key exchange for sharing a session key, given the fact that we use a public-key crypto systems that can be used to share the session key?

	**ANS:** see slides on forward secrecy and ephimeral keys.
