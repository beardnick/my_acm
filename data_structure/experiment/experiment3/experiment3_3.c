#include<stdio.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct Node{
    int weight , parent , left , right;
}Node;

typedef struct tree{
    Node elem[MAX_SIZE];
    int len;
}Tree;

//the var that will be used in the functions
int helpStart = 0 ;
char helpString[MAX_SIZE] , code[MAX_SIZE][MAX_SIZE];

//elem[0] wont use

void buildTree(Tree *tree , int a[MAX_SIZE] ,int n){
    int i;
    tree->len = n;
    for(i = 1 ; i <= n ; i ++){
        tree->elem[i].weight = a[i];
        tree->elem[i].parent = 0;
        tree->elem[i].left = 0;
        tree->elem[i].right = 0;
    }
}

void HuffManTree(Tree *tree){
    int i , min1 , min2;
    int min1Index , min2Index;
    int n = tree->len;
    while(tree->len < 2 * n - 1){
        min1 = 1000;
        min2 = 1000;
        for( i = 1 ; i <= tree->len ; i ++){
            if(tree->elem[i].parent == 0){
                if(tree->elem[i].weight < min1){
                    min2 = min1;
                    min2Index = min1Index;
                    min1 = tree->elem[i].weight;
                    min1Index = i;
                }else if(tree->elem[i].weight < min2){
                    min2 = tree->elem[i].weight;
                    min2Index = i;
                }
            }
        }
        tree->elem[++(tree->len)].weight = min1 + min2;
		if(min1Index < min2Index){
			 tree->elem[tree->len].left = min1Index;
			 tree->elem[tree->len].right = min2Index;
		}else{
			 tree->elem[tree->len].left = min2Index;
			 tree->elem[tree->len].right = min1Index;
		}
        tree->elem[tree->len].parent = 0;
        tree->elem[min1Index].parent = tree->len;
        tree->elem[min2Index].parent = tree->len;
    }
}

void Print(Tree tree){
    int i;
    for(i = 1 ; i <= tree.len ; i ++){
        printf("%d. %d %d %d %d\n" , i , tree.elem[i].weight , tree.elem[i].parent , tree.elem[i].left , tree.elem[i].right);
    }

}

void bottomUpBuild(Tree tree){
    char temp[tree.len];
    int i  , start = tree.len , parent , child;
    for(i = 1 ; i <= tree.len ; i ++){
        start = tree.len;
        temp[start] = '\0';
        parent = tree.elem[i].parent;
        child = i;
        while (parent != 0){
            if(tree.elem[parent].left == child){//do not use i to replace child
                temp[-- start] = '0';
            } else{
                temp[-- start] = '1';
            }
            child = parent;
            parent = tree.elem[parent].parent;
        }
        strcpy(code[i] , &temp[start]);
    }
}


void topDownBuild(Tree tree , int index){
    if(tree.elem[index].left == 0 && tree.elem[index].right == 0){
        helpString[helpStart] = '\0';
        strcpy(code[index] , helpString);
    } else{
        helpString[helpStart ++] = '0';
        topDownBuild(tree , tree.elem[index].left);
        helpString[helpStart ++] = '1';
        topDownBuild(tree , tree.elem[index].right);
    }
    helpStart -- ;
}

int main(){
    int n;//the number of the node
    int a[MAX_SIZE];
    scanf("%d" , &n);
    Tree tree;
    int i;
    for( i = 1 ; i <= n ; i ++){
        scanf("%d" , &a[i]);//the weight of the node
    }
    buildTree(&tree , a , n);
    HuffManTree(&tree);
//    bottomUpBuild(tree);
//    Print(tree);
//    for(i = 1 ; i <= n ; i ++){
//        printf("%s\n" , code[i]);
//    }
    helpStart = 0;
    //bottomUpBuild(tree );
    topDownBuild(tree , tree.len);
    Print(tree);
    for(i = 1 ; i <= n ; i ++){
        printf("%s\n" , code[i]);
    }
    return 0;
}
