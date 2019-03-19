#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
#define M 20
#define T char*

typedef struct Node{
    T elem;
    struct Node *firstChild;
    struct Node *nextSibling;
}Node , *Tree;

//initialize the tree

void Init(Tree *tree){
    *tree = NULL;
}

//insert an element to the tree

void insert(Tree *tree , T value){
    Node *p = (Node*)malloc(sizeof(Node));
    p->elem = value;
    p->firstChild = NULL;
    p->nextSibling = NULL;
    if(*tree == NULL){
        *tree = p;
    }
    else if((*tree)->firstChild == NULL)(*tree)->firstChild = p;
    else{
        Node *temp = (*tree)->firstChild;
        while (temp->nextSibling != NULL){
            temp = temp->nextSibling;
        }
        temp->nextSibling = p;
    }
}

void ListDir(Tree  tree, int depth){
    int i;
    if(tree->elem != NULL){
        for(i = 0 ; i < depth ; i ++){
            printf("    ");
        }
        printf("%s\n" , tree->elem);
        if(tree->firstChild != NULL){
            ListDir(tree->firstChild , depth + 1);
            Node *p = tree->firstChild;
            while (p->nextSibling != NULL){
                p = p->nextSibling;
                ListDir(p , depth + 1);
        }
        }
        }
    }


void ListTree(Tree tree){
    if(tree != NULL)
    ListDir(tree , 0);
    else{
        printf("the tree is empty\n");
    }
}

Tree findSon(Tree tree , char *key){
    if(tree == NULL){
        printf("the tree is NULL\n");
        return NULL;
    }
    if(strcmp(tree->elem , key) == 0)return tree;
    else if(tree->firstChild != NULL){
        if(strcmp(tree->firstChild->elem , key) == 0)return tree->firstChild;
        Node *p = tree->firstChild;
        while (p->nextSibling != NULL){
            p = p->nextSibling;
            if(strcmp(p->elem , key) == 0)return p;
        }
    }
    return NULL;
}

Tree findAll(Tree tree , char* key){
    Node *temp;
    if(tree == NULL){
        printf("the tree is NULL\n");
        return NULL;
    }
    if(strcmp(tree->elem , key) == 0)return tree;
    else if(tree->firstChild != NULL){
        temp = findAll(tree->firstChild , key);
        if(temp != NULL)
            return  temp;
        Node *p = tree->firstChild;
        while (p->nextSibling != NULL){
            p = p->nextSibling;
            temp = findAll(p , key);
            if(temp != NULL)
                return temp;
        }
    }
    return NULL;
}

int main(){
    Tree tree;
    Init(&tree);
    char cmd[M];
    char p[N][M];
    char temp[M];
    int counter = 0;
    strcpy(p[0] , "root");
    insert(&tree , p[0]);
    Tree current = tree;
    int flag = 1;
    while (flag){
        scanf("%s" , cmd);
        if(strcmp("dir" , cmd) == 0){
            ListTree(current);
        } else if(strcmp("mkdir" , cmd) == 0){
            scanf("%s" , p[++ counter]);
            insert(&current , p[counter]);
        } else if(strcmp("cd" , cmd) == 0){
            scanf("%s" , temp);
            Node *d = findSon(current , temp);
            if(d != NULL)current = d;
        } else if(strcmp("exit" , cmd) == 0){
            flag = 0;
        } else if(strcmp("dirall" , cmd) == 0){
            ListTree(tree);
        }
        else if(strcmp("cdall"  , cmd) == 0){
            scanf("%s" , temp);
            Node *d = findAll(tree , temp);
            if(d != NULL)current = d;
        }else{
            printf("there is no such cmd\n");
        }

    }
    return 0;
}