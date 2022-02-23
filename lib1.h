#ifndef _LIB1_H
#define _LIB1_H

void enterLib1();
#ifdef SPECIAL_CONTENT
void useLib1Special();
#else
void useLib1Default();
#endif

#endif // _LIB1_H