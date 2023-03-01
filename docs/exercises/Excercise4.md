# Exercises sheet 4

## WEB Security

1. What is the impact of a successful SQL injection attack? Do you know any SQL injection examples?

2. What are the types of XSS attacks? Explain! What is the difference between them?

3. List three design goals for a firewall.

4. What are some weaknesses of a packet filtering firewall?

5. What is the difference between a packet filtering firewall and a stateful inspection firewall?

6. One approach to defeating the tiny fragment attack is to enforce a minimum length of the transport header that must be contained in the first fragment of an IP packet. If the first fragment is rejected, all subsequent fragments can be rejected. However, the nature of IP is such that fragments may arrive out of order. Thus, an intermediate fragment may pass through the filter before the initial fragment is rejected. How can this situation be handled?

7. A common management requirement is that “all external Web traffic must flow via the organization’s Web proxy.” However, that requirement is easier stated than implemented. Discuss the various problems and issues, possible solutions, and limitations with supporting this requirement. In particular consider issues such as identifying exactly what constitutes “Web traffic” and how it may be monitored, given the large range of ports and various protocols used by Web browsers and servers.7. What are two common techniques used to protect a password file?

8. Why is it useful to have host-based firewalls?

9. What are three benefits that can be provided by an intrusion detection system?

10. What is the difference between statistical anomaly detection and rule-based intrusion detection?

11. What metrics are useful for profile-based intrusion detection?

12. An example of a host-based intrusion detection tool is the tripwire program (you can google about it). This is a file integrity checking tool that scans files and directories on the system on a regular basis and notifies the administrator of any changes. It uses a protected database of cryptographic checksums for each file checked and compares this value with that recomputed on each file as it is scanned. It must be configured with a list of files and directories to check, and what changes, if any, are permissible to each. It can allow, for example, log files to have new entries appended, but not for existing entries to be changed. What are the advantages and disadvantages of using such a tool? Think! Consider the problem of determining which files should only change rarely, which files may change more often and how, and which change frequently and hence cannot be checked. Hence consider the amount of work in both the configuration of the program and on the system administrator monitoring the responses generated.
