#!/bin/sh

mkdir -p build

   gcc -c -Wall -Werror -Wextra -fpic -O3 -DSPECIAL_CONTENT=1 lib1.c -o build/lib1S.o \
&& gcc -shared -o build/lib1S.so build/lib1S.o                                        \
&& gcc -c -Wall -Werror -Wextra -fpic -O3 lib1.c -o build/lib1D.o                     \
&& gcc -shared -o build/lib1D.so build/lib1D.o                                        \
&& gcc -c -Wall -Werror -Wextra -fpic -O3 lib2.c -o build/lib2.o                      \
&& gcc -shared -o build/lib2.so build/lib2.o -Lbuild -l1D                             \
&& gcc -c -Wall -Werror -Wextra -fpic -O3 entry.c -o build/entry.o                    \
&& gcc -o build/run_test build/entry.o -ldl                                           \
&& echo "ok"