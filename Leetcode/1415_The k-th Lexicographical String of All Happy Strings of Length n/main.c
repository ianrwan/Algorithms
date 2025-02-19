#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

/*
思考方向:

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

/*
combine function:

1. input parameter:
previous: 被合成的字串
inputChar: 被合成的字元
length: previous 字串長度

2. output: 合成的字串

將 previous 的字串與 inputChar 字元合併再一起
例如:
previous = "ab"
inputChar = 'c'

則 return "abc"
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
    int current1DLen = 0; // 存取目前的字串所需的陣列大小（亦即字串的所有排列組合）
    int previous1DLen = 0; // 存取上一筆字串所需的陣列大小（亦即字串的所有排列組合）
    char **current = NULL; // 存取目前的字串陣列
    char **previous = NULL; // 存取上一筆的字串陣列

    // 如果要求的 k 值超過 n 則回傳空字串
    if(k > 3*pow(2,n-1))
        return "";

    for(int i = 0 ; i < n ; i++)
    { 
        previous1DLen = current1DLen; 
        current1DLen = 3*pow(2, i); // i 個字元所有的排列組合

        previous = current;
        current = (char**)malloc(sizeof(char*)*current1DLen); 

        // 初始化
        if(i == 0)
        {
            current[0] = "a";
            current[1] = "b";
            current[2] = "c";
        }
        else
        {
            // 看上一筆字串有哪些字串, 並看每個字串最後一個字元決定最後一個字元的下一個字元要填的內容
            // 如 previous = ["ab", "ac"...] 則 current = ["aba", "abc", "aca", "acb"...]
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
    }
    
    return current[k-1];
}


int main(void)
{
    char* output = getHappyString(1, 4);
    printf("%s", output);
}