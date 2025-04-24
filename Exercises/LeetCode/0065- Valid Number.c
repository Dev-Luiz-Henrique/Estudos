/*
    Given a string s, return whether s is a valid number.

    For example, all the following are valid numbers: "2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", 
        "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789", 
    while the following are not valid numbers: "abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53".

    Formally, a valid number is defined using one of the following definitions:
        An integer number followed by an optional exponent.
        A decimal number followed by an optional exponent.
        An integer number is defined with an optional sign '-' or '+' followed by digits.

    A decimal number is defined with an optional sign '-' or '+' followed by one of the following definitions:
        Digits followed by a dot '.'.
        Digits followed by a dot '.' followed by digits.
        A dot '.' followed by digits.
    
    An exponent is defined with an exponent notation 'e' or 'E' followed by an integer number.
    The digits are defined as one or more digits.
*/

#include <stdbool.h>
#include <ctype.h>

bool isNumber(char* s) {
    bool sign = false, exp = false, dot = false;
    for(int i=0; s[i]; i++){
        if(s[i] >= '0' && s[i] <= '9') continue;
        switch(s[i]){
            case '-':
            case '+':
                if(i>0 && strchr("eE", s[i-1]) && isdigit(s[i+1])) continue;
                if(!sign && i==0 && s[i+1] != '\0' && strchr("0123456789.", s[i+1])){
                    sign = true; continue;
                }
                return false;
            case '.':
                if(!dot && ((i > 0 && isdigit(s[i-1])) || isdigit(s[i+1])) && !exp){
                    dot = true;  continue;
                }
                else return false;
            case 'e':
            case 'E':
                if(!exp && i>0 && strchr("0123456789.", s[i-1]) 
                    && s[i+1] != '\0' && strchr("0123456789+-", s[i+1])){
                        exp = true;
                        continue;
                }
                else return false;
            default: 
                return false;
        }
    }
    return true;
}

int main(){
    return 0;
}