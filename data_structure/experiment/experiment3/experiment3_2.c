#include<stdio.h>
#include <stdlib.h>

#define N 100

typedef struct Node{
    char elem;
    struct Node *left , *right;
}Node , *Tree;

int n = 0;
char c[N];

void Init(Tree * tree){
    *tree = NULL;
}

void buildTree(Tree * tree){
    if(c[n] == ' '){
        *tree = NULL;
        n ++;
    }else if(c[n] == '\0'){
        *tree = NULL;
    }else{
        Node *p = (Node*)malloc(sizeof(Node));
        p->elem = c[n ++];
        *tree = p;
        buildTree( &(*tree)->left  );
        buildTree( &(*tree)->right );
    }
}

void firstOrder(Tree tree){
    if(tree != NULL){
        printf("%c " , tree->elem);
        firstOrder(tree->left);
        firstOrder(tree->right);
    }
}

void midOrder(Tree tree){
    if(tree != NULL){
        midOrder(tree->left);
        printf("%c " , tree->elem);
        midOrder(tree->right);
    }
}

void lastOrder(Tree tree){
    if(tree != NULL){
        lastOrder(tree->left);
        lastOrder(tree->right);
        printf("%c" , tree->elem);
    }
}

int main(){
    gets(c);
  //  printf("%s\n" , c);
    Tree tree;
    Init(&tree);
    buildTree(&tree);
    firstOrder(tree);
    printf("\n");
    midOrder(tree);
    printf("\n");
    midOrder(tree);
    return 0;
}
