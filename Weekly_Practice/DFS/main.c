#include<stdio.h>
#include<stdlib.h>

int distance = 0;
enum Color{
    white, gray, black
};

struct Node
{
    int num;
    enum Color color;
    int startDistance;
    int endDistance;
    struct Node *father;
    struct Node *next;
};

struct List
{
    struct Node *node;
};

struct Graph
{
    int vertices;
    struct List *list;
};

struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->list = (struct List*)malloc(sizeof(struct List)*vertices);

    for(int i = 0 ; i < vertices ; i++)
    {
        graph->list[i].node = (struct Node*)malloc(sizeof(struct Node));
        graph->list[i].node->num = i+1;
        graph->list[i].node->color = white;
        graph->list[i].node->startDistance = 0;
        graph->list[i].node->endDistance = 0;
        graph->list[i].node->father = NULL;
        graph->list[i].node->next = NULL; 
    }

    return graph;
}

void addEdge(struct Graph *graph, int start, int end)
{
    struct Node *startNode = graph->list[start-1].node;
    struct Node *endNode = startNode;
    while(endNode->next != NULL)
    {
        endNode = startNode->next;
    }
    endNode->next = (struct Node*)malloc(sizeof(struct Node));
    endNode = endNode->next;

    endNode->num = end;
    endNode->next = NULL;
}

void DFS(struct Graph *graph, int start)
{
    distance++;
    graph->list[start-1].node->startDistance = distance;
    graph->list[start-1].node->color = gray;

    printf("%d ", start);

    struct Node *startNode = graph->list[start-1].node;
    struct Node *current = startNode;
    while(current->next != NULL)
    {
        current = current->next;
        struct Node *vertice = graph->list[current->num-1].node;
        if(vertice->color == white)
        {
            vertice->father = startNode;
            DFS(graph, vertice->num);
        }
    }
    startNode->color = black;
    distance++;
    startNode->endDistance = distance;
}

int main(void)
{
    struct Graph *graph = createGraph(4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    
    addEdge(graph, 2, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 4, 2);
    addEdge(graph, 2, 1);

    DFS(graph, 1);

    // struct Node *node = NULL;
    // for(int i = 0 ; i < 4 ; i++)
    // {
    //     node = graph->list[i].node;
    //     while(node != NULL)
    //     {
    //         printf("%d ", node->num);
    //         node = node->next;
    //     }
    //     printf("\n");
    // }
}