#ifndef FUNCTIONS_H
#define FUNCTIONS_H
char *myItoa(long int num, int base);
char *myHex(int number, int counter);
char *myUtoa(unsigned int n, int size);
char *longHex(long *decimal, int size);
char *myNegativeHex(unsigned int number, int size);
int numSize(long int num);
#endif