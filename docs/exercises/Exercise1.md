# Exercises sheet 1

## Intro to CIA/AAA/Threat/Security Principles
1. Let us assume tha mayor of Bristol wants to release a public notice on an important issue. Which of the CIA properties should be enforced and why?

2. Explain why someone need not worry about being a victim of a social engineering attack through their cell phone if they are inside of a Faraday cage.

3. With respect to the C.I.A. and A.A.A. concepts, what risks are posed by Trojan horses?

4. With respect to the C.I.A. and A.A.A. concepts, what risks are posed by someone making so many download requests from an online music store that it prevents other users from being able to download any songs?
	
5. Give an example of the false sense of security that can come from using the “security by obscurity” approach.

6. The HF Corporation has a new refrigerator, the Monitator, which has a camera that takes a picture of the contents of the refrigerator and uploads it to the HF Corporation’s web site. The Monitator’s owner can then access this web site to see what is inside their refrigerator without opening the door. For security reasons, the HF Corporation encrypts this picture using a proprietary algorithm and gives the 4-digit PIN to decrypt this picture to the Monitator’s owner, so he or she can get access to the pictures of their Monitator’s interior. What are the security concerns and principles that this solution does and doesn’t support?
7. Consider a desktop publishing system used to produce documents for various organizations.
a. Give an example of a type of publication for which confidentiality of the stored data is the most important requirement.
b. Give an example of a type of publication in which data integrity is the most impor- tant requirement.
c. Give an example in which system availability is the most important requirement.

8. For each of the following assets, assign a low, moderate, or high impact level for the loss of confidentiality, availability, and integrity, respectively. Justify your answers. 
a. An organization managing public information on its Web server.
b. A law enforcement organization managing extremely sensitive investigative information.
c. A financial organization managing routine administrative information (notprivacy-related information).
d. An information system used for large acquisitions in a contracting organization contains both sensitive, pre-solicitation phase contract information and routine administrative information. Assess the impact for the two data sets separately and the information system as a whole.
e. A power plant contains a SCADA (supervisory control and data acquisition) system controlling the distribution of electric power for a large military installation. The SCADA system contains both real-time sensor data and routine admin- istrative information. Assess the impact for the two data sets separately and the information system as a whole.


## Answers
- **ANS A.1:** Integrity and Availability. **I** because none should be able to alter it in unintended way and **A** because it should be available to the public to see.
- **ANS A.2:** becuase there will be no signal to get connected to the site if that was the intention of the attacker.
- **ANS A.3:** a trojan horse can violate all of the CIA, by leaking info,modifying files, and deleting files. For AAA, it can sabotage authenticity. 
- **ANS A.4:** CIA- availability, AAA- Accountability.
- **ANS A.5:** using a encryption scheme that is not public, thinking that no one will break it if they don't know about. Anothe example is hard coded secrets in the binary thinking that no one will know about them.
- **ANS A.6:** It is simple desigin, thus *economy of mechanism* prnciple is followed. However, proprietary encryption shceme is a bad idea (*Open design* principle). Protecting it with a PIN is good (confidentiality and Assurance). However, 4-digit PIN may be a weak protection.
- **ANS A.7:** a. The system will have to assure confidentiality if it is being used to publish corporate proprietary material.
b. The system will have to assure integrity if it is being used to laws or regulations.
c. The system will have to assure availability if it is being used to publish a daily paper.
- **ANS A.8:** a. An organization managing public information on its web server determines that there is no potential impact from a loss of confidentiality (i.e., confidentiality requirements are not applicable), a moderate potential impact from a loss of integrity, and a moderate potential impact from a loss of availability.
b. A law enforcement organization managing extremely sensitive investigative information determines that the potential impact from a loss of confidentiality is high, the potential impact from a loss of integrity is moderate, and the potential impact from a loss of availability is moderate.
c. A financial organization managing routine administrative information (not privacy-related information) determines that the potential impact from a loss of confidentiality is low, the potential impact from a loss of integrity is low, and the potential impact from a loss of availability is low.
d. The management within the contracting organization determines that: (i) for the sensitive contract information, the potential impact from a loss of confidentiality is moderate, the potential impact from a loss of integrity is moderate, and the potential impact from a loss of availability is low; and (ii) for the routine administrative information (non-privacy-related information), the potential impact from a loss of confidentiality is low, the potential impact from a loss of integrity is low, and the potential impact from a loss of availability is low.
e. The management at the power plant determines that: (i) for the sensor data being acquired by the SCADA system, there is no potential impact from a loss of confidentiality, a high potential impact from a loss of integrity, and a high potential impact from a loss of availability; and (ii) for the administrative information being processed by the system, there is a low potential impact from a loss of confidentiality, a low potential impact from a loss of integrity, and a low potential impact from a loss of availability. 

