# Exercises sheet 10


1. What evidence do you see that convinces us that Linux OS provides DAC?
	
2. Can you think of situation where RBAC makes more sense in a real-world scenario? [Hint: employee promotions in an organization!]

3. Suppose that you created a file my-data.txt and you want to provide a read only access to this file to any other user. What command you do use.

4. What is the main purpose of providing the mechanism of Set-User ID?

5. Segmentation based-techniques cannot provide finer level protection, whereas page-level protections can do. Can you explain (justify) the statement? 

## Answers

1. **ANS:** As a owner of a file, we can use chmod command to change its ACL.  Plus its called the UNIX DAC... and Linux is UNIX sort of?

2. **ANS:** If I promote an employee from _minion_ to _senior minion_ I just need to change the role they have active rather than redefining all the permissions for that employee.  When I feed them to the sharks later I can just revoke their access to that role just in case they escape and the sharks don't finish them off.

3. **ANS:** `chmod o-w my-data.txt`

_Note from Joseph:_ some clever person will say I should just set the permissions to `744` but for normal people who haven't internalised the relationship between octal numbers and the UNIX DAC this is just confusing and error prone… (especially when you start to deal with *masks*—we didn't even mention them here! See `man umask` and cry)  Luckily since the 90's there are *symbolic* permissions available which do all the translation between octal and masks for you.

- `o+r` - turns on the read permission for the other set of permissions
- `g-w` - turns off the write permissions for the group.
- `a-x` - turns off the execute permission for the user, group and other permissions
- `u+s` - turns on the sticky bit (see `man chmod`)

Please don't use the octal representation… the poor souls amongst you who spend too long on UNIX-esque systems will eventually internalise them, but we shouldn't inflict that on others unnecessarily!  The symbolic ones work **EVERYWHERE**, and we've moved forwards with usability since the 60s.  Now to go rename that silly `creat` systemcall…

4. **ANS:** To give a limited, per program way, of letting a user do trivial systems administration without bothering the sysadmin to do it for them.  That said we should give setuid programs a thorough audit 'cos if the user hacks one of them they've broken into the admin account the naughty so-and-so's!

5. **ANS:** Depends on how you set up the segments, the OS, and the computer architecture but in general it is easier to do low-level fiddling with permissions via pages because we can get the OS to enforce whatever policy we want when switching between them.  We then leave the segments for doing more general process isolation and for dealing with separation between rings or supervsior-mode/user-mode.  Pages also have access to physical memory banks which gives the opportunity for more tricks. Segments are also limited to addressing with a 16 bit register which further limits things too whereas pages are somewhat less constrained (its just a table in memory).

You could (of course) go and define some computer architecture where the opposite is true, or probably abuse segments and the GDT in a really interesting way to prove the opposite (go look up Windows's far and near pointers).  But in general its easier mucking about at the page level.

