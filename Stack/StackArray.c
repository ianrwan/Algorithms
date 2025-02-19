#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#define SIZE 3 // stack 的容量
int top; // 目前 stack 最上層的 index

void print1DArray(int *head, int start, int end) // start 填入起始 index, end 填入結束 index
{
    if(start > end) return;
    for(int i = start ; i <= end ; i++)
    {       
        printf("%d ", head[i]);
    }

    printf("\n");
}

int *createStack()
{
    int *head = (int*)malloc(sizeof(int)*(SIZE+1)); // index 0 為空值，建立 [1...SIZE] 的空間
    for(int i = 0 ; i < SIZE+1 ; i++) head[i] = -1;

    top = 0;

    return head; // 回傳陣列的起始位置
}

void push(int* head, int value)
{
    if(top == SIZE) // 如果 stack 滿的話
    {
        printf("stack is full\n"); 
        return;
    }
    
    head[++top] = value; // 新增物品到 stack 裡面

    printf("stack value: ");
    print1DArray(head, 1, top);
}

int pop(int *head)
{
    if(top == 0) // 如果 stack 空的話
    {
        printf("stack is empty\n");
        return -1;
    }

    int popNumber = head[top--]; // 將 stack 裡面的東西 pop 出來
    // print1DArray(head, 1, top);
    return popNumber;
}

bool isEmpty()
{
    if(top == 0) return true;
    return false;
}

bool isFull()
{
    if(top == SIZE) return true;
    return false;
}

int main()
{
    int* head = createStack();
    push(head, 10);
    push(head, 35);
    push(head, 40);
    push(head, 1000);
    printf("pop: %d\n", pop(head));
    push(head, 50);
    printf("pop: %d\n", pop(head));
    printf("pop: %d\n", pop(head));
    printf("pop: %d\n", pop(head));
    printf("pop: %d\n", pop(head));
}