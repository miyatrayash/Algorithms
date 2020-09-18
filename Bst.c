#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
}Node;


void insert(Node** root,int item){
    if(*root == NULL)
    {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = item;
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->parent = NULL;
        *root = new_node;
        return;
    }
    if((*root)->right == NULL && (*root)->data < item || (*root)->left == NULL && (*root)->data > item)
    {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = item;
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->parent = *root;

        if((*root)->data < item)
            (*root)->right = new_node;
        else
            (*root)->left = new_node;
        return;
    }

    if((*root)->data < item)
        insert(&(*root)->right,item);
    else
        insert(&(*root)->left,item);
}

Node* pred(Node* root){
    if(root->right == NULL)
    {
        return root;
    }

    pred(root->right);
}

void delete(Node* root,int item) {

    if(root == NULL)
    {
        printf("Item not found\n");
        return;
    }
    if(root->data < item)
    {
        delete(root->right,item);
    }
    else if(root->data > item)
    {
        delete(root->left,item);
    }
    else 
    {
        if(root->left == NULL && root->right != NULL)
        {
            
            if(root->parent->left == root)
                root->parent->left = root->right;
            else
                root->parent->right = root->right;
            
            root->right->parent = root->parent;
            free(root);
        }
        else if(root->right == NULL && root->left != NULL)
        {
            
            if(root->parent->left == root)
                root->parent->left = root->left;
            else
                root->parent->right = root->left;
            
            root->left->parent = root->parent;
            free(root);
        }
        else if(root->right == NULL && root->left == NULL)
        {
            if(root->parent->left == root)
                root->parent->left = NULL;
            else
                root->parent->right = NULL;
            free(root);
        }
        else
        {
            Node* pre = pred(root->left);
            pre->parent->right = pre->left;
            root->data = pre->data;
            free(pre);
        }
        return;
    }
}

void inOrder(Node* root)
{
    if(root == NULL)
        return;
    
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

int main()
{
    int a=0;
    Node* root=NULL;
    scanf("%d",&a);
    do
    {
        insert(&root,a);
        scanf("%d",&a);
    }while(a != -1);

    inOrder(root);

    scanf("%d",&a);
    do
    {
        delete(root,a);
        inOrder(root);
        scanf("%d",&a);
    }while(a != -1);

}