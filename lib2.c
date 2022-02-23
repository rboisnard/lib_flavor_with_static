#include <stdio.h>
#include "lib1.h"
#include "lib2.h"

void useLib2() {
  useLib1Default();
  printf("[lib2] using\n");
}