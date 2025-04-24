// Given a string s, find the length of the longest substring without repeating characters.

#include <stdlib.h>
#include <math.h>

int lengthOfLongestSubstring(char* s) {
    int start = 0, maxLen = 0;
    int charIndex[128] = {0}; // Occurrence array

    for(int i = 0; s[i]; i++) {
        if(charIndex[s[i]] > start) 
            start = charIndex[s[i]];

        charIndex[s[i]] = i + 1; // Add occurrence
        maxLen = fmax(maxLen, i - start + 1); 
    }
    return maxLen;
}

int main(){
    return 0;
}