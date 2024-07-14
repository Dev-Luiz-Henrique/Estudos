/*
    Write a function to find the longest common prefix string amongst an array of strings.

    If there is no common prefix, return an empty string "".
*/

#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    char* prefix = (char*)malloc(sizeof(char) * (strlen(strs[0]) + 1));
    int i = -1;

    do{
        i++;
        prefix[i] = strs[0][i];
        for(int j=0; j < strsSize; j++){
            if(!strs[j][i] || prefix[i] != strs[j][i]) 
                prefix[i] = '\0';
        }
    } while(prefix[i]);
    return prefix;
}

int main(){
    return 0;
}