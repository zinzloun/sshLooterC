//compile it with
// gcc callLooter.c -o callLooter -m32 -ldl
//the m32 switch is optional, for 32bit arch compilation on 64bit system
 
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
int main()
{
  void *lib;
  void (*extsendMessage)(char (*message)[]);
  //test message
  char buf[] = "$alvini fat dé in te cul!"; 
  //load external library
  lib = dlopen("./looter.so", RTLD_LAZY);
  if ( lib != NULL ) {
    *(void **)(&extsendMessage) = dlsym(lib, "sendMessage");
    extsendMessage(&buf);
  } else {
    //something bad....
    printf("Error: %s\n",dlerror());
  }
  //exit
  if (lib != NULL ) dlclose(lib);
  return EXIT_SUCCESS;
}
