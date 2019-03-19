#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node *left;
    struct Node *right;
    int elem;
}*Tree , Node;

void InitTree(Tree* root){
    *root = NULL;
}

void insert(Tree *root , int value){
    if(*root == NULL){
        *root = (Node*)malloc(sizeof(Node));
        (*root)->elem = value;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else if(value > (*root)->elem){
        insert((&(*root)->right) , value);
    } else if(value < (*root)->elem){
        insert(&((*root)->left) , value);
    }
}

int find(Tree root , int key){
    if(root == NULL)return 0;
    if(root->elem == key)return 1;
    else if(key > root->elem)return find(root->right , key);
    else if(key < root->elem)return find(root->left , key);
}

int main(){
    int n , k , a;
    int i , target;
    Tree root;
    InitTree(&root);
    scanf("%d%d" , &n , &k);
    for(i = 0 ; i < n ; i ++){
        scanf("%d" , &a);
        insert(&root , a);
    }
    while (k --){
        scanf("%d" , &target);
        printf("%d " , find(root , target));
    }
    printf("\n");
    return 0;
}