/*
    Given an integer x, return true if x is a palindrome, and false otherwise.
*/

#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0) return false;
    int rev = 0;
    long long int tmp = x;
    while (tmp != 0) {
        rev = rev * 10 + tmp % 10;
        tmp /= 10;
    }
    return (rev == x);
}

int main() {
    return 0;
}