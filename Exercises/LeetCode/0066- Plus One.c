/*
    You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. 
    The digits are ordered from most significant to least significant in left-to-right order. 
    The large integer does not contain any leading 0's.

    Increment the large integer by one and return the resulting array of digits.
*/

#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry, i = digitsSize - 1, size = digitsSize;
    digits[i] += 1;
    
    while(digits[i] > 9){
        carry = digits[i] / 10;
        digits[i] %= 10;
        i--;
        if(i < 0) {
            size++;
            int *result = (int*) malloc (sizeof(int) * size);
            result[0] = carry;
            for(int j=1; j < size; j++)
                result[j] = digits[j-1];
            *returnSize = size;
            return result;
        }
        digits[i] += carry;
    }
    *returnSize = size;
    return digits;
}

int main(){
    return 0;
}