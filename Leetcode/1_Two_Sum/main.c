#include<stdio.h>
#include<stdlib.h>

#define NumSize 3
#define Target 6

/*
以 nums = [2,7,11,15], target = 9 為例
一開始先搜尋 nums[0] (2), 並且將 target-nums[0] (7), 得到 7 之再往後搜尋有沒有對應的數字

如果沒有搜尋到對應的數字則跳到 nums[1], target 減掉之後再往下繼續比較
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    *returnSize = 2;
    int *returnNums = (int*)malloc(sizeof(int)*(*returnSize));
    
    for(int i = 0 ; i < numsSize ; i++)
    {
        int temp = target - nums[i];
        for(int j = i+1 ; j < numsSize ; j++)
        {
            if(nums[j] == temp)
            {
                returnNums[0] = i;
                returnNums[1] = j;
                return returnNums; 
            }
        }
    }
    return NULL;
}

int main(void)
{
    int nums[NumSize] = {3,2,4};
    int value;
    int *returnSize = &value;
    int *returnNums = twoSum(nums, NumSize, Target, returnSize);
    printf("[%d, %d]", returnNums[0], returnNums[1]);
}