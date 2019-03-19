#include <stdio.h>

#include <stdlib.h>
#define T int
typedef struct Node{
    T data;
    struct Node* next;
}Node;

//define queue head
typedef struct{
    Node* front;
    Node* rear;
}Queue;

//initialize the empty queue

void InitQueue(Queue *l){
    l->front = (Node*)malloc(sizeof(Node));
    l->rear = l->front;
    l->front->next = NULL;
}

//enter the queue

void enter(Queue *l , T c){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = c;
    l->rear->next = p;
    l->rear = p;
    p->next = NULL;
}

//delete from the queue

void delete(Queue *l){
    Node *p;
    if(l->front->next != NULL){
        if(l->rear == l->front->next)l->rear = l->front;
        p = l->front->next;
        l->front->next =p->next;
        free(p);
    }
}

//get a element data from the queue

T get(Queue l){
    return l.front->next->data;
}

//is empty

int isEmpty(Queue l){
    return l.front->next == NULL;
}

//get the size of the queue

int sizeofQueue(Queue l){
    int counter = 0;
    Node *p = l.front;
    while (p->next != NULL){
        p = p->next;
        counter ++;
    }
    return counter;
}


#define MAX_SIZE 100
int vis[MAX_SIZE] = {0};
int graph[MAX_SIZE][MAX_SIZE];

void search(int i , int size){
   Queue queue;
    InitQueue(&queue);
    enter(&queue , i);
    int j , temp;
    while (! isEmpty(queue)) {
        temp = get(queue);
        delete(&queue);
        for(j = 0 ; j < size ; j ++){
            if(graph[temp][j] && ! vis[j]){
                printf("%d " , j);
                vis[j] = 1;
                enter(&queue , j);
            }
        }
    }
}

int main(){
    int size ;
    scanf("%d" , &size);
    int i , j;
    for(i = 0 ; i < size ; i ++){
        for ( j = 0 ; j < size ; j ++){
            scanf("%d" , &graph[i][j]);
        }
    }
    printf("0 ");
    vis[0] = 1;
    search(0 , size);
    printf("\n");
    return 0;
}