#include <stdlib.h>
#include <stdio.h>

#define  T int

typedef struct Node {
    T data;
    struct Node* prior;
    struct Node* next;
}Node , *DLinkList;

//initialize the list

void InitList(DLinkList *l ){
    *l = (Node*) malloc(sizeof(Node));
    (*l)->next = *l;
    (*l)->prior = *l;
}

//create from head

void CreateFromHead(DLinkList l , T value){
    Node *p = (Node*) malloc(sizeof(Node));
    p->data = value;
    if( l->next == l && l->prior == l){
        l->next = p;
        l->prior = p;
        p->next = l;
        p->prior = l;
    } else{
        p->next = l->next;
        p->prior = l;
        l->next = p;
    }
}

//create from tail

void CreateFromTail(DLinkList l , T value){
    Node *p = (Node*) malloc(sizeof(Node));
    Node *temp = l->prior;
    p->data = value;
    p->prior = temp;
    p->next = l;
    temp->next = p;
}

void insert(DLinkList l , T value , int position){
    Node *p = l;
    Node *temp = (Node*) malloc(sizeof(Node));
    if(temp == NULL || p == NULL){
        //printf("insert fail\n");
        return;
    }
    temp->data = value;
    int counter = 0;
    while (p->next != l && counter != position - 1){
        p = p->next;
        counter ++;
    }
    if(counter == position - 1){
        temp->next = p->next;
        p->next = temp;
      //  printf("insert OK\n");
    } else{
       // printf("insert fail\n");
    }

}

void PrintAll(DLinkList l)
{
    Node* p;
    p = l;
    while( p->next != l)
    {
        p = p->next;
        printf("%d ",p->data);
    }
    printf("\n");
}

void delete(DLinkList l , int position){
    Node *p = l;
    int counter = 0;
    while (p->next != l && counter != position - 1){
        p = p->next;
        counter ++;
    }
    if(p->next != l){
        Node *temp = p->next;
        p->next = temp->next;
        temp->prior = p;
        free(temp);
        //printf("delete OK\n");
    } else{
       // printf("delete fail\n");
    }
}

int main(){
    DLinkList  l;
    InitList(&l);
    int cmd;
    int position , value;
    while (scanf("%d" ,&cmd)) {
        switch (cmd){
            case 0:
                PrintAll(l);
                break;
            case 1:
                scanf("%d%d" , &position , &value);
                insert(l , value , position);
                break;
            case 2:
                scanf("%d" , &position);
                delete(l , position);
                break;
            default:
                break;
        }
    }
    return 0;
}