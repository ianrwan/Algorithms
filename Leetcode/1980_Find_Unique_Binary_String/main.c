#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

/*
思考方式：
如果陣列儲存的是 n 個 bits，且陣列也存取 n 筆資料，則回傳不在陣列的二位元字串
如:
A = ["010", "100", "111"] 又 "000" 不在 A 中，則可回傳 "000"，亦可回傳 "001", "100" ... 等不在陣列的二位元字串

因為 n 的範圍為 1~16 bits 之間，不會超過 int 4 bytes 的範圍，所以可以先將 string 轉為 int
轉為 int 的數字存取到 hashmap，採用 linear probing 的方式存取，之後再 linear search 找出不再陣列的裡的值
 */

int *binaryDecimal = NULL;

void setBinaryDecimal(int numsSize)
{
    binaryDecimal = (int*)malloc(sizeof(int)*numsSize);
    for(int i = 0 ; i < numsSize ; i++)
    {
        binaryDecimal[i] = pow(2,i);
    }
}

int stringToBinary(char *binaryString, int numsSize)
{
    int temp = 0;
    for(int i = 0 ; i < numsSize ; i++)
    {
        if(binaryString[numsSize-i-1] != '0')
        {
            temp += binaryDecimal[i];
        }
    }

    return temp;
}

char* decimalToBinaryString(int nums, int numsSize)
{
    char *temp = (char*)malloc(sizeof(nums)*(numsSize+1));
    for(int i = 0 ; i < numsSize ; i++)
    {
        temp[i] = '0';
    }

    if(nums == 0)
    {
        temp[numsSize] = '\0';
        return temp;
    }
    
    int numsRange = (int)log2(nums)+1;
    for(int i = numsSize-1 ; i >= numsSize-numsRange ; i--)
    {
        if(nums % 2 == 0) temp[i] = '0';
        if(nums % 2 == 1) temp[i] = '1';
        nums /= 2;
    }
    temp[numsSize] = '\0';
    
    return temp;
}

char* findDifferentBinaryString(char** nums, int numsSize) 
{
    int *numsData = (int*)calloc(pow(2,numsSize),sizeof(int));
    setBinaryDecimal(numsSize);

    for(int i = 0 ; i < numsSize ; i++)
    {
        int temp = stringToBinary(nums[i], numsSize);
        numsData[temp] = 1;        
    }

    for(int i = 0 ; i < pow(2, numsSize) ; i++)
    {
        if(numsData[i] == 0)
        {
            return decimalToBinaryString(i, numsSize);
        }
    }
    return NULL;
}

int main(void)
{
    // setBinaryDecimal(5);
    // printf("%d",stringToBinary("10111", 5));
    char *nums[2] = {"11", "10"};
    char *ans = findDifferentBinaryString(nums, 2);
    // char *p = decimalToBinaryString(22, 10);
    printf("%s", ans);
    // printf("%d", (int)(log2(10)));
}
