#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* makeNode(int data)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void insert(Node** root,int data)
{
    if (*root==NULL) 
    {
        (*root)=makeNode(data);
        return;
    }
    if ((*root)->data<data) insert(&(*root)->right,data);
    if ((*root)->data>data) insert(&(*root)->left,data);
    return;
}
void inOrder(Node* root)
{
    if (root==NULL) return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
    return;
}
void preOrder(Node* root)
{
    if (root==NULL) return;
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
    return;

}
void freeTree(Node* root)
{
    if (root==NULL) return;
    freeTree(root->right);
    freeTree(root->left);
    free(root);
}
int main()
{
    char s[100];
    int a;
    Node* root=NULL;
    while(1)
    {
        scanf("%s",s);
        if (s[0]=='#') break;
        scanf("%d",&a);
        insert(&root,a);
    }
    preOrder(root);
    printf("\n");
    freeTree(root);
    return 0;
}