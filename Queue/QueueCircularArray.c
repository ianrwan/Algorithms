#include "stdio.h"
#include "stdlib.h"

#define SIZE 4
int front, rear;

void print1DArray(int *head, int start, int end) // start 填入起始 index, end 填入結束 index
{
    int i = start; // 設定起始值
    while(i%SIZE != end) // 如果 i 跑一圈遇到 end 的話停止
    {
        printf("%d ", head[++i%SIZE]); // 輸出 i 值跑一圈的值
    }

    printf("\n");
}

int* createQueue()
{
    int *head = (int*)malloc(sizeof(int*)*(SIZE)); // 建立 queue array
    front = rear = 0; // 設定 front and rear 在 0 的位置
    return head;
}

void enqueue(int* head, int value)
{
    rear = (rear+1)%SIZE; // rear 向右移動一格（或繞回起點）
    if(rear == front) // 如果 rear 遇到 front 表示 full
    {
        printf("queue is full\n");
        rear = (rear-1)%SIZE; // rear 向後退一步
        return;
    }

    head[rear] = value; // 將值放入 rear 所在的位置
    // print1DArray(head, front, rear);
}

int dequeue(int*head)
{
    if(rear == front) // 如果 front 與 rear 相等表示 empty
    {
        printf("queue is empty\n");
        return -1;
    }
    front = (front+1)%SIZE; // front 向右移動一格（或繞一圈回起始點）
    return head[front]; // 回傳 front 的值
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
    enqueue(head, 80);
    enqueue(head, 90);
    printf("Dequeue: %d\n", dequeue(head));
    printf("Dequeue: %d\n", dequeue(head));
    printf("Dequeue: %d\n", dequeue(head));
    enqueue(head, 50);
    enqueue(head, 50);
    enqueue(head, 50);
    enqueue(head, 50);
}