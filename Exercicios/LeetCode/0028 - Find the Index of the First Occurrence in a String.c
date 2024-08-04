/*
    Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, 
        or -1 if needle is not part of haystack.
*/

int strStr(char* haystack, char* needle) {
    int index = -1, curr = 0;
    // While haystack[i] != '\0' (single false)
    for(int i=0; haystack[i]; i++){
        if(needle[curr] == haystack[i]){
            if(index == -1) index = i; 
            if(!needle[++curr]) return index;
        }
        else {
            if(index != -1) i = index;
            index = -1;
            curr = 0;
        }
    }
    return -1;
}

int main(){
    return 0;
}