#include "hex.c"
#include "func.c"

char *myItoa(long int num, char *str, int base);
char *myHex(int number, int counter);
char *myUtoa(unsigned int n, int size);
char *longHex(unsigned long *decimal, int size);
char *myNegativeHex(unsigned int number, int size);
int numSize(long int num);