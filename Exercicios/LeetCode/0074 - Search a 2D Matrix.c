/*
    You are given an m x n integer matrix matrix with the following two properties:
        Each row is sorted in non-decreasing order.
        The first integer of each row is greater than the last integer of the previous row.

    Given an integer target, return true if target is in matrix or false otherwise.

    You must write a solution in O(log(m * n)) time complexity.
*/

#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int startCol = 0, endCol = matrixSize-1, midCol;
    int startRow = 0, endRow = matrixColSize[0]-1, midRow;

    while(startCol <= endCol){            
        midCol = (startCol + endCol) / 2; 
        
        if (target >= matrix[midCol][startRow] && target <= matrix[midCol][endRow]) {
            while(startRow <= endRow){
                    midRow = (startRow + endRow) / 2;
                    if(target == matrix[midCol][midRow]) 
                        return true;
                    if(target < matrix[midCol][midRow]) 
                        endRow = midRow - 1; 
                    else 
                        startRow = midRow + 1;
            }
            return false;
        }          
        if(target < matrix[midCol][startRow])
            endCol = midCol - 1; 
        else
            startCol = midCol + 1;
    }
    return false;
}

int main(){
    return 0;
}