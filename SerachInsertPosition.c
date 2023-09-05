#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int searchInsert(int* nums, int numsSize, int target){
    int i = 0, begin = 0, end = numsSize - 1, key = end / 2;
    for(i = 0; i < numsSize; i++){
        if(nums[key] > target)
            end = key - 1;
        else if(nums[key] < target)
            begin = key + 1;
        else return key;
        
        key = (begin + end) / 2;
    }
    if(nums[key] >= target)
        return key;
    else
        return key + 1; 
    
}

int main()
{
    int nums[4] = {1,3,5,6}, target = 5, numsSize = 4;
    int result = searchInsert(nums, numsSize, target);
    printf("%d", result);
}