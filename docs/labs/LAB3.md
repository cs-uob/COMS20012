# Lab 3 - Web Security

## Description

In this lab, we will explore some of the web vulnerabilities that we discussed in the lecture. We will use a well known educational web application, called [WebGoat](https://owasp.org/www-project-webgoat/), which contains vulnerable web pages. It also has some basic introduction to web vulnerabilities and related hands-on exercises to complete. You will complete some of those exercises.

**NOTE:** Those students who are using personal computers, make sure you have recent version of JDK (e.g. jdk-12.0.2) installed on your machine. You can get one from [here](https://github.com/AdoptOpenJDK/openjdk12-binaries/releases/tag/jdk12u-2019-11-21-10-04). For those accessing university lab machine, JDK is already installed  (see the instructions below for setting it properly).
Also, you need to use X2go client to access lab machines as we will require a GUI based access. [link](https://uob.sharepoint.com/sites/itservices/SitePages/fits-engineering-linux-x2go.aspx)

## Lab Instructions

1. Download the vulnerable server *WebGoat* from this [link](https://github.com/WebGoat/WebGoat/releases/download/v8.1.0/webgoat-server-8.1.0.jar).
2. This will ask you to save a jar file `webgoat-server-8.1.0.jar`.
3. Open a terminal and go to the folder where you saved `webgoat-server-8.1.0.jar`
4. Enter the following commands:
````
export PATH=/usr/lib/jvm/java-11/bin:$PATH
export WEBGOAT_PORT=18080
export WEBGOAT_HSQLPORT=19001
java -jar webgoat-server-8.1.0.jar
````
5. It will start the vulnerable server on your machine.
6. Open you browser and type the following URL:
    127.0.0.1:18080/WebGoat
7. You will see the WebGoat login page. Register with some dummy account.
8. On the left pane, you will see several topics that are covered in WebGoat server labs (tutorials and exercises). We will cover only the following:
    - A1: Injection
    - A3: Sensitive data Exposure
    - A7: Cross-Site Scripting (XSS)
9. Before starting the exercise, Click on the **General** option in the left menu and select *Developer Tools*. Complete the lession. You will notice that the lesson takes example of Chrome browser. The similar options are also available on Firefox. For Firefox, press F12 or click *menu button* (on right top corner) *-> Web Developer -> Toggle*
9. For **A1: SQL injection**, we will be completing the Part 1 "**SQL Injection (intro)**". Follow the instructions on the page and complee the exercises (from 1 to 13). **Remark:** *As you move on solving the exercise, you will be asked to change something in a DB table. It will save you time, if you take a screenshot of the table that you print first time so that you remember its structure for the following exercises.*
10. Optionally, you can try Part 2 (SQL Injection (advanced) at your own time.
11. For,**A3: Sensitive data exposure**, we will be completing the part *insecure login*. Click on that exercise on your left pane. You will notice that the exercise asks you to use a network sniffer. As we don't have it, you can use a Firefox/chrome utility. Once on the exercise page, open your developer tool pane. You will see the "Network" tab in the menu. Click that. Now, you can see the request/response of each action you do on the page. Use this utility to complete the exercise. This exercise shows the importance of HTTPS!
12. For **A7: Cross-Site Scriptng (XSS)**, click the respective menu item on the left pane. Complete the steps 1 to 7.
