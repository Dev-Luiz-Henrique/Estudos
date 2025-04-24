/*
    Given a string s consisting of words and spaces, return the length of the last word in the string.
    
    A word is a maximal substring consisting of non-space characters only.
*/

int lengthOfLastWord(char* s) {
    int len = 1;
    for(int i=1; s[i]; i++){
        if(s[i] == ' ') continue;
        if(s[i-1] == ' ') len = 0;
        len++;
    }
    return len;
}

int main(){
    return 0;
}