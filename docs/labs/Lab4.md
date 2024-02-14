# Lab 4: Testing a Firewall 


Hi class.  In todays lab, you will learn more about networking and firewalls.  



**Note:** Today’s lab DOES NOT work in Packet Tracer versions after 7.3. You need to either log in to the Engineering Desktop, where it is already installed, via this link: https://rdweb.wvd.microsoft.com/arm/webclient/index.html, or install Packet Tracer Version 7.3 on to your own laptop. Here is the [LINK](https://u.pcloud.link/publink/show?code=kZm7KgVZmRzv7EJdhHfxv7cRscruY5kfUznV&fbclid=IwAR2KkUMzaCzwedQjeLeuPIw5zrMEc4y7fA2tdy3ghMbPlTN_ODP205IvDd8) for packet tracer for different environments (AMD, Windows and Mac). Before installing Packet Tracer 7.3. version please uninstall any versions you already have on your system.


**Note:** If you haven't done so already (e.g. from previous labs) you will need to create a [CISCO account](https://www.cisco.com/c/en/us/about/help/login-account-help.html) to be able to use Packet Tracer for free! 


**Note:** Working from home?  If you need help post a question in the Teams group for the unit and we'll try and help you from there, but if at all possible do try and attend the lab where there will be *more* support. 



## Getting familiar with the network


•	Open the Packet Tracer simulation, [02_PacketTracer_Testing_firewall.pka](https://github.com/cs-uob/COMS20012/blob/master/docs/materials/02_PacketTracer_Testing_firewall.pka) inside Cisco Packet Tracer. If you are asked whether to update devices, click No. 

### The Devices 

In the green section is some of the equipment that may be found in a small office that operates as a branch of a larger business. 

•	The Branch PC is just a normal computer workstation in the office. It can be used to access information and controls on the servers, or access the head office via the Internet. 

•	The Fire Sprinkler, Webcam, Light and Drain are all connected to the network so they can each be remotely monitored and operated. 

•	The Thermostat measures ambient temperature and controls the heating and cooling. This is also connected so it may be monitored and controlled across the network. 

•	The Branch Server contains the databases of sensitive company and customer information.  

•	The IoT Device Registration Server acts as a single interface that can be logged in to for monitoring and controlling all devices. {For more information on IoT see: [Link](https://www.oracle.com/uk/internet-of-things/what-is-iot/#:~:text=What%20is%20IoT%3F,and%20systems%20over%20the%20internet.)}. The yellow section represents the head office of the company, located in a different city from the branch offices. Head office can connect to branch servers and IoT device registration servers via the Internet as needed. Branches can also connect to the server in the head office to access information. 
The red section contains an attacker’s equipment, which could be located anywhere else in the world. The attacker may have various reasons for wanting to gain access to sensitive company information and gain control over connected devices, such as for financial benefits, to disrupt or as a personal challenge. 


## Test the network

1.	Click on the Branch PC. A window will open on your screen representing the PC. 
2.	Click on the Desktop tab and click on Web Browser (you might need to enlarge the window). 
3.	Click in the box next to URL and type _branch.server_ 
4.	Press Enter on your keyboard or click the Go button on screen. 
A website should appear on the Branch PC’s web browser which was sent by the Branch Server. You can click on the links on the page and see that there are (mock-up) sensitive details that could harm the business’s reputation, cause legal problems or otherwise cost money if accessed by an attacker. 
5. Click in the URL box of the web browser and replace the current URL with _iot.devices_ 
6. Press Enter on your keyboard or click the Go button on screen. 
7. In the web page that appears, enter the following login details: Username is _devices_, password is _vB82parsnip!_ (including the exclamation mark). 
8.	Click the Fire Sprinkler line. It will drop down to show you the status of the sprinkler, represented by a red or green rectangle. 
9.	Click the red rectangle so that it changes to green, indicating a change in status. This is how the IoT devices can be manually activated via a website. Notice the change to the picture of the sprinkler in the main workspace. 
10.	Click again to turn the Fire Sprinkler off. 
11.	Still in the web page on the Branch PC, click the Thermostat section. The status and options for the thermostat should appear. 
12.	Click Auto, so that the thermostat regulates the temperature. 
13.	Set both the Auto Cool Temperature and Auto Heat Temperature to 18.0 (you will need to click Set for each after typing 18.0 and _might_ need to set the Auto Heat first). Notice the red indicator lights on the heating and cooling as the thermostat attempts to maintain the fluctuating temperature. Close the Branch PC's window.

## Access the Head Office Server via the Internet  

**Note:** This is a simplified representation of Internet communication. In reality, the particular IPv4 addresses being used here could not be used directly across the Internet. NAT (Network Address Translation) at the routers would convert them to different IP addresses as they leave a network and back again as they return. 

1.	In the Web Browser on the Branch PC, type _head.office.server_ 
2.	Press Enter on your keyboard or click the Go button on screen. 


At the moment you pressed Enter or Go, the Branch PC sent data through the routers and the Internet to the Head Office Server, which represented a request for a web page. In response, the data which formed the web page was sent back to the Branch PC from the server, where it was displayed on screen.  Close the Branch PC window.

Normally, the firewall on the Branch Router would block all data being sent to the Branch’s network from the Internet. It was only allowed in this case because it was recognised as a response to a request as part of an established connection. 


## Access the Branch from Head Office 

There is a requirement that Head Office should be able to access the Branch’s network via the Internet to monitor information on the server and check on the IoT devices. For this to work, the firewall on the Branch Router must also allow the entry of certain types of data traffic from the outside even if it is not a response to a request from inside the network. 
To make this possible, the firewall on the Branch Router will allow any data traffic originating from the IP addresses used by the head office equipment. 
1.	Click the Laptop in Head Office. 
2.	Click the Desktop tab and then click Web Browser. 
3.	Type _branch.server_ into the box next to URL and press Enter or click Go. You should be able to see the website on the Branch Server. 
4.	Now type _iot.devices_ in to the box next to URL and press Enter or click Go. 
5.	Login using the username _devices_ and the password _vB82parsnip!_ 
6.	Open the Water Drain. 
7.	Turn on the Light. 
8.	Close the Laptop window. 


## Attempt Access from the Attacker’s PC 

We will assume an [ attacker ](https://www.u-blox.com/en/blogs/insights/iot-device-security-man-in-middle#:~:text=A%20man%2Din%2Dthe%2Dmiddle%20attack%20occurs%20when%20a,network%20or%20send%20malicious%20data.) would like to gain access to the Branch network to access data on the Branch Server and control the IoT devices to cause harm to the business. 
1.	Click the Attacker’s PC to open a window. 
2.	Click the Desktop tab and click Web Browser. 
3.	Try typing _branch.server_ in the box next to URL, then press Enter or click Go. 

Nothing may happen for a second or so as the PC tries to connect, but then you will see a message in the browser, "Host Name Unresolved". When a website address is typed into a browser, the DNS (Domain Name System) on your computer will check an index which matches hostnames to IP addresses. This is to make it easier than remembering and typing IP addresses to find websites. The hostnames we have been using so far in this activity (e.g. _iot.devices_) are using a DNS that is local to the company networks which the attacker cannot access. 

**_Question: What is DNS and what is it used for?_**  Hint: Go back to lecture 3!

Let's assume the attacker already knows the actual IP address of the Branch Server: 

4.	Repeating step 3, try typing the IP address of Branch Server `192.168.3.5` in the box next to URL, then press Enter or click Go. 
After a few seconds you will see a message in the browser, "Request Timeout". In this case, the routers were able to use their routing tables to send the request for a web page towards the correct network, but the packets were dropped upon reaching the Branch Router. They were dropped, or ignored, because the source IP address of the packet was the Attacker’s PC, and did not match any firewall rules allowing access. 



### Gather Information from the Network 

As we said in the lectures, you cannot protect or attack a system or network that you do not know! To be able to penetrate into the system/network, you need to get familiar with it! 

The attacker is aware that there is communication between the company’s Head Office and the Branch and would like to view some of these packets to learn which IP addresses are being used. One way this could be achieved is by sending an email to a company staff member using an email address listed on their public website. The email would appear to be genuine, but actually contained a malicious attachment which installed spyware on the staff member’s computer. This spyware then records traffic sent from the laptop computer in Head Office and secretly emails all the details to the attacker. Attempting to attack by tricking someone to installing spyware or malware on their own computer is known as phishing. 
The Sniffer, which can be seen in the red section of the simulation workspace, is a device which will represent spyware for this Packet Tracer simulation by recording network traffic details within the head office. 
1.	Click the Sniffer. A window will open. 
2.	Click the GUI tab (Graphical User Interface). 
3.	Maximize the window on your computer screen so you can see all details. 
You will see a number of HTTP packets listed in a column on the left of the window which were recorded during your earlier activity. The ones at the bottom of the list should be the most recent, which were generated when accessing the IoT Device Registration Server from the laptop in the head office. 

**_Question: In the world of networking, what is a sniffer? Did we talk about that in the lecture? Which one_**?

4.	In the Sniffer window, click the last HTTP packet (at the bottom of the list) and look at its contents as they appear in the section on the right. 
This shows you some details of the packet contents in the form of an upsidedown TCP/IP model (Physical or Network Access layer at the top) . You may need to scroll down to see all details.
  
•	The Ethernet II section includes the source and destination MAC addresses, seen as twelve hexadecimal figures and labelled as SRC ADDR and DEST ADDR.  

•	The IP section includes the source and destination IPv4 addresses, seen as decimal numbers and labelled as SRC IP and DST IP.  

•	The TCP section shows the source and destination ports labelled as SOURCE PORT and DESTINATION PORT.  

•	The HTTP section is show in the application layer, which in this case is the HTTP data request instructions relating to the IoT devices.  

If the previous steps were done in the order of these instructions, you should see that the destination IP (DST IP) of the packet is `192.168.3.100` and the source IP (SRC IP) of the packet is `10.1.1.3`. 
This tells us that the most recent packet that was sent from Head Office (which turned on the Light in the branch office) was sent from an IP address of `10.1.1.3`.

**_Question: Can you give three examples of popular application layer protocols with well-known TCP port numbers?_**  


### Send from a Spoofed Source IP Address 

To get past the Branch Router firewall, the attacker might use special software and methods to modify the source address of a packet before trying to send an HTTP request to the Branch Server. 
We will simulate this by modifying the configuration of the attacker’s equipment so that it sends packets which will appear to from the Head Office, and therefore will get past the Branch Office firewall: 

1.	Click on the Attacker’s PC so that a window opens. 
2.	Click the Desktop tab, then click IP Configuration. 
3.	Change the IP Address to `10.1.1.6` (this should be within the Head Office subnet) 
4.	Change the Subnet Mask to `255.255.255.248` 
5.	Change the Default Gateway to `10.1.1.5` 
6.	Close the Attacker’s PC window. 
The Attacker’s Router would also need to be reconfigured to suit. Rather than doing this using the router’s command line configuration, which is outside the scope of this course, a replacement router is available which has already had its own IP address changed from `192.168.0.1` to `10.1.1.5` 
7.	Move the Replacement Router so it is alongside the Attacker’s Router 
8.	Click the green flashing light at the end of the cable below the Attacker’s Router, drag it to the Replacement Router and release. If you instead receive a pop-up warning when trying to click then you are clicking the wrong place and should try again. A menu will pop up showing the available ports; choose GigabitEthernet0/0 
10.	Click the green flashing light at the end of the cable above the Attacker’s Router, drag it to the Replacement Router and release. A menu will pop up showing the available ports; choose GigabitEthernet0/1
11.	After a short pause all the triangles should turn back to Green.

**_Qestion: What is Spoofing?_** 


### Gain Access through the [Firewall](https://www.simplilearn.com/tutorials/cyber-security-tutorial/what-is-firewall)
1.	Click the Attacker’s PC to open a window. 
2.	From the Desktop tab, open the Web Browser. 
3.	Type the IP address of the Branch Server, which is `192.168.3.5` and press `Enter` or click `Go`. 
You should now see the web pages on the Branch Server. The attacker also has access to the IoT Device Registration Server. 
4.	Type the IP address of the Registration Server, which is `192.168.3.100` and press `Enter` or click `Go`. 

The IoT Device Registration Server has another level of protection. Even though an attacker has been able to access the network, they would still require a username and password to gain control. This is why the strength of the password is important, so that it cannot easily be guessed. Other security measures, such as temporary lockouts after a number of incorrect attempts and the use of multifactor authentication would also help to prevent access to the IoT controls. Even without being able to crack the password and control IoT devices, an attacker could still cause harm to the server from inside the network, such as creating a DoS (denial of service) attack. 

It may also be possible for someone to determine the username and password by “sniffing” and examining the traffic that passes when others log in. These web pages are using the HTTP protocol and, therefore, any passwords are visible data (or plaintext). Using a properly encrypted HTTPS (secure HTTP) website would prevent this. 

5.	Assume the attacker has discovered the password. Type the username _devices_ and the password _vB82parsnip!_ to sign in to the registration server. 
6.	Click the Webcam option in the list of devices and click the red rectangle to activate the webcam. 
7.	Click the Light option and turn it off. 
8.	Click the Thermostat and turn it off. 
9.	Close the Water Drain and turn on the Fire Sprinkler. 


This demonstrates some of the security implications of having IoT devices connected to the Internet. If an attacker can gain access, they could potentially view inside secure areas with a webcam, create a nuisance or hazard by turning lights off, damage temperature-controlled equipment by disabling air-conditioning or even flood a building. 
While this activity was largely theoretical, it is necessary to understand some of the security considerations that should be taken and the potential implications if ignored. In reality it would be more difficult to gain access through a firewall from the Internet by simply spoofing an IP address like this because any responses to your HTTP requests would be routed to the real IP address unless further efforts were made to redirect them. 


**Note:** This weeks lab *should* work on any machine... including
an M1 Mac, a lab machine and anything else you can throw at it... but
you *might* need to tweak things to get it all working; and if in
doubt fall back to `ssh seis.bristol.ac.uk`

Good Luck!

Alma
