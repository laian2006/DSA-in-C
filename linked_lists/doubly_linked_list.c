#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

DNode* createDNode(int data) {
    DNode* node = (DNode*)malloc(sizeof(DNode));
    if (!node) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->prev = node->next = NULL;
    return node;
}

void insertAtHead(DNode** head, int data) {
    DNode* newNode = createDNode(data);
    if (*head) {
        (*head)->prev = newNode;
        newNode->next = *head;
    }
    *head = newNode;
}

void insertAtTail(DNode** head, int data) {
    DNode* newNode = createDNode(data);
    if (!*head) {
        *head = newNode;
        return;
    }
    DNode* cur = *head;
    while (cur->next)
        cur = cur->next;
    cur->next = newNode;
    newNode->prev = cur;
}

DNode* findDNode(DNode* head, int data) {
    while (head) {
        if (head->data == data) return head;
        head = head->next;
    }
    return NULL;
}

void deleteNode(DNode** head, DNode* node) {
    if (!node) return;
    if (node->prev)
        node->prev->next = node->next;
    else
        *head = node->next;
    if (node->next)
        node->next->prev = node->prev;
    free(node);
}

void printForward(DNode* head) {
    printf("Forward: ");
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void printBackward(DNode* head) {
    if (!head) { printf("Backward: NULL\n"); return; }
    while (head->next)
        head = head->next;
    printf("Backward: ");
    while (head) {
        printf("%d ", head->data);
        head = head->prev;
    }
    printf("\n");
}

void freeDList(DNode** head) {
    DNode* cur = *head;
    while (cur) {
        DNode* tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    *head = NULL;
}

int main() {
    DNode* head = NULL;

    insertAtHead(&head, 3);
    insertAtHead(&head, 2);
    insertAtHead(&head, 1);
    printForward(head);
    printBackward(head);

    insertAtTail(&head, 4);
    insertAtTail(&head, 5);
    printForward(head);
    printBackward(head);

    DNode* node = findDNode(head, 3);
    deleteNode(&head, node);
    printForward(head);
    printBackward(head);

    freeDList(&head);
    printForward(head);
    printBackward(head);

    return 0;
}
