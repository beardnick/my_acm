#include <stdlib.h>
#include <stdio.h>
#define T int

typedef struct  Node
{
    T data;
    struct Node * next;
}Node , *LinkList;

//initialize the list
//set next NULL

void InitList(LinkList * l)
{
    *l = (Node*)malloc(sizeof(Node*));
    (*l)->next = NULL;
}

//create from head


//create from tail

void CreateFromTail(LinkList l , T value)
{
    Node* p = (Node*)malloc(sizeof(Node*));
    p->data = value;
    Node* tail;
    tail = l;
    while(tail->next != NULL)tail = tail->next;
    tail->next = p;
    p->next = NULL;
}


//print all the elems

void PrintAll(LinkList l)
{
    Node* p;
    p = l;
    while( p->next != NULL)
    {
        p = p->next;
        printf("%d ",p->data);
    }
    printf("\n");
}


void reverse(LinkList l){
    LinkList temp;
    InitList(&temp);
    Node *p;
    while (l->next != NULL){
        p = l->next;
        l->next = p->next;
        if(temp->next == NULL){
            temp->next = p;
            p->next = NULL;
        } else{
            p->next = temp->next;
            temp->next = p;
        }
    }
    l->next = temp->next;
    free(temp);
}

int main(){
    LinkList  l;
    InitList(&l);
    int n;
    scanf("%d", &n);
    int i , value;
    for(i = 0 ; i < n ; i ++){
        scanf("%d",&value);
        CreateFromTail(l , value);
    }
    PrintAll(l);
    reverse(l);
    PrintAll(l);

}
