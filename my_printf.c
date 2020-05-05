#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

int my_printf(char * restrict format, ...);
char* myItoa(int num, char* str, int base);
char* myHex(int number);
char * myUtoa(unsigned int n);
char* longHex(unsigned long *decimal);

int main() {
    
    int a;
    my_printf("Hello %s %s!\n", "Mr", "Gaetan");
    //printf("%c!\n", 'H');

    return 0;
}

int my_printf(char * restrict format, ...) {

    char *ptr;

    va_list objectsList;
    int length = 0;

    va_start(objectsList, format);
    
    for (ptr = format; *ptr != '\0'; ptr++) {
        while(*ptr != '%'){         //go through format
            if(*ptr != '\0'){
                write(1, ptr, 1);
                ptr++;
                length++;
            }  else {
            break;
            }
        }

        if(*ptr == '\0'){               //break after format is printed
            break;
        }

        ptr++;
        char *tmp;
        if (*ptr == 's') {              //%s and NULL      
        
            char* string = va_arg(objectsList, char*);
            tmp = malloc(sizeof(string));
            tmp = string;

            if(string == NULL){
                tmp = "(null)";
                length+=6;
            } else {
                length+=strlen(tmp);
            }

        } else if (*ptr == 'd') {       //%d        

            int i = va_arg(objectsList, int);
            tmp = malloc(sizeof(i));
            myItoa(i, tmp, 10);
        
            length+=strlen(tmp);
        
        } else if (*ptr == 'o') {       //%o        

            int i = va_arg(objectsList, int);
            tmp = malloc(sizeof(i) * 2);
            myItoa(i, tmp, 8);

            length+=strlen(tmp);

        } else if (*ptr == 'u') {       //%u        

            int i = va_arg(objectsList, int);
            unsigned int b = i;
            tmp = malloc(sizeof(b));
            tmp = myUtoa(b);

            length+=strlen(tmp);
            
        } else if (*ptr == 'x') {       //%x        
            
            int i = va_arg(objectsList, int);
            tmp = malloc(sizeof(i));
            tmp = myHex(i);

            length+=strlen(tmp);

        } else if (*ptr == 'c') {       //%c         

            int i = va_arg(objectsList, int);
            tmp = malloc(sizeof(i));
            tmp = (char*)&i;
            length++;

        } else if (*ptr == 'p') {       //%p     

            void* str;
            str = va_arg(objectsList, void*);

            unsigned long int address;
            address = (unsigned long int)&str;
            
            tmp = (char*)longHex(&address);

            length+=strlen(tmp) + 2;
        }

        if(*ptr == 'p'){

            write(1, "0x", 3);
            write(1, tmp, strlen(tmp) + 1);

        } else {

            write(1, tmp, strlen(tmp));

        }
    
    }

    printf("%d", length);               //prints size of printf()
    va_end(objectsList);
    return 0;
}

char* myItoa(int num, char* str, int base) { 

    int i = 0; 
    bool isNegative = false; 
  
    //number is 0
    if (num == 0) { 
        str[i++] = '0'; 
        str[i] = '\0'; 
        return str; 
    } 
  
    //standart itoa()
    if (num < 0 && base == 10) { 
        isNegative = true; 
        num = -num; 
    } 
  
    while (num != 0) { 
        int rem = num % base; 
        if (rem > 9) {
            str[i++] = (rem - 10) + 'a';
        } else {
            str[i++] = rem + '0';
        }
        
        num = num/base; 
    } 
  
    //negative number
    if (isNegative == true){ 
        str[i++] = '-'; 
    }
    str[i] = '\0';
  
    //reverse the string  

    int f = 0;
    int j = strlen(str) - 1;
    char temp;

    while(f < j) {
        
        temp = str[f];
        str[f] = str[j];
        str[j] = temp;
        f++;
        j--;
    }
  
    return str; 
} 

char* myHex(int number){

    char *hexNumber = malloc((int)sizeof(number));
    int i = 0;
    bool isNegative = false;

    if(number < 0){
        isNegative = true;
        number = number * (-1);
    }

    while (number != 0) { //hex conversion
        
        int tmp = 0;
        tmp = number % 16;

        if (tmp < 10) {
            hexNumber[i] = tmp + 48;
            i++;
        } else {
            hexNumber[i] = tmp + 55;
            i++;
        }

        number = number / 16;
    }

    if(isNegative == true){
        hexNumber[i++] = '-';
    }
    hexNumber[i] = '\0';

    int f = 0;
    int j = strlen(hexNumber) - 1;
    char temp;

    while(f < j) { //reverse string
        
        temp = hexNumber[f];
        hexNumber[f] = hexNumber[j];
        hexNumber[j] = temp;
        f++;
        j--;
    }

    return hexNumber;
}

char* myUtoa(unsigned int n) {
  char *res, buffer[30];
  unsigned int i, counter = 0;

  if (n == 0)
    buffer[counter++] = '0';

  for ( ; n; n /= 10)
    buffer[counter++] = "0123456789"[n%10];

  res = malloc(counter);

  for (i = 0; i < counter; ++i)
    res[i] = buffer[counter - i - 1];

  return res;
}

char* longHex(unsigned long *decimal) {
    long q, r;
    int i, j = 0;
    char *hexadecimal = malloc((unsigned long)sizeof(decimal) * 10);
    
    q = *decimal;
    
    while (q != 0) {
        r = q % 16;          
        if (r < 10){
            hexadecimal[j++] = 48 + r;   
        } else {
            hexadecimal[j++] = 55 + r;  
        } 
        q = q / 16;            
    }
    
    int tmp = 0;
    int f = 0;
    int k = strlen(hexadecimal) - 1;

    while (f < k) {

        tmp = hexadecimal[f];
        hexadecimal[f] = hexadecimal[k];
        hexadecimal[k] = tmp;
        f++;
        k--;
    }

    for(int i = 0; i <= strlen(hexadecimal); i++){ 
        if(hexadecimal[i] >= 65 && hexadecimal[i] <= 90){
            hexadecimal[i] = hexadecimal[i] + 32;
        }
    }
    
    return hexadecimal;
}