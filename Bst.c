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

void delete(Node** root,int item) {
    Node* temp_root = *root;
    if(temp_root == NULL)
    {
        printf("Item not found\n");
        return;
    }
    if(temp_root->data < item)
    {
        delete(&(*root)->right,item);
    }
    else if(temp_root->data > item)
    {
        delete(&(*root)->left,item);
    }
    else 
    {
        if(temp_root->left == NULL && temp_root->right != NULL)
        {
            if(temp_root->parent == NULL)
            {
                temp_root->data = temp_root->right->data;
                Node* temp = temp_root->right;

                temp_root->right = NULL;
                free(temp);
                return;
            }
            else if(temp_root->parent->left == temp_root)
                temp_root->parent->left = temp_root->right;
            else
                temp_root->parent->right = temp_root->right;
            
            temp_root->right->parent = temp_root->parent;
            free(temp_root);
        }
        else if(temp_root->right == NULL && temp_root->left != NULL)
        {
            if(temp_root->parent == NULL)
            {
                temp_root->data = temp_root->left->data;
                Node* temp = temp_root->left;
                temp_root->left = NULL;
                free(temp);

                return;
            }
            else if(temp_root->parent->left == temp_root)
                temp_root->parent->left = temp_root->left;
            else
                temp_root->parent->right = temp_root->left;
            
            temp_root->left->parent = temp_root->parent;
            free(temp_root);
        }
        else if(temp_root->right == NULL && temp_root->left == NULL)
        {
            if(temp_root->parent == NULL)
            {
                *root = NULL;
                free(temp_root);
                return;
            }
            if(temp_root->parent->left == temp_root)
                temp_root->parent->left = NULL;
            else
                temp_root->parent->right = NULL;
            free(temp_root);
        }
        else
        {
            Node* pre = pred(temp_root->left);
            if(pre == temp_root->left)
                pre->parent->left = pre->left;
            else
                pre->parent->right = pre->left;
            temp_root->data = pre->data;
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
        if(root == NULL)
        {
            printf("root is null");
            break;
        }
        delete(&root,a);
        inOrder(root);
        scanf("%d",&a);
    }while(a != -1);

}