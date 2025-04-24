/*
    Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

    The algorithm for myAtoi(string s) is as follows:

        Whitespace: Ignore any leading whitespace (" ").
        Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity is neither present.
        Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered 
            or the end of the string is reached. If no digits were read, then the result is 0.
        Rounding: If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], then round the integer to remain 
            in the range. Specifically, integers less than -2^31 should be rounded to -2^31, 
            and integers greater than 2^31 - 1 should be rounded to 2^31 - 1.
    Return the integer as the final result.
*/

#include <limits.h>

int myAtoi(char* s) {
    int sign = 1, isStart = 1;
    long int num = 0;
    for(int i=0; s[i]; i++){
        // Only up to position 57 in the ASCII table, except '.'
        if(s[i] > '9' || s[i] == '.') break; 
        if((s[i] == '+' || s[i] == '-' || s[i] == ' ') && isStart == 0) break;
        if(s[i] == ' ') continue;
        if(s[i] == '-') sign = -1;
        else if(s[i] != '+'){
            num = num * 10 + (s[i] - '0');
            if(num < INT_MIN || num > INT_MAX) 
                return sign == -1 ? INT_MIN : INT_MAX;
        }
        isStart = 0;
    }
    return num * sign;
}

int main(){
    return 0;
}