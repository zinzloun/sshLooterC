# sshLooterC forked
<pre>
https://github.com/mthbernardes/sshLooterC<br/>

# Changes from the original project
* Removed libcurl4-openssl-dev dependency, now using system("wget ...")
* Compiled for 32bit arch, should work for 64bit as well, 
you need to install gcc-multilib on the attacker machine
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
See the original project, please note that you have to modify the /etc/pam.d/common-auth file 
inserting looter.so, according to the compilation instructions
</pre>

# Credits
<a href="https://mthbernardes.github.io/persistence/2018/02/10/stealing-ssh-credentials-another-approach.html" target="_blank">Stealing SSH credentials Another Approach.</a>
<br/>
Thank you

 
