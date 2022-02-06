# Lecture 3 - Cryptography and Web Security

The material is subdivided in small videos.

Please, watch the videos and go through the reading material in your own time.

Also remember to work on the accompanying [exercises sheet](../exercises/EXERCISES3.html)

| Video                   | Links                     |        Reading Material                                                                                                                                                                                      |
|-------------------------|---------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| A gentle introduction to Cryptography | [video (45min)](https://web.microsoftstream.com/video/1fdf3361-4fbe-4f2b-9f8a-9212ff7ec097){:target="_blank"} (sorry about the bad audio. I bought a new mic, but it was worse!) [pdf](../slides/W3/W3-L1-Intro-Crypto.pdf){:target="_blank"} | Text Book Chapter 1-- sections 3.1, 3.2, 3.4, 3.5 |
| A gentle introduction to Web Terminology  | [video (32min)](https://web.microsoftstream.com/video/2650423e-41be-4d97-b629-b48c4a5a1033){:target="_blank"} [pdf](../slides/W3/W3-L2-Intro-BasicWeb.pdf){:target="_blank"} | Text Book Chapter 7-- sections 1.1|
| Web Security Part 1  | [video (22min)](https://web.microsoftstream.com/video/665e8709-b8ec-4fef-90b1-23a3df90a343){:target="_blank"} [pdf](../slides/W3/W3-L3-Intro-WebSec1.pdf){:target="_blank"} | Text Book Chapter 7-- sections 1.4, 2.1, 2.2, 2.3|
| Web Security Part 2 (XSS, CSRF) | [video (27min)](https://web.microsoftstream.com/video/fed8db95-363e-4a5c-b0ef-816f1cea7e47){:target="_blank"} [pdf](../slides/W3/W3-L4-Intro-WebSec2.pdf){:target="_blank"} | Text Book Chapter 7-- sections 2.6, 2.7|
| Web Security Part 3 (SQLi)  | [video (17min)](https://web.microsoftstream.com/video/c2af5b32-8652-40cd-8474-9340237d3fb7){:target="_blank"} [pdf](../slides/W3/W3-L5-Intro-WebSec4.pdf){:target="_blank"} | Text Book Chapter 7-- section 3.3|

## Last week survey results

The results from last week survey are [available](../surveys/week2.html).

## Q&A
**Note:** Due to some setting issues, we realized that when Sanjay was explaining the input Sanitization example, the video did not capture his on-screen writing. It only captured his voice describing the example, which makes it hard to understand what was being pointed out. So, here is the example, he was talking about: It was a real example from MS sanitizing inputs for its IIS server. The idea was to remove the string `<script>` entirely whenever it appears in some specific user input. This will prevent malicious user from inserting javascript. As usual, the mitigation was bypassed by using the following string `<scri<script>pt>`. As you can see, on receiving this string, sanitizer removes substring `<script>`, which results in concating the remaining parts thereby generating the intended string `<script>`.

<iframe width="640" height="360" src="https://web.microsoftstream.com/embed/video/6b66ca13-12ab-4bde-9f97-1150234ae3aa?autoplay=false&amp;showinfo=true&amp;st=4" allowfullscreen style="border:none;"></iframe>
