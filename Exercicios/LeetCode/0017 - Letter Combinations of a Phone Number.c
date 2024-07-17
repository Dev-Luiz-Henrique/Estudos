/*
    Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
    Return the answer in any order.

    A mapping of digits to letters (just like on the telephone buttons) is given below. 
    Note that 1 does not map to any letters.
*/

#include <stdlib.h>
#include <string.h>

char *letters[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void generateCombinations(char* digits, int index, char* current, char** combs, int* returnSize) {
    // Base case: If we have processed all digits, add the current combination to the result
    if(index == strlen(digits)) {
        combs[*returnSize] = strdup(current);
        (*returnSize)++;
        return;
    }

    // Otherwise, try all possible letters for the current digit
    int digit = digits[index] - '2';
    for(int i = 0; i < strlen(letters[digit]); i++) {
        current[index] = letters[digit][i];
        generateCombinations(digits, index + 1, current, combs, returnSize);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    int len = strlen(digits);
    if(len == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Calculate the size of the return array
    int rows = 1;
    for(int i=0; digits[i]; i++)
        rows *= strlen(letters[digits[i] - '2']);
    
    // Allocate memory for the return array
    char** combs = (char**) malloc (rows * sizeof(char*));
    char*  curr  = (char*)  malloc ((len + 1) * sizeof(char));
    curr[len] = '\0';  // Null-terminate the string

    // Generate all combinations
    *returnSize = 0;
    generateCombinations(digits, 0, curr, combs, returnSize);
    free(curr);
    return combs;
}

int main(){
    return 0;
}