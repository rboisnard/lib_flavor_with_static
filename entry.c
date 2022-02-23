#include <dlfcn.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  if (argc > 0) {
    for (int arg = 0; arg < argc; ++arg) {
      printf("[entry] arg %d: '%s'\n", arg, argv[arg]);
    }
  }

  printf("[entry] enter\n");

  void* pHandle = dlopen("lib1S.so", RTLD_NOW);
  if (!pHandle) {
    printf("[entry][error] dlopen lib1S failed\n");
    return 1;
  }
  void* (*pFunc)(void) = dlsym(pHandle, "enterLib1");
  if (!pFunc) {
    printf("[entry][error] dlsym enterLib1 failed\n");
    dlclose(pHandle);
    return 1;
  }
  pFunc();
  dlclose(pHandle);

  printf("[entry] exit\n");
}