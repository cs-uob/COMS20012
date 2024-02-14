# Exercise sheet 3

## Network Security

1. Investigate the network access control scheme used at your school or place of employment (if you work somewhere). Draw a diagram and describe the principal components. **This question has an aim to make you investigate and there is no uniform answer. You are strongly encouraged to ask our guest lecturer about our University access control.**

2. Explain DNS cache poisoning.

3. What is SamSam malware? How deos it work? What are the famous ransomware attacks in the UK?

4. Should I use DoH or DoT? Convince me!

5. What is the purpose of HTTPS?

6. What is the goal of the TCP session hijacker? How can we prevent it? 

7. For what applications is SSH useful?

8. What is the difference between SYN Flooding Attack and TCP session hijacking? Can we prevent them? How? 

9. Where does IPsec reside in a protocol stack?

10. What is DHCP? How useful is it to help achieve security of IP addresses?

11. How does ARP Spoofing facilitate MITM attack?  

12. Is Wireless networking more susceptible to eavesdropping and jamming than wired networks? Elaborate! Why/why not?

13. What was the largest DDoS attack of all time? Is it still the largest? Investigate! What are other famous DDoS attack? Can you explain how they were performed?

14. In IEEE 802.11, open system authentication simply consists of two communications. An authentication is requested by the client, which contains the station ID (typically the MAC address). This is followed by an authentication response from the AP/router containing a success or failure message. An example of when a failure may occur is if the client’s MAC address is explicitly excluded in the AP/router configuration.
a. What are the benefits of this authentication scheme?
b. What are the security vulnerabilities of this authentication scheme?


## Answers
- **ANS A.1:** This question has an aim to make you investigate and there is no uniform answer.
- **ANS A.2:** In DNS cache poisoning or DNS spoofing, an attacker diverts traffic from a legitimate server to a malicious/dangerous server. The perpetrator enters false information -- such as a doctored website address -- into the DNS cache, which results in the redirection of users to a wrong, unexpected or dangerous website. DNS cache poisoning is a highly deceptive attack that not only diverts traffic from legitimate websites, but also leaves users vulnerable to many risks, including malware infections and data theft. 
- **ANS A.3:** SamSam ransomware, also known as MSIL/Samas.A. Specifically, this product shares analysis of vulnerabilities that cyber actors exploited to deploy this ransomware. The actors exploit Windows servers to gain persistent access to a victim’s network and infect all reachable hosts. According to reporting from victims in early 2016, cyber actors used the JexBoss Exploit Kit to access vulnerable JBoss applications. Since mid-2016, FBI analysis of victims’ machines indicates that cyber actors use Remote Desktop Protocol (RDP) to gain persistent access to victims’ networks. Typically, actors either use brute force attacks or stolen login credentials. Detecting RDP intrusions can be challenging because the malware enters through an approved access point. After gaining access to a particular network, the SamSam actors escalate privileges for administrator rights, drop malware onto the server, and run an executable file, all without victims’ action or authorization. While many ransomware campaigns rely on a victim completing an action, such as opening an email or visiting a compromised website, RDP allows cyber actors to infect victims with minimal detection.
- **ANS A.4:** From a network security standpoint, DoT is arguably better. It gives network administrators the ability to monitor and block DNS queries, which is important for identifying and stopping malicious traffic. DoH queries, meanwhile, are hidden in regular HTTPS traffic, meaning they cannot easily be blocked without blocking all other HTTPS traffic as well. However, from a privacy perspective, DoH is arguably preferable. With DoH, DNS queries are hidden within the larger flow of HTTPS traffic. This gives network administrators less visibility but provides users with more privacy.
- **ANS A.5:** Hypertext transfer protocol secure (HTTPS) is the secure version of HTTP, which is the primary protocol used to send data between a web browser and a website. HTTPS is encrypted in order to increase security of data transfer. HTTPS uses TLS (SSL) to encrypt normal HTTP requests and responses, making it safer and more secure.
- **ANS A.6:** A form of cyber attack in which an authorized user gains access to a legitimate connection of another client in the network. Having hijacked the TCP/IP session, the attacker can read and modify transmitted data packets, as well as send their own requests to the addressee. TCP/IP hijacking is a type of man-in-the-middle attack. The intruder can determine the IP addresses of the two session participants, make one of them inaccessible using a DoS attack, and connect to the other by spoofing the network ID of the former. The goal of the TCP session hijacker is to create a state where the client and server are unable to exchange data; enabling him/her to forge acceptable packets for both ends, which mimic the real packets. Thus, the attacker is able to gain control of the session. Counter Measures: Using secure protocols instead of clear text protocols like HTTP, FTP. etc. Encrypting session id will increase the complexity of the session id prediction. Sending session id over SSL. Use long random numbers for session id. Implement timeout for the session when the session is logged out, or session id expires etc.
- **ANS A.7:** The initial version, SSH1 was focused on providing a secure remote logon facility to replace TELNET and other remote logon schemes that provided no security. SSH also provides a more general client/server capability and can be used for such network functions as file transfer and e-mail.
- **ANS A.8:** SYN flood attack, also known as the half-open attack, is a protocol attack, which exploits the vulnerabilities in the network communication to make the victim’s server unavailable to legitimate requests. By consuming all the server resources, this type of attack can bring down even high-capacity components capable of handling millions of connections. SYN flood DDoS attacks exploit TCP three-way handshake connection and its limitation in handling half-open connections. How to Protect Against SYN Flood Attacks? 1.Increase Backlog Queue. 2.Recycling the oldest half-open connection. 3.SYN Cookies. On the other side, the goal of the TCP session hijacker is to create a state where the client and server are unable to exchange data; enabling him/her to forge acceptable packets for both ends, which mimic the real packets. Thus, the attacker is able to gain control of the session. Counter Measures: Using secure protocols instead of clear text protocols like HTTP, FTP. etc. Encrypting session id will increase the complexity of the session id prediction. Sending session id over SSL. Use long random numbers for session id. Implement timeout for the session when the session is logged out, or session id expires etc.
- **ANS A.9:** IPsec is below the transport layer (TCP, UDP). 
- **ANS A.10:** Dynamic Host Configuration Protocol (DHCP) is a client/server protocol that automatically provides an Internet Protocol (IP) host with its IP address and other related configuration information such as the subnet mask and default gateway. DHCP minimizes configuration errors caused by manual IP address configuration, such as typographical errors, or address conflicts caused by the assignment of an IP address to more than one computer at the same time.
- **ANS A.11:** An ARP spoofing, also known as ARP poisoning, is a Man in the Middle (MitM) attack that allows attackers to intercept communication between network devices. The attack works as follows: The attacker must have access to the network. They scan the network to determine the IP addresses of at least two devices⁠—let’s say these are a workstation and a router. The attacker uses a spoofing tool, such as Arpspoof or Driftnet, to send out forged ARP responses. The forged responses advertise that the correct MAC address for both IP addresses, belonging to the router and workstation, is the attacker’s MAC address. This fools both router and workstation to connect to the attacker’s machine, instead of to each other. The two devices update their ARP cache entries and from that point onwards, communicate with the attacker instead of directly with each other. The attacker is now secretly in the middle of all communications.
- **ANS A.12:** Yes. 
- **ANS A.13:** Hackers are always trying to pull off the next great heist, as evidenced by recent DDoS attacks. According to The Record, Google stifled what would have been the largest DDoS attack in the world in June of 2022. The attack peaked at 46 million requests per second, which was compared to the number of requests Wikipedia receives every day. The attack lasted about 30 minutes and consisted of more than 5,000 devices from 132 countries. DDoS attack protocols and the Google security team prevented what could have been a significant security risk for billions of users.
- **ANS A.14:** a) This scheme is extremely simple and easy to implement. It does protect against very simple attacks using an off-the-shelf Wi-Fi LAN card, and against accidental connection to the wrong network. b) This scheme depends on all parties behaving honestly. The scheme does not protect against MAC address forgery. 

