/*
    Given a signed 32-bit integer x, return x with its digits reversed. 
    If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

    Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
*/

#include <limits.h>

int reverse(int x){
    long int y = 0; 
    while(x != 0){
        y = y * 10 + x % 10;
        x /= 10;
    }
    if(y > INT_MAX || y < INT_MIN) return 0;
    return y;
}

int main(){
    return 0;
}



int myAtoi(char* s) {
    int sign = 1, isStart = 1;
    long int num = 0;
    for(int i=0; s[i]; i++){
        // Only up to position 57 in the ASCII table, except '.'
        if(s[i] > '9' || s[i] == '.') break; 
        if((s[i] == '+' || s[i] == '-') && isStart == 0) break;
        if(s[i] == ' ') continue;
        if(s[i] == '-') sign = -1;
        else if(s[i] != '+'){
            num = num * 10 + (s[i] - '0');
            if(num * sign < INT_MIN) return INT_MIN;
            if(num > INT_MAX) return INT_MAX;
        }
        isStart = 0;
    }
    return num * sign;
}