/*
    Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects 
        of the same color are adjacent, with the colors in the order red, white, and blue.

    We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

    You must solve this problem without using the library's sort function.
*/

void sortColors(int* nums, int numsSize) {
    for(int i=0; i < numsSize; i++){
        for(int j=0; j < numsSize; j++){
            if(nums[j] > nums[i]){
                int tmp = nums[j];
                nums[j] = nums[i];
                nums[i] = tmp;
            }
        }
    }
}

int main(){
    return 0;
}