#include <dlfcn.h>
#include <stdio.h>
#include "lib1.h"

static char specialVar[16];

void setSpecialVar();
void showSpecialVar();

void setSpecialVar() {
#ifdef SPECIAL_CONTENT
  snprintf(specialVar, 16, "special content");
#else
  snprintf(specialVar, 16, "default content");
#endif
  printf("[lib1] setting '%s' at %p\n", specialVar, specialVar);
}

void showSpecialVar() {
  printf("[lib1] showing '%s' at %p\n", specialVar, specialVar);
}

#ifdef SPECIAL_CONTENT
void useLib1Special() {
#else
void useLib1Default() {
#endif
  printf("[lib1] using '%s' from %p\n", specialVar, specialVar);
}

void enterLib1() {
  printf("[lib1] enter\n");
  setSpecialVar();

#ifdef SPECIAL_CONTENT
  useLib1Special();
#else
  useLib1Default();
#endif

  void* pHandle = dlopen("lib2.so", RTLD_NOW);
  if (!pHandle) {
    printf("[lib1][error] dlopen lib2 failed\n");
    return;
  }
  void* (*pFunc)(void) = dlsym(pHandle, "useLib2");
  if (!pFunc) {
    printf("[lib1][error] dlsym useLib2 failed\n");
    dlclose(pHandle);
    return;
  }
  pFunc();

  showSpecialVar();
  printf("[lib1] exit\n");
  dlclose(pHandle);
}
