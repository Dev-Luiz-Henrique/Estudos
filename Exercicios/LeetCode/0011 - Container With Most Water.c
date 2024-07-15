/*
    You are given an integer array height of length n. 
    There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

    Find two lines that together with the x-axis form a container, such that the container contains the most water.
    Return the maximum amount of water a container can store.
    Notice that you may not slant the container.
*/

#include <math.h>

// Two Pointers
int maxArea(int* height, int heightSize) {
    int max = 0, left = 0, right = heightSize - 1;
    while(left < right){
        int w = fmin(height[left], height[right]) * (right - left);
        if(w > max) max = w;

        if (height[left] < height[right]) left++;
        else right--;
    }
    return max;
}

int main() {
    return 0;
}

/* BruteForce - TimeOut
int maxArea(int* height, int heightSize) {
    int max = 0;
    for(int i=0; i < heightSize; i++){
        for(int j=1; j < heightSize; j++){
            int w = fmin(height[i], height[j]) * (j - i);
            if(w > max) max = w;
        }
    }
    return max;
}
*/