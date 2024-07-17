/*
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    An input string is valid if:
        1- Open brackets must be closed by the same type of brackets.
        2- Open brackets must be closed in the correct order.
        3- Every close bracket has a corresponding open bracket of the same type.
*/

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//
// Implicit Stack Solution
//
bool isValid(char* s) {
    int len = strlen(s);
    char stk[len];
    int top = -1;

    for(int i=0; i < len; i++){
        if(s[i]=='(' || s[i] == '{' || s[i] == '[' ) 
            stk[++top] = s[i];
        else{
            if(top == -1) return false; // Impossible to remove item from empty stack
            if((s[i] == ')' && stk[top] != '(') || (s[i] == '}' && stk[top] != '{') || (s[i] == ']' && stk[top] != '['))
                return false;
            top--;
        } 
    }  
    return top == -1; 
}

//
// Explicit Stack Solution
//
typedef struct stack {
    int top;
    char* item; 
} *Stack;

bool empty(Stack S){
    if( S->top == -1 ) return 1;
    return 0;
}

void push(Stack S, char v){
    S->top++;
    S->item[S->top] = v;
}

char pop(Stack S){
    char r = S->item[S->top];
    S->top--;
    return r;
}

bool isValidd(char* s) {
    int len = strlen(s);
    Stack stk = (Stack) malloc (sizeof(struct stack) * len);
    stk->top = -1;
    stk->item = (char*) malloc (sizeof(char) * len);

    for(int i=0; i < len; i++){
        switch(s[i]){
            case '(': push(stk, ')'); break;
            case '[': push(stk, ']'); break;
            case '{': push(stk, '}'); break;
            default: 
                if(empty(stk) || s[i] != pop(stk)){
                    free(stk->item);
                    free(stk);
                    return false;
                }
        }
    }
    bool r = empty(stk);
    free(stk->item);
    free(stk);
    return r;
}

int main(){
    return 0;
}