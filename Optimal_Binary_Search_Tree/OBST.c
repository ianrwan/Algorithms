#include "stdio.h"
#include "stdlib.h"

#define MAX 5 // max number of array elements

void print2DArray(int **array, int m, int n)
{
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
            printf("% 3d ", array[i][j]);
        printf("\n");
    }
    printf("\n");
}

int** make2DArray(int m, int n)
{
    int** array = (int**)malloc(m*sizeof(int*));
    for(int i = 0 ; i < n ; i++)
    {
        array[i] = (int*) malloc(n*sizeof(int));
    }

    // 初始化
    for(int i = 0 ; i < m ; i++)
        for(int j = 0 ; j < n ; j++)
            array[i][j] = -1;

    return array; 
}

int obst(int *pi, int *qi, int n)
{
    int** cost = make2DArray(n+1, n+1);
    int** weight = make2DArray(n+1, n+1);
    int** root = make2DArray(n+1, n+1);

    // 設定初值
    for(int i = 0 ; i <= n ; i++)
    {
        cost[i][i] = qi[i];
        weight[i][i] = qi[i];
        root[i][i] = 0;     
    }

    for(int a = 1 ; a <= n ; a++) // 做 n 次會將陣列完成
    {
        for(int i = 0 ; i <= n-a ; i++)  
        {
            int j = i+a; // 斜線必須先做，才換下一個斜線
            weight[i][j] = weight[i][j-1]+pi[j]+qi[j]; 
            
            int minCost = __INT_MAX__; // min i < k <= j 求最小 cost
            int minCostRoot = -1; // 紀錄 root 為哪一個
            for(int k = i+1 ; k <= j ; k++)
            {
                if(minCost > cost[i][k-1]+cost[k][j])
                {
                    minCost = cost[i][k-1]+cost[k][j];
                    minCostRoot = k;
                }
            }
            cost[i][j] = minCost+weight[i][j];
            root[i][j] = minCostRoot;
        }
    }
    print2DArray(root, n+1, n+1);

    return cost[0][n];
}

int main()
{
    int pi[MAX] = {0, 5, 2, 4, 3}; // sucessfull weight
    int qi[MAX] = {3, 2, 3, 4, 2}; // unsucessfull weight

    int optimal = obst(pi, qi, MAX-1);
    printf("optimal: %d", optimal);
}