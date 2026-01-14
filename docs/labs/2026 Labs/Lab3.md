# Lab 3: Getting famiar with networking using Packet Tracer 

Hi class. In this lab, you will learn how to set up simple network in Packet Tracer. In the second part of this lab you will learn how to use [ IP spoofing](https://www.kaspersky.com/resource-center/threats/ip-spoofing) in the IoT house.  

[ Packet Tracer ](https://www.netacad.com/courses/packet-tracer) is a cross-platform visual simulation tool designed by Cisco Systems that allows users to create network topologies and imitate modern computer networks. The software allows users to simulate the configuration of Cisco routers and switches using a simulated command line interface.

**NOTE** You need to create [CISCO account](https://www.cisco.com/c/en/us/about/help/login-account-help.html) to be able to use Packet Tracer for free! If you are using your own laptop download Packet Tracer by following the Packet Tracer link above and registering for the "Getting Started with Cisco Packet Tracer" course. Then, lets start! 

**NOTE** If you are using lab machines you'll need to access the Kali VM that you should have made last week. To download and set up Packet Tracer within Kali:
1. Download the Packet Tracer .deb file after logging into your account from the link above (make sure it is the one listed for Ubuntu). 
2. Run `sudo dpkg -i [PATH TO YOUR PACKET TRACER DEB]`
3. Accept the license agreement and EULA terms

This WILL result in dependency issues (dialog, libxcb-xinerama0, libgl1-mesa-glx), but we'll need to install these separately...

4. To install dialog, run:
```
sudo wget http://http.kali.org/kali/pool/main/d/dialog/dialog_1.3-20240307-2+b1_amd64.deb 
sudo dpkg -i dialog_1.3-20240307-2+b1_amd64.deb 

sudo wget http://http.kali.org/kali/pool/main/d/dialog/libdialog15_1.3-20240307-2+b1_amd64.deb

sudo dpkg -i libdialog15_1.3-20240307-2+b1_amd64.deb 
sudo apt-get install dialog
```

5. To install libxcb-xinerama0, run:
```
sudo wget http://ftp.de.debian.org/debian/pool/main/libx/libxcb/libxcb-xinerama0_1.15-1_amd64.deb
sudo dpkg -i libxcb-xinerama0_1.15-1_amd64.deb

sudo wget http://ftp.de.debian.org/debian/pool/main/libx/libxcb/libxcb-xinerama0-dev_1.15-1_amd64.deb
sudo dpkg -i libxcb-xinerama0-dev_1.15-1_amd64.deb 
```

6. To install libgl1-mesa-glx, run:
```
sudo wget http://ftp.de.debian.org/debian/pool/main/m/mesa/libgl1-mesa-glx_20.3.5-1_amd64.deb
sudo dpkg -i libgl1-mesa-glx_20.3.5-1_amd64.deb 
```

With this you should now be able to boot Packet Tracer with the packettracer command.


**NOTE:** working from home?  If you need help post a question in the
Teams group for the unit and we'll try and help you from there, but if
at all possible do try and attend the lab where there will be *more* support. 

## Exercise 1. Setting up simple network in Packet Tracer

1.	Open packet tracer and click on file then new
2.	On the bottom left click on the “Network Devices” icon routers and drag a new PT-Router.
3.	Click on the “End Devices” next and drag two generic PCs. 
4.	Click on “Connections” and select on a “Copper Cross-Over” cable and connect the first PC through a FastEthernet0 then click on the router and plug it into the routers FastEthernet0/0 as well. 
5.	Get another Cross-Over cable and click on the second PC’s FastEthernet0 and plug that into the other FastEthernet1/0 on the router.
6.	Rename the first PC to (192.168.1.100) and then rename the second PC to (192.168.5.100). 
7.	Click on the router and go to the Config tab and click on FastEthernet0/0. 
8.	Type in the IP Address (192.168.1.1) and turn the Port Status to (on). 
9.	Now click on FastEthernet1/0 and type in the IP Address (192.168.5.1) and turn the Port Status to (on). Close the window.
10.	Click on the first PC and go to the Desktop tab and click IP Configuration. 
11.	In the IP Address textbox type (192.168.1.100) in the Subnet Mask textbox type (255.255.255.0). 
12.	Close the IP Configuration window (not the PC window) and open a Command Prompt; type `ping 192.168.1.1` and enter. You should see 4 packets sent and received; if not, then check your settings. 
13.	Close this window, open the IP Configuration again and in the Default Gateway textbox type (192.168.1.1) and in the DNS Server textbox type (192.168.1.1) close this window. Go back to Command Prompt and type `ping 192.168.1.1`; again, you should see 4 packets sent and received. Close the window. 
14.	Now go back and click on the second PC; go to Desktop and IP Configuration. 
15.	In the IP Address textbox type (192.168.5.100) in the Subnet Mask textbox type (255.255.255.0) in the Default Gateway textbox type (192.168.5.1) in the DNS server textbox type (192.168.5.1) close this configuration window.
16.	Open the Command Prompt; type `ping 192.168.5.1` and enter.  Again, you should see 4 packets sent and received. Close the window. 
17.	Open the first PC and go to the Command Prompt; type `ping 192.168.5.100` and `enter`. You see 4 packets sent to and received from the other PC. Close the window. 
18.	Open the router and go to the CLI tab. Hit (enter) get to the start screen - it should show "Router>".  (You might need to type 'exit' twice or ctrl+c.) 
19.	When at the command prompt type 'enable and hit enter; you should now see "Router#".  Now type `show ip route`.  You should see a screen which finishes with confirmation that 192.168.1.0/24 is connected to FastEthernet0/0 and 192.168.5.0/24 is connected to FastEthernet1/0.  Close the window. 
20.	Pull up another PT-Router and from Connections get a Serial DCE cable; connect that into the router that already has the PCs plugged into it and plug into the Serial2/0 port.
21.	Connect the other end of the cable to the other router’s Serial2/0.
22.	Click on the first router, go to the Config tab and select Serial2/0. Set the clock rate to (56000); in the IP Address textbox type (10.0.0.1); in the Subnet Mask textbox type (255.0.0.0); and turn the Port Status to on. Then close the window. 
23.	Now go back and click on the second router. Go to the Config tab and select Serial2/0.  Set the clock rate to (56000); in the IP Address textbox type (10.0.0.2); in the Subnet Mask textbox type (255.0.0.0); and turn the Port Status On.  Then close the window. 
24.	Click on the first router and select the CLI tab.  Press (ctrl c) and hit (enter) (you should now see "Router#"). Type (show ip route) and hit (enter). You should now see that in addition to the 2x PCs you have the other router (10.0.0.0/8) is directly connected via Serial2/0. 
25.	From End Devices the bottom left, select a Server and drag into the space. 
26.	Go to connections and get a (Copper) Cross-Over cable; click on the FastEthernet0 on the server, and on the second router click on the FastEthernet0/0.
27.	Label the server (172.16.1.100), then go to its desktop tab and click on IP Configuration. In the IP Address textbox type (172.16.1.100), in the Subnet Mask textbox type (255.255.0.0) and in the Default Gateway textbox type (172.16.0.1).  Close this window. 
28.	Click on the second router and select the config tab. 
29.	Click on the FastEthernet0/0. In the IP Address textbox type (172.16.0.1); in the Subnet Mask textbox type (255.255.0.0); turn the Port Status on and close this window.
30. Click on the server, go to the Command Prompt and type `ping 172.16.0.1` and hit `enter`.  Again, you should see 4 packets sent and received (i.e. no losses).  Now type `ipconfig` and hit `enter` - you should see the IPv6 address, IP address, Subnet Mask and Default Gateway.  Close the window. 
31.	Click on the first router, go the Config tab and click on the Static tab under Routing.
32.	Type in the Network textbox (172.16.0.0), in the Mask textbox type (255.255.0.0) and in the Next Hop textbox type (10.0.0.2).  Now click Add and close this window.
33.	Click on the second router and on the Config tab click Static (under the Routing tab). 
34.	In the Network textbox type (192.168.1.0); in the Mask textbox type (255.255.255.0); in the Next Hop textbox type (10.0.0.1); then click Add and close this window.
35.	Click on the first PC and go to the Command Prompt and type `ping 172.16.1.100` and press `enter`.  You should see 4 packets sent and received.  Close this window.
36.	Click on the second router and go to the Config tab and to the Static tab under Routing.  In the Network tab textbox type (192.168.5.0) and in the Mask textbox type (255.255.255.0) and in the Next Hop textbox type (10.0.0.1). Click Add and close this window. 
37.	Click on the second PC and open Command Prompt. Type `ping 172.16.1.100` and press `enter`. Again, 4 packets successfully sent and received. Your network is up and running!


## Exercise 2: Testing IoT house

1.	Open the Packet Tracer simulation,[ 01_PacketTracer_IoT_house.pka ](https://github.com/cs-uob/COMS20012/blob/master/docs/materials/01_PacketTracer_IoT_house.pka) in Cisco Packet Tracer. It should work fine on versions 7.0 and newer, but there is a known incompatibility with version 7.1.1. 

Look at the eight devices around the house. In a few seconds you should see a visual representation of wireless connections being made between three of the devices. After a while, you should also see that the flickering status lights between the Wireless Access Point and Switch1 will have changed from orange to green to indicate they are ready for operation. 
The IoT House in this simulation shows three devices that have been connected to a single board computer, which has been networked to a wireless access point via a network switch. This system allows the front door to the house and the garage door to be unlocked and opened from anywhere within the house or as the owner approaches and leaves. 
A tablet acts as the control panel for operating the devices within the house. Its wireless connection means it can be mounted in a holder on the wall or moved around the house as needed. The house owner’s smartphone can also control the devices whenever it is within range of the wireless access point. 
1.	Click the House Owner’s Smartphone. A window will open showing the Smartphone’s details. 
2.	The single board computer has been configured to act as a web server to allow the devices to be controlled over the local network. Click the Desktop tab of the Smartphone window and click Web Browser. 
3.	You will see an empty web browser window on the Smartphone. Click in the address bar of the browser (to the right of the initials URL). 
4.	Type the IP address for the single board computer, which is 10.1.1.100 
5.	Press Enter on your keyboard or click Go on the screen. 
6.	You will see six buttons. Test the buttons and view the changes in the alarm, front door and garage door. 
7.	Close the doors and enable the alarm before closing the Smartphone window, as though the owner has left the house locked and secure while away for the day. 

Whenever IoT devices are connected to a network, potential vulnerabilities are introduced. With the advantages of the convenience comes a risk that an attacker may be able to gain access and cause harm. 
We will look at the security measures that have been taken in this IoT house scenario and perform a basic penetration test by finding a way an attacker may still manage to gain control over the doors and alarm from outside the house. 


## Connecting from the Internet 

The house owner has chosen to keep the network which controls the home security completely separate from his home wireless network that connects to the Internet. By being an isolated system, it would be nearly impossible for an attacker to gain access without physically being at or near the house. However, the disadvantage to this is that the home owner will not have the ability to monitor and control these devices while away from home. 

## Connecting to the Wireless Network 

The house owner is using wireless for the benefit of some mobility, rather than using wired devices which would be fixed into place. The wireless access point has been mounted on the outside of the house so that the Smartphone is within range as he approaches the doors. The convenience of using this wireless networking means that network traffic is not just confined to the wires within the house, but is also visible to and is potentially accessible to attackers from outside. 
1.	Click the House Control Panel (Tablet). A window will pop open. 
2.	Click the Config to see the interface configuration options. 
3.	Click Wireless0 from the options towards the left of the window to view settings for the wireless interface.

You can view the settings the tablet is using to connect to the Wireless Access Point and some details about the type of wireless network it is: 

•	What is the SSID of the wireless network? 
The SSID (Service Set Identification) is the name of the network which can either be broadcast so that devices in range can see, or it can be kept private so that someone must already know this before trying to connect. 

•	Which method of authentication is being used for this network? 
This is the best of the available options for preventing unauthorized connection to the HomeWiFi network and for providing encryption to prevent data being viewed by attackers who are within range. 

•	What is the PSK Pass Phrase being used for this network? 
Does it use words that can be found in a dictionary? Does it use upper- and lower-case letters? Does it use numbers and symbols? How long is it? 

•	Try typing this password in to the password strength checker at [https://howsecureismypassword.net/](https://www.security.org/how-secure-is-my-password/) to get an estimate of how long it might take a modern computer to guess this password.  

**NOTE** It is not good practice to test real passwords in password checking websites in case their intentions are not genuine and are actually trying to steal your password. If you would like to test the strength of your own, use passwords which have similar characteristics (length and character type) to your real one but keep yours private. 

•	How could this password be changed to be even stronger and more difficult for computers algorithms to crack using brute-force or dictionary attacks? 

It can be seen that this wireless network is reasonably secure. If an attacker wants to use the IoT devices to gain access to the house, taking control by hacking the WiFi would not be simple. 


## Connecting to the Wired Network 

It can be assumed that the walls and locked doors of this house are physically secure and that there is no way to get within them without telling the single board computer to open them. 
If the single board computer (SBC0) was accessible from outside the house, then there may be ways to take control of it and tell it to open the door, such as by connecting to its serial input connectors. 
If the network switch (Switch1) was accessible from outside the house, then there may be ways to use it to access the network. This could be done via the console port, which allows direct connection to a computer for configuring the switch. An attacker might also be able to plug in to any unused switch ports that have not been deactivated. This may allow the attacker’s device to communicate with the computer which controls the doors and alarm. 

One way an attacker could gain access to the network by connecting to Switch1 from outside the house is by unplugging the cable from the Wireless Access Point and plugging it in to a computer. We will try this now. 
 
1.	From the devices menu at the bottom-left of the Packet Tracer screen, select End Devices. 
2.	In the list of end devices, you will see a symbol for a generic laptop computer. Click the symbol and place one laptop in to the workspace, to the left of the IoT House. 
3.	Click the end of the cable at the Wireless Access Point, where there is a green light, and drag the end of the cable to the new laptop computer. If you are receiving the “Configure is Locked” message instead then you are not clicking in the right place. 
4.	You should see a list appear, which shows the connection types available on the laptop. This is a copper Ethernet cable, so choose the FastEthernet0 option. 

After around 30 seconds you should see that the lights at both ends of the cable have returned to a green colour, indicating correct physical connectivity. The attacker’s laptop computer is now physically connected to the switch in the house’s network, but may not yet be logically connected, i.e. it cannot communicate with any devices. 

A ping is a method of testing logical connectivity. The ping request is sent from one device to another, and the device should usually give a ping reply if it can be reached. The attacker may try to determine the IP address of any connected devices by doing a “ping scan” of a range of IP addresses using software such as nmap. This will try to ping all available IP addresses within the range and list those that replied (there are also other network scanning methods that could be used). 

•	What is nmap?

In this case, however, unplugging the wireless access point and just connecting another device will not work. The home owner has implemented port security on the switch, a measure aimed at preventing this kind of attack. The port at the switch has been configured not to accept packets from unknown devices. This is done by keeping record of the MAC addresses (Media Access Control) of the Smartphone and House Control Panel in the switch. MAC addresses consist of 12 hexadecimal characters (48 bits) and are assigned to any wired or wireless NIC (Network Interface Controller) at manufacture for unique identification. 

In the next steps, we will try pinging the IP address of the single board computer (SBC0) which controls the doors and alarms. The IP address is 10.1.1.100, though the attacker would not know this unless they could find it through a successful ping scan.

5.	Click the Laptop. A window will open. 
7.	Click the Desktop tab and open Command Prompt. 
8.	Type `ping 10.1.1.100` then press `Enter` on your keyboard. 

You will see that it tries to ping the address four times. Each attempt will fail because no reply is received, and the request will time out. This is because the switch will see which address the ping was sent from and drop the packet, rather than forwarding it to the single board computer. 



## Spoof the MAC Address 

The attacker may suspect that port security may be implemented which will reject communication from the laptop’s MAC address, because it does not match the address of the known devices. In theory, MAC addresses should not ever be changed so that all network interfaces have unique identification. In reality, they can easily be modified on some devices or packets can be manipulated so that they appear to come from a different MAC address. 

To spoof the MAC address, the attacker first needs to find the MAC of a valid device, so that it can be copied. One method of finding the MAC address of a device using wireless networking is to “sniff” the traffic that is being sent through the air. Using software on the laptop, such as Wireshark that we got familiar with in the Lab2, the attacker could listen for communication between the House Control Panel and other wireless devices. Even though data is encrypted, the MAC address will still be visible so that devices can identify and differentiate between each other. 

**It is not possible to simulate Wireshark in Packet Tracer, but successfully listening to the wireless traffic between the Wireless Access Point and the House Control Panel will reveal that the MAC address for the tablet’s wireless interface is 0010.1161.3339

1.	Click the Laptop to open its window again. 
2.	Click the Config tab. 
3.	From the options on the left, click FastEthernet0. The interface configuration options will appear. 
4.	Delete the existing MAC address and replace it with 0010.1161.3339 

If the attacker was now to perform a ping scan of some common IP address ranges, they would receive a response from the IP address held by SBC0, the single board computer. It would make sense to begin scanning within the private IP address ranges, which would often be used in homes and small office situations and are as follows: 

•	`192.168.0.0 to 192.168.255.255`

• `172.16.0.0 to 172.31.255.255`

• `10.0.0.0 to 10.255.255.255`

This scan would now reveal that SBC0 has an address of 10.1.1.100. The laptop would need to be configured to an unused address that is likely to be within the same range of addresses (or subnet) that the home network uses. 

5.	From the same window and tab you used for changing the MAC address of the Laptop, find the option for IP Configuration and click the box next to IP Address. 
6.	Type in an address of 10.1.1.99 
7.	Click in the Subnet Mask box and 255.0.0.0 should appear. Leave this as it appears. 
8.	Click the Desktop tab then click Command Prompt 
9.	Type `ping 10.1.1.100` again, then press `Enter` on your keyboard. 

This time you should find that the pings are successful because you receive replies. Having established communication with the computer that controls the doors and alarm, the attacker could now use software like nmap to perform a port scan. This will test TCP or UDP ports (at the transport layer) to determine which protocols may be active and, therefore, which services are available on the device. This will reveal that TCP port 80 is open, which represents the HTTP used by normal web browsing. 


## Control the System 

Having gained access into the home’s network and achieved communication with the computer which controls security, we will now prove that this could result in the attacker being able to open doors and disable the alarm 
1.	From the Desktop tab of the Laptop window, close the Command Prompt if it is still open by clicking the ‘X’ at the right of the blue title bar. 
2.	Click Web Browser (which is also in the Desktop tab). 
3.	Type the IP address of SBC0 in to the box next to URL. (The IP address is 10.1.1.100) 
4.	Press Enter on your keyboard or click Go on the screen. 
5.	Disable the alarm and open the doors from the buttons on the website that appear. 
 
**This activity has demonstrated a way that this system could potentially be controlled from outside the house by an attacker, despite the measures that were in place to protect it. One way this particular attack might have been prevented is by including a physical barrier around the Wireless Access Point, so that the wired network could not have been accessed from outside the house. 



**NOTE:** this weeks lab *should* work on any machine... including
an M1 Mac, a lab machine and anything else you can throw at it... but
you *might* need to tweak things to get it all working; and if in
doubt fall back to `ssh seis.bristol.ac.uk`

Good luck,
Alma.
