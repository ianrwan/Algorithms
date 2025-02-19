#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#define SIZE 3

int front, rear; // front 指向 queue 刪除端的前一格，rear 指向 queue 新增端

bool move(int* head) // 移動 queue 的 value 因為 queue 會因為 dequeue 而造成 array space 的浪費 (fake full)
{
    if(front == 0) return false; // 如果 front 為 0 表示 queue 為 real full

    for(int i = front+1 ; i <= rear ; i++) // 將每一個元素向左移動 front 格
    {
        head[i-front] = head[i];
    }
    rear -= front; // 將 rear 向左移動 front 格
    front = 0; // 將 front 向左移動到 index 0
    return true;
}

void print1DArray(int *head, int start, int end) // start 填入起始 index, end 填入結束 index
{
    if(start > end) return;
    for(int i = start ; i <= end ; i++)
    {       
        printf("%d ", head[i]);
    }

    printf("\n");
}

int* createQueue() // O(1)
{
    int *head = (int*)malloc(sizeof(int)*(SIZE+1));  // 建一個 queue array
    front = 0; // front 設定為 0
    rear = 0; // rear 設定為 0
    return head;
}

void enqueue(int* head, int value) // O(n) move(head) 所花的時間
{
    if(rear == SIZE) // 如果 rear 到 array 的尾端
    { 
        if(!move(head)) // 檢查 array 是否為 fake full 若可以則移動，否則 real full
        {
            printf("queue is full\n");
            return;
        }
    }

    head[++rear] = value; // 加入新的值 rear 向右一格
    print1DArray(head, front+1, rear);
}

int dequeue(int *head) // O(1)
{
    if(front == rear) // array 是否為空，front == rear 代表 array 為空
    {
        printf("queue is empty\n");
        return -1;
    }

    print1DArray(head, front+1, rear); 
    return head[++front]; //將 dequeue 的值回傳
}

int main()
{
    int* head = createQueue();
    printf("Dequeue: %d\n", dequeue(head));
    enqueue(head, 10);
    printf("Dequeue: %d\n", dequeue(head));
    printf("Dequeue: %d\n", dequeue(head));
    enqueue(head, 35);
    enqueue(head, 40);
    printf("Dequeue: %d\n", dequeue(head));
    printf("Dequeue: %d\n", dequeue(head));
    printf("Dequeue: %d\n", dequeue(head));
    enqueue(head, 50);
    enqueue(head, 50);
    enqueue(head, 50);
    enqueue(head, 50);
}