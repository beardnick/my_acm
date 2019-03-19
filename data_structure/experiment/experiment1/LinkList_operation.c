#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define T int
typedef struct Node{
    T data;
    struct Node *next;
}*LinkList , Node;

void Init(LinkList *l){
    *l = (Node*)malloc(sizeof(Node));
    (*l)->next = NULL;
}

void insert(LinkList l , T value , int position){
    Node *p = l;
    Node *temp = (Node*) malloc(sizeof(Node));
    if(temp == NULL || p == NULL){
        printf("insert fail\n");
        return;
    }
    temp->data = value;
    int counter = 0;
    while (p->next != NULL && counter != position - 1){
        p = p->next;
        counter ++;
    }
    if(counter == position - 1){
        temp->next = p->next;
        p->next = temp;
        printf("insert OK\n");
    } else{
        printf("insert fail\n");
    }

}

void insertBack(LinkList l, T value){
    Node *p = (Node*) malloc(sizeof(Node));
    if(p == NULL){
        printf("insert fail\n");
        return;
    }
    p->data = value;
    if( l->next == NULL){
        l->next = p;
        p->next = NULL;
    } else{
        p->next = l->next;
        l->next = p;
    }
}

void show(LinkList l){
    Node *p = l;
    if(p->next == NULL){
        printf("Link list is empty\n");
        return;
    }
    while (p->next != NULL){
        p = p->next;
        printf("%d ", p->data);
    }
    printf("\n");
}


void delete(LinkList l , int position){
    Node *p = l;
    int counter = 0;
    while (p->next != NULL && counter != position - 1){
        p = p->next;
        counter ++;
    }
    if(p->next != NULL){
        Node *temp = p->next;
        p->next = temp->next;
        free(temp);
        printf("delete OK\n");
    } else{
        printf("delete fail\n");
    }
}

T get(LinkList l , int position){
    Node *p = l;
    int counter = 0;
    while (p->next != NULL && counter != position ){
        p = p->next;
        counter ++;
    }
    if(p->next != NULL){
        printf("%d\n" , p->data);
    } else{
        printf("get fail\n");
    }
}
int main(){
    LinkList l;
    Init(&l);
    int n , temp , i;
    scanf("%d" , &n);
    for(i = 0 ; i < n ; i ++){
        scanf("%d" , &temp);
        insertBack(l, temp);
    }
    scanf("%d" , &n);
    char cmd[10];
    int value , position;
    while ( n --){
        scanf("%s" , cmd);
        if(strcmp(cmd , "show") == 0){
           // printf("show OK\n");
            show(l);

        }else if(strcmp(cmd , "get") == 0){
           // printf("get OK\n");
            scanf("%d" , &position);
            get(l , position);
        } else if(strcmp(cmd , "delete") == 0){
           // printf("delete OK\n");
            scanf("%d" , &position);
            delete(l , position);

        }else if(strcmp(cmd , "insert") == 0){
            scanf("%d%d" , &position , &value);
            insert(l , value , position);
        }
    }
    return 0;
}