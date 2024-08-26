/*
    Given an absolute path for a Unix-style file system, which begins with a slash '/', 
        transform this path into its simplified canonical path.

    In Unix-style file system context, a single period '.' signifies the current directory, 
        a double period ".." denotes moving up one directory level, and multiple slashes such as "//" 
        are interpreted as a single slash. In this problem, treat sequences of periods not covered by the previous 
        rules (like "...") as valid names for files or directories.

    The simplified canonical path should adhere to the following rules:
        It must start with a single slash '/'.
        Directories within the path should be separated by only one slash '/'.
        It should not end with a slash '/', unless it's the root directory.
        It should exclude any single or double periods used to denote current or parent directories.

    Return the new path.
*/

#include <stdlib.h>
#include <string.h>

char* simplifyPath(char* path) {
    int len = strlen(path);
    // Allocate memory for stack
    char *stk = (char*) malloc ((len+1)*sizeof(sizeof(char))); 
    int top = 0;
    stk[0] = path[0]; // Initialiaze stack with first path character ('/')

    for(int i=1; i < len; i++){
        // Case "//" or "/<EndOfString(\0)>"
        if(path[i]=='/' && (stk[top]=='/' || path[i+1]=='\0' || top==0))
            continue;
        // Case "/../"  or "/..<EndOfString(\0)>""   
        if(path[i-1] == '/' && path[i] == '.'  && path[i+1] == '.' && (path[i+2] == '/' || path[i+2] == '\0')){
            if(i != 1 && top != 0)
                top--; // Remove last '/' of "/../"
            while(top >= 0 && stk[top] != '/')
                top--;
            i+=2;
        }
        // Case /. or /./
        else if(path[i-1] == '/' && path[i] == '.'  && (path[i+1] == '/' || path[i+1] == '\0')){
            if(i != 1 && top != 0) 
                top--;
        }
        else 
            stk[++top] = path[i];
        
        stk[top+1] = '\0';
    }
    // If there is a '/' remaining in the end removes it
    if(top >0 && stk[top]=='/')
        top--;

    stk[top+1] = '\0'; // Define EndOfString(\0) in top+1 
    return stk; 
}

int main(){
    return 0;
}