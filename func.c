#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

int numSize(long int num);

char* myItoa(long int num, char* str, int base) { 

    int i = 0; 
    bool isNegative = false; 
  
    //number is 0
    if (num == 0) { 

        str[i] = '0';  
        str[i + 1] = '\0'; 
        return str;
    } else if (num < 0 && base == 10) {         //standart itoa()

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

    int k, j;
    char c;
 
    for (k = 0, j = strlen(str)-1; k<j; k++, j--) {
        c = str[k];
        str[k] = str[j];
        str[j] = c;
    }

    return str; 
} 


char* myHex(int number, int size){

    char *hexNumber = malloc(size);
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
    free(hexNumber);
}


char* myUtoa(unsigned int n) {
    char *res, buffer[numSize(n) + 1];
    unsigned int i, counter = 0;

    if (n == 0) {

        buffer[counter++] = '0';
    }

    for ( ; n; n /= 10) { 

        buffer[counter++] = "0123456789"[n%10];
    }

    res = malloc(counter + 1);

    for (i = 0; i < counter; ++i) {

        res[i] = buffer[counter - i - 1];
        
    } 

    res[counter] = '\0';
    
    return res;

    free(res);
}


char* longHex(unsigned long *decimal, int size) {
    long q, r;
    int i, j = 0;
    char *hexadecimal = malloc(size);
    
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
    free(hexadecimal);
}

int numSize(long int num) {

    int counter = 0;
    if (num < 0) {

        num = -num;

    } else if(num == 0){

        counter = 1;
    }

    while (num != 0) {
                
        num/=10;
        counter++;
    }

    return counter;
}