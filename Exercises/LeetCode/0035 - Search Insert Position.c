/*
    Given a sorted array of distinct integers and a target value, return the index if the target is found. 
    If not, return the index where it would be if it were inserted in order.

    You must write an algorithm with O(log n) runtime complexity.
*/

int searchInsert(int* nums, int numsSize, int target) {
    int first = 0, last = numsSize - 1, middle;

    while(first <= last){
        middle = (first+last) / 2;
        if(nums[middle] == target) return middle;
        if(nums[middle] > target) last = middle - 1;
        else first = middle + 1;
    }
    return first;
}