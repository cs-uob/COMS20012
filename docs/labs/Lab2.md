# Lab 2: Message Analysis using Wireshark

Hi class. In this lab, you will learn to capture messages (Application, TCP segments, IP Packets and Ethernet Frames) using Wireshark. Wireshark is the world’s foremost and widely-used network protocol analyzer. It lets you see what’s happening on your network at a microscopic level and is the de facto (and often de jure) standard across many commercial and non-profit enterprises, government agencies, and educational institutions. Using packet analysis to sniff network traffic can achieve the following goals: Footprinting and reconnaissance. As a precursor to an active attack, hackers use Wireshark to capture unencrypted traffic in order to gather as much information about the target as possible. More about Whireshark you can read [here](https://www.wireshark.org/#:~:text=About%20Wireshark&text=Wireshark%20is%20the%20world's%20foremost,government%20agencies%2C%20and%20educational%20institutions.). 
We will not be hacking anything today, but we will learn how to build, define and exercise Wireshark Message/Packet Display Filter (Typing Text, Expression Builder & Shortcut options). You will also compare the standards of the TCP/IP Layered Network Architecture with Wireshark captured HTTP and TCP messages. More about TCP/IP Layered Network Architecture you can read [here](https://docs.oracle.com/cd/E19683-01/806-4075/ipov-10/index.html)

## 1. Setting up Wireshark
As you will be using Wireshark for this lab, let's learn how to setup Wireshark on Kali Linux inside Vagrant. 

**You can use your laptop (Linux system) (it is expected that you use Ubuntu for Desktops: http://www.ubuntu.com/ .) And VMware which is an open source on Linux systems.**

In the previous lab we were setting up Vagrant and VirtualBox VM, to make sure today lab is successful go to the vagrant file in your CS_Vagrant and delete it. 

**For this lab make new file otherwise it will not work!!!**

1. On your host machine, open a terminal in you home directory (or whatever directory you are asigned which has good memory). Make a directory `mkdir CS_Lab`
2. `cd CS_Lab` 
3. `vagrant init kalilinux/rolling`  
4. `vagrant up`. First time, this is will download Kali Linux. It will take a while. Once done, you will have new window opened! It is Kali Linux! 
5. Open a terminal inside Kali and type sudo wireshark. This will install Wireshark inside your Kali Linux VM! You screen should look something like [this](https://github.com/cs-uob/COMS20012/blob/master/docs/materials/Selection_001.png).
6. Congratulations! Now you are ready to run your first packet analysing lab!

**NOTE:** working from home?  If you need help post a question in the
Teams group for the unit and we'll try and help you from there, but if
at all possible do try and attend the lab where there will be *more* support. 

## Exercise 1: Wireshark Setup/Capture

Make sure that the Host Hardware/External Network Interface ethx (where x is an integer) is connected to the public network (Internet), that is, it acquired an IP address.

Launch Wireshark on the Host by typing sudo wireshark in a terminal on the Host. Click on the Interfaces option in the Capture menu. Click on the Options button corresponding to the IP address acquired by the Host Hardware/External Network Interface ethx.
Check the boxes for all Displays Options and Name Resolution. Make sure that “Enable promiscuous mode on all interfaces” is checked in. Click Start.

## Q1 - What does promiscuous mode mean?
Wireshark should start displaying “packets” (actually displaying frames) transmitted or received on the selected interface. Note that each line represents an Ethernet Frame. Wireshark window is divided into 3 panes. If you do not see all 3 panes you may have to click on one of the thick horizontal divider to show any hidden pane. The top pane displays one row of info for each frame/packet captured.

## Q2 - Describe the information provided and explain the headings of the columns.
Note that the frames/packets (rows) are sorted by Time. However, you can change that by clicking on the heading of another column and therefore sort by the heading of that column.

## Q3 – Provide an example where you have sorted the frames using the Protocol column.
The center pane displays the protocols associated with the selected Frame and the bottom pane displays the hexadecimal representation (Hex View) of the data contained in the same. Beneath the bottom pane is a status bar that displays the total number of Frames captured, displayed and marked (zero unless filtering is applied).

For example, if you select in the center pane the Ethernet II layer (Data Link) of a Frame, the hexadecimal representation of that layer information should be highlighted in the bottom pane. Take a [screenshot](https://github.com/cs-uob/COMS20012/blob/master/docs/materials/ScreenshotDNS.png).

## Q4 – Find out and describe how one could change the bottom pane view from Hex View to Bits.
## Q5 – Explain the how one would go about converting decimal number 87 into its Hex and Binary representations.

## Exercise 2: Capturing Frames and encoding:
Open a Firefox browser on the Host. Select Edit > Preferences > Privacy and select Never remember history and click on clear all current history. Click Close. Make sure that the startup home page of your browser is Google or Ubuntu Google. Close the browser.

On Wireshark application (assuming it is still running!), select Capture > Restart (the green arrow) from the top menu bar. All captured and displayed Frames should be cleared from the top pane. Note – Almost instantaneously new frames are captured, the network is busy all the time, auto discover, etc.

In a terminal (on the Host) type nslookup google.com to force the generation of Domain Name requests. You screen should look something like [this](https://github.com/cs-uob/COMS20012/blob/master/docs/materials/Screenshot_2023-02-05_10-20-57.png).

## Q6 – compare the results of nslookup on the Host terminal and the content of the corresponding DNS response message as captured by Wireshark.

Then launch Firefox browser on the Host to force the generation of http requests &responses and tcp segments. Note that ARPs messages are dynamically generated on a regular basis. Wireshark should display frames/packets with protocols, such as, ARP, DNS, TCP, HTTP, etc. Did you get similar [traffic](https://github.com/cs-uob/COMS20012/blob/master/docs/materials/Selection_003.png)? 

Wait a second or two and then close the browser. Stop capturing packets by clicking on the stop icon (see above) or select Capture > Stop from the top bar menu. Save the captured packets in a file: select File > Save As > enter a name, say, Lab_Capture_Lastnames.pcap, navigate where you want to save the file, and click Save.

Check http://www.ascii-code.com/, that is, the ASCII table:
Provide the binary representation of the character A (letter), the character 3 (number) and the no-displayable character \r (carriage return).
Using the ASCII table, find out the Hexadecimal representations of the characters G, E and T (that is the word GET).

## Exercise 3: Wireshark Display/Filtering
Continuing with the captured packets on Wireshark, type http in the tool bar text box and click Apply. The background of the text box turns green when the typed text in the correct syntax (that is, expected by Wireshark). Wireshark should display Frames with http protocol (as the top protocol).
Type tcp in the tool bar text box and click Apply.

## Q8 - Why are there some frames labeled as HTTP under the protocol heading after applying the tcp filter?
If you need to exclude the HTTP from the TCP frames, you can type “tcp and not http” (which means filter for tcp and exclude http) in the filter text box. Try it out. Provide your results. For more information regarding wireshark filters check the following link.

If you need to display packets sent (sourced from) by a specific IP address, you should enter ip.src== “ip address” (replace the word “ip address” with the specific IP address you are searching for). Provide an example.
To find out the entire set of Display Filter syntax, you may click the Expression button next to the filter text box. For example, scroll to the IP entry and expand by clicking on the + sign or the arrow on the left. Wireshark should display all possible attributes of the object IP. Find ip.ttl and find out what it means. Type “ip.ttl” then “==” and type “64” in the value field so that the equation would look like the following (ip.ttl == 64) and Click OK.
## Q9 - Describe what happens (what you have witnessed).
## Q10 – Can I filter for a specific source IP address and specific destination IP address? Provide screenshots.

**NOTE:** this weeks lab *should* work on any machine... including
an M1 Mac, a lab machine and anything else you can throw at it... but
you *might* need to tweak things to get it all working; and if in
doubt fall back to `ssh seis.bristol.ac.uk`
Good Luck
Alma
