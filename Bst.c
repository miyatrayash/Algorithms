#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;


void insert(Node* root,int item){

    if(root == NULL)
    {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = item;
        root->left = NULL;
        root->right = NULL;
    }

    if(root->data < item)
        insert(root->right,item);
    else
        insert(root->left,item);
}

Node* pred(Node* root){
    
}

void delete(Node* root,int item) {

    if(root == NULL)
    {
        printf("Item not found\n");
        exit(0);
    }
    if(root->data == item) {

    }
}