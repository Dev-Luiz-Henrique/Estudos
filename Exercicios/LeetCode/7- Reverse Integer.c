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
