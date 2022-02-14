# Lab 3 - Web Security

## Description

In this lab, we will explore some of the web vulnerabilities that we discussed in the lecture. We will use a well known educational web application, called [WebGoat](https://owasp.org/www-project-webgoat/){:target="_blank"}, which contains vulnerable web pages. It also has some basic introductions to web vulnerabilities and related hands-on exercises to complete. You will complete some of those exercises.

**NOTE:** Those students who are using personal computers, make sure you have recent version of JDK (e.g. jdk-12.0.2) installed on your machine. You can get one from [here](https://github.com/AdoptOpenJDK/openjdk12-binaries/releases/tag/jdk12u-2019-11-21-10-04){:target="_blank"}. For those accessing university lab machine, JDK is already installed  (see the lab instructions below for setting it properly).

If you are not working directly at a lab machine, you can SSH into one from your own computer using the following:

```bash
# ssh into the lab machine and forward the port
# -L specify the mapped port and -J specify the jump server
# Please change ab12345 to your username
ssh -L18080:localhost:18080 -J ab12345@seis.bris.ac.uk ab12345@rd-mvb-linuxlab.bristol.ac.uk
cd <your working directory>
# Download the jar file for the lab
wget https://github.com/WebGoat/WebGoat/releases/download/v8.1.0/webgoat-server-8.1.0.jar
```

If you would prefer to have a full graphical session remotely, you can use X2Go (not recommended): [see here](https://uob.sharepoint.com/sites/itservices/SitePages/fits-engineering-linux-x2go.aspx){:target="_blank"}.

## Lab Instructions

1. Download the vulnerable server *WebGoat* from this [link](https://github.com/WebGoat/WebGoat/releases/download/v8.1.0/webgoat-server-8.1.0.jar).
2. This will ask you to save a jar file `webgoat-server-8.1.0.jar`.
3. Open a terminal and go to the folder where you saved `webgoat-server-8.1.0.jar`
4. Enter the following commands:
```properties
export PATH=/usr/lib/jvm/java-11/bin:$PATH
export WEBGOAT_PORT=18080
export WEBGOAT_HSQLPORT=19001
java -jar webgoat-server-8.1.0.jar
```
5. It will start the vulnerable server on your machine.
6. Open you browser and type the following URL:
    127.0.0.1:18080/WebGoat
7. You will see the WebGoat login page. Register with some dummy account.
8. On the left pane, you will see several topics that are covered in WebGoat server labs (tutorials and exercises). We will cover only the following:
    - A1: Injection
    - A3: Sensitive data Exposure
    - A7: Cross-Site Scripting (XSS)
9. Before starting the exercise, Click on the **General** option in the left menu and select **Developer Tools**. Complete the lesson. You will notice that the lesson uses the Chrome browser. Similar options are also available on Firefox. For Firefox, press F12 or click the *menu button* (on right top corner) *-> Web Developer -> Toggle*
10. For **A1: SQL injection**, we will be completing the Part 1 "**SQL Injection (intro)**". Follow the instructions on the page and complete the exercises (from 1 to 13). **Remark:** *As you move on solving the exercise, you will be asked to change something in a DB table. It will save you time, if you take a screenshot of the table that you print first time so that you remember its structure for the following exercises.*
11. Optionally, you can try Part 2: SQL Injection (advanced) at your own time.
12. For **A3: Sensitive data exposure**, we will be completing the part *insecure login*. Click on that exercise on your left pane. You will notice that the exercise asks you to use a network sniffer. As we don't have one, you can use a Firefox/Chrome utility. Once on the exercise page, open your developer tool pane. You will see the "Network" tab in the menu. Click that. Now, you can see the request/response of each action you do on the page. Use this utility to complete the exercise. This exercise shows the importance of HTTPS!
13. For **A7: Cross-Site Scriptng (XSS)**, click the respective menu item on the left pane. Complete the steps 1 to 7.
