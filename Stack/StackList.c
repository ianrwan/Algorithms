#include "stdio.h"
#include "stdlib.h"

struct Node
{
    int value;
    struct Node *next;
};

struct Node *top;

void printList(struct Node* top)
{
    if(top == NULL)
        printf("stack is empty\n");

    struct Node* current;
    current = top;
    while(current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

struct Node* createStack()
{ 
    struct Node* top = NULL; // 建立一個空 stack 
    return top;
}

void push(int value)
{
    struct Node *new = (struct Node*)malloc(sizeof(struct Node)); // 在 stack 中建立新的 node
    new->value = value; // 在 stack 中加入新的值
    new->next = top; // 將新的 node 的 next 指向舊值
    top = new; // 將 top 移到新的 node 上面
    // printList(top); 
}

int pop()
{
    if(top == NULL) // 如果發現 top 是 NULL 代表 stack empty
    {
        printf("stack is empty");
        return -1;
    }

    int popNumber = top->value; // 將要 pop 的值存入一變數中
    struct Node *delete = top; // 將要刪除的節點指向 top
    top = top->next; // top 移到下一個 node
    free(delete); // 刪除 pop 掉的 node

    return popNumber;
}

int main()
{
    top = createStack();
    push(10);
    push(35);
    push(40);
    push(1000);
    printf("pop: %d\n", pop());
    push(50);
    printf("pop: %d\n", pop());
    printf("pop: %d\n", pop());
    printf("pop: %d\n", pop());
    printf("pop: %d\n", pop());
}