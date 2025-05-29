#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    struct Node* next;
    int data;
} Node;
Node* makeNode(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->next=NULL;
    newNode->data=data;
    return newNode;
}
void insertAtTail(Node** head,int data)
{
    Node* newNode=makeNode(data);
    if ((*head)==NULL) 
    {
        (*head)=newNode;
        return;
    } 
    Node* cur=*head;
    while (cur->next!=NULL)
    {
        cur=cur->next;
    }
    cur->next=newNode;
    return;
}
void insertAtHead(Node** head,int data)
{
    Node* newNode=makeNode(data);
    if ((*head)==NULL)
    {
        (*head)=newNode;
        return;
    }
    newNode->next=*head;
    (*head)=newNode;
    return;
}
Node* findNode(Node* head,int data)
{
    if (head==NULL) return NULL;
    while (head!=NULL&&head->data!=data)
    {
        head=head->next;
    }
    if (head==NULL) return NULL;
    return head;
}
void DeleteByValue(Node**head,int data)
{
    if ((*head)==0) return;
    if ((*head)->data==data) *head=NULL;
    Node* new=*head;
    while (new->next!=NULL)
    {
        if (new->next->data==data)
        {
            new->next=NULL;
            return;
        }
        new=new->next;
        
    }
    return;
}
void printList(Node* head)
{
    while (head!=NULL)
    {
        printf("%d -> ",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
void freeNode(Node** head)
{
    Node* cur=*head;
    Node* temp=cur;
    while (cur!=NULL)
    {
        cur=cur->next;
        free(temp);
        temp=cur;
    }
    *head=NULL;

}
int main()
{
    int n,d;
    Node* head=NULL;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&d);
        insertAtTail(&head,d);
    }
    printList(head);
    return 0;
}
