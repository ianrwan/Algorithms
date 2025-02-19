#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

/*
n 是得到 happy string 的長度
k 是要得到的第幾個 happy string

例:
n = 2, happy string 的長度為 2 字元 [ab, ac, ba, bc, ca, cb]
k = 3, 第三個字組則為 "ba"

利用陣列存取資料
1, 以 DP 的方法存取資料 A[0] = [a, b, c], A[1] = [ab, ac, ba, bc, ...], A[2] = [aba, abc, ....] 
2, 指向每一個字串最後一個字元，並且將與最後一個字元不同的字元合在一起，然後再填入新的陣列
3, A[0] = [a, b, c] A[0][0] = 'a' => 得到 'b', 'c' 與 'a' 不同，所以會得到 "ab", "ac" 的字串
4, 將上面的字串存到 A[2]
5, A[1] = [ab, ac, ...]
*/

char* combine(char* previous, char inputChar, int length)
{
    int i = 0;
    char *buffer = (char*)malloc(sizeof(char)*(length+2));
    while(previous[i] != '\0')
    {
        buffer[i] = previous[i];
        i++;
    }
    buffer[i++] = inputChar;
    buffer[i] = '\0';
    return buffer;
}

char* getHappyString(int n, int k)
{
    int current1DLen = 0;
    int previous1DLen = 0;
    char **current = NULL;
    char **previous = NULL;

    if(k > 3*pow(2,n-1))
        return "";

    for(int i = 0 ; i < n ; i++)
    {
        previous1DLen = current1DLen;
        current1DLen = 3*pow(2, i);

        previous = current;
        current = (char**)malloc(sizeof(char*)*current1DLen);

        if(i == 0)
        {
            current[0] = "a";
            current[1] = "b";
            current[2] = "c";
        }
        else
        {
            for(int j = 0 ; j < previous1DLen ; j++)
            {   
                if(previous[j][i-1] == 'a')
                {
                    current[j*2] = combine(previous[j], 'b', i);
                    current[j*2+1] = combine(previous[j], 'c', i);
                    
                }
                else if(previous[j][i-1] == 'b')
                {
                    current[j*2] = combine(previous[j], 'a', i);
                    current[j*2+1] = combine(previous[j], 'c', i);
                }
                else if(previous[j][i-1] == 'c')
                {
                    current[j*2] = combine(previous[j], 'a', i);
                    current[j*2+1] = combine(previous[j], 'b', i);
                }
            }
        }

        for(int f = 0 ; f < current1DLen ; f++)
        {
            printf("%s\n", current[f]);
        }
        printf("\n");   
    }
    
    return current[k-1];
}


int main(void)
{
    char* output = getHappyString(1, 4);
    printf("%s", output);
}