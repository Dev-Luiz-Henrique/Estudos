/*
    Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

    If target is not found in the array, return [-1, -1].
    You must write an algorithm with O(log n) runtime complexity.
*/

#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* out = (int*) malloc (sizeof(int) * 2);
    out[0] = -1; out[1] = -1;
    *returnSize = 2;

    int start = 0, end = numsSize-1;
    while(start <= end){
        if(nums[start] == target){
            out[0] = start;
            for(int i = start; i < numsSize; i++){
                if(nums[i] == target) 
                    out[1] = i;
            }
            break;
        } 
        start++;
        if(nums[end] == target){
            out[1] = end;
            for(int i = end; i >= 0; i--){
                if(nums[i] == target)
                    out[0] = i;
            }
            break;
        }   
        end--;
    }
    return out;
}

int main(){
    return 0;
}