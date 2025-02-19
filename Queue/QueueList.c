#include "stdio.h"
#include "stdlib.h"

/*
所實作的 queue 是以 list 的 front 作為 queue 的 front
list 的 rear 作為 queue 的 rear

(list front(queue front)) [node1]->[node2]->[node3]->NIL (list rear(queue rear))
enqueue: O(1)
dequeue: O(1)
*/

struct Node
{
    int value;
    struct Node *next;
};

struct Node* rear;
struct Node* front;

void printList(struct Node* top)
{
    if(top == NULL)
        printf("queue is empty\n");

    struct Node* current;
    current = top;

    while(current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void *createQueue() // 建立一個新的 queue
{
    rear = NULL;
    front = NULL;  
}

void *enqueue(int value)
{
    struct Node *new = (struct Node*)malloc(sizeof(struct Node)); // 建立新的節點
    new->value = value; // 新的 node 設定新值
    new->next = NULL; // 新的 node 指向 NULL 值
    
    if(rear != NULL) rear->next = new; // 如果 rear 並非 NULL 則舊的 node next 指向新的 node
    rear = new; // rear 移到新的 node

    if(front == NULL) front = new; // 如果 front 為 NULL 的話將其指到新的 node
    
    // printList(front);
}

int dequeue()
{
    if(front == NULL) // 如果 front 為 null 則 queue empty
    {
        printf("queue is empty\n");
        return -1;
    }

    struct Node *delete = front;
    int dequeueNum = front->value;
    if(rear == front) rear = NULL; // 如果是最後一個節點被刪除 rear 設定為 NULL 
    front = front->next; // front 移到下一個節點 (若為最後一個剛好會指向 NULL)
    free(delete);
    return dequeueNum; // 回傳 dequeue 出來的數字
}

int main()
{
    createQueue();
    printf("Dequeue: %d\n", dequeue());
    enqueue(10);
    printf("Dequeue: %d\n", dequeue());
    printf("Dequeue: %d\n", dequeue());
    enqueue(35);
    enqueue(40);
    enqueue(80);
    enqueue(90);
    printf("Dequeue: %d\n", dequeue());
    printf("Dequeue: %d\n", dequeue());
    printf("Dequeue: %d\n", dequeue());
    enqueue(50);
    enqueue(50);
    enqueue(50);
    enqueue(50);
    printf("Dequeue: %d\n", dequeue());
}