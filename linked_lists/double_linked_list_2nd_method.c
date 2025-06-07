#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

Node* find(int k) {
    Node* p = head;
    while (p != NULL) {
        if (p->key == k) return p;
        p = p->next;
    }
    return NULL;
}

void addfirst(int k) {
    if (find(k)) return;
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = k;
    node->prev = NULL;
    node->next = head;
    if (head != NULL) head->prev = node;
    else tail = node;
    head = node;
}

void addlast(int k) {
    if (find(k)) return;
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = k;
    node->next = NULL;
    node->prev = tail;
    if (tail != NULL) tail->next = node;
    else head = node;
    tail = node;
}

void addafter(int u, int v) {
    if (find(u)) return;
    Node* pv = find(v);
    if (!pv) return;
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = u;
    node->prev = pv;
    node->next = pv->next;
    if (pv->next != NULL) pv->next->prev = node;
    else tail = node;
    pv->next = node;
}

void addbefore(int u, int v) {
    if (find(u)) return;
    Node* pv = find(v);
    if (!pv) return;
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = u;
    node->next = pv;
    node->prev = pv->prev;
    if (pv->prev != NULL) pv->prev->next = node;
    else head = node;
    pv->prev = node;
}

void remove_key(int k) {
    Node* p = find(k);
    if (!p) return;
    if (p->prev != NULL) p->prev->next = p->next;
    else head = p->next;
    if (p->next != NULL) p->next->prev = p->prev;
    else tail = p->prev;
    free(p);
}

void reverse() {
    Node *cur = head, *tmp = NULL;
    while (cur != NULL) {
        tmp = cur->prev;
        cur->prev = cur->next;
        cur->next = tmp;
        cur = cur->prev;
    }
    tmp = head;
    head = tail;
    tail = tmp;
}

void output(int o) {
    if (o == 1) {
        Node* p = head;
        while (p != NULL) {
            printf("%d ", p->key);
            p = p->next;
        }
    } else {
        Node* p = tail;
        while (p != NULL) {
            printf("%d ", p->key);
            p = p->prev;
        }
    }
    printf("\n");
}

int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        addlast(x);
    }
    char cmd[100];
    while (1) {
        scanf("%s", cmd);
        if (strcmp(cmd, "#") == 0) break;
        if (strcmp(cmd, "addlast") == 0) {
            int k; scanf("%d", &k);
            addlast(k);
        } else if (strcmp(cmd, "addfirst") == 0) {
            int k; scanf("%d", &k);
            addfirst(k);
        } else if (strcmp(cmd, "addafter") == 0) {
            int u, v; scanf("%d%d", &u, &v);
            addafter(u, v);
        } else if (strcmp(cmd, "addbefore") == 0) {
            int u, v; scanf("%d%d", &u, &v);
            addbefore(u, v);
        } else if (strcmp(cmd, "remove") == 0) {
            int k; scanf("%d", &k);
            remove_key(k);
        } else if (strcmp(cmd, "reverse") == 0) {
            reverse();
        } else if (strcmp(cmd, "output") == 0) {
            int o; scanf("%d", &o);
            output(o);
        }
    }
    return 0;
}