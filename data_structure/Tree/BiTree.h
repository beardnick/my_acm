//
// Created by asus on 2017/10/25.
//

#ifndef DATASTRUCTURE_BITREE_H
#define DATASTRUCTURE_BITREE_H

#include <stdlib.h>
#include <stdio.h>

#define T TreeNode*
#define  TYPE int

typedef struct TreeNode{
    TYPE elem;
    struct TreeNode *leftChild;
    struct TreeNode *rightChild;
} TreeNode , *BiTree;


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

T delete(Queue *l){
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


//initialize the Tree
void Init(BiTree *root){
   *root = NULL;
}

//insert an element into the BiTree
//I want to build a complete tree
//I need to use BFS
//so I need a queue

void Insert(BiTree *tree , TYPE value){
    TreeNode *p = (TreeNode*)malloc(sizeof(TreeNode));
    p->elem = value;
    p->leftChild = NULL;
    p->rightChild = NULL;
  if(*tree == NULL){
      *tree = p;
      return;
  }
    Queue q;
    InitQueue(&q);
    enter(&q , *tree);
    TreeNode *temp;
    while (! isEmpty(q)){
     temp = get(q);
        delete(&q);
        if(temp->leftChild == NULL){
            temp->leftChild = p;
            return;
        } else{
            enter(&q , temp->leftChild);
        }
        if(temp->rightChild == NULL){
            temp->rightChild = p;
            return;
        } else{
            enter(&q , temp->rightChild);
        }
    }
}

void List(BiTree tree , int depth){
    if(tree == NULL)return;
    int i;
    for(i = 0 ; i < depth ; i ++){
        printf("    ");
    }
    printf("%d\n" , tree->elem);
    List(tree->leftChild , depth + 1);
    List(tree->rightChild , depth + 1);
}
#endif //DATASTRUCTURE_BITREE_H
