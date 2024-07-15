/*
    Seven different symbols represent Roman numerals with the following values:
        Symbol	Value
           I	  1
           V	  5
           X	  10
           L	  50
           C	  100
           D	  500
           M	  1000

    Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. 
    Converting a decimal place value into a Roman numeral has the following rules:

        If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, 
            append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.

        If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, 
            for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms 
            are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).

        Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. 
            You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.
    
    Given an integer, convert it to a Roman numeral.
*/

#include <stdlib.h>
#include <string.h>

//
// Second Solution
//
char* intToRoman2(int num) {
    char* numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    // Allocate memory for largest Roman numeral
    char* roman = (char*) malloc (sizeof(char) * (15 + 1)); 
    int i = 0;
    roman[0] = '\0'; // Result = String empty

    while (num > 0) {
        while (num >= values[i]) {
            num -= values[i];
            // Use strcat because it is a string array and not a char array
            strcat(roman, numerals[i]);
        }
        i++;
    }
    return roman;
}

//
// First Solution
//
char* intToRoman(int num) {
    // Allocate memory for largest Roman numeral
    char* roman = (char*) malloc (sizeof(char) * (15 + 1)); 
    int i = 0;
    while(num > 0){
        if(num >= 1000){
            num -= 1000;
            roman[i] = 'M';
        }
        else if(num >= 900){
            num -= 900;
            roman[i] = 'C';
            roman[++i] = 'M';
        }
        else if(num >= 500){
            num -= 500;
            roman[i] = 'D';
        }
        else if(num >= 400){
            num -= 400;
            roman[i] = 'C';
            roman[++i] = 'D';
        }
        else if(num >= 100){
            num -= 100;
            roman[i] = 'C';
        }
        else if(num >= 90){
            num -= 90;
            roman[i] = 'X';
            roman[++i] = 'C';
        }
        else if(num >= 50){
            num -= 50;
            roman[i] = 'L';
        }
        else if(num >= 40){
            num -= 40;
            roman[i] = 'X';
            roman[++i] = 'L';
        }
        else if(num >= 10){
            num -= 10;
            roman[i] = 'X';
        }
        else if(num >= 9){
            num -= 9;
            roman[i] = 'I';
            roman[++i] = 'X';
        }
        else if(num >= 5){
            num -= 5;
            roman[i] = 'V';
        }
        else if(num >= 4){
            num -= 4;
            roman[i] = 'I';
            roman[++i] = 'V';
        }
        else {
            num -= 1;
            roman[i] = 'I';
        }
        i++;
    }
    roman[i] = '\0';
    return roman;
}

int main(){
    return 0;
}