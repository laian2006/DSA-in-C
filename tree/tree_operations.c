#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1005

// --- Cấu trúc 1 node của cây ---
typedef struct Node {
    int val;
    struct Node* firstChild;  // con đầu
    struct Node* nextSibling; // anh em kế tiếp
} Node;

// Dùng mảng để quản lý các node (theo giá trị val)
// Giả sử các giá trị val đều <= MAXN
Node* nodes[MAXN];

// Hàm tạo node mới
Node* createNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->firstChild = NULL;
    node->nextSibling = NULL;
    return node;
}

// --- Các thao tác chính ---

// MakeRoot u: tạo nút gốc u
void MakeRoot(int u) {
    if (!nodes[u]) {
        nodes[u] = createNode(u);
    }
}

// Insert u v: tạo node u, chèn vào cuối danh sách con của node v
void Insert(int u, int v) {
    if (!nodes[u]) nodes[u] = createNode(u);
    if (!nodes[v]) nodes[v] = createNode(v);
    Node* par = nodes[v];
    Node* child = par->firstChild;
    if (!child) {
        par->firstChild = nodes[u];
    } else {
        while (child->nextSibling) child = child->nextSibling;
        child->nextSibling = nodes[u];
    }
}

// Đếm số lá của cây gốc u (lá: node không có con)
int CountLeaves(Node* node) {
    if (!node) return 0;
    if (!node->firstChild) return 1;
    int sum = 0;
    for (Node* child = node->firstChild; child; child = child->nextSibling)
        sum += CountLeaves(child);
    return sum;
}

// Đếm số node có đúng k con trong cây gốc u
int CountKChildren(Node* node, int k) {
    if (!node) return 0;
    int cnt = 0;
    int child_cnt = 0;
    for (Node* child = node->firstChild; child; child = child->nextSibling)
        child_cnt++;
    if (child_cnt == k) cnt++;
    for (Node* child = node->firstChild; child; child = child->nextSibling)
        cnt += CountKChildren(child, k);
    return cnt;
}

// --- MAIN ---
int main() {
    char cmd[30];
    // Khởi tạo mảng node
    memset(nodes, 0, sizeof(nodes));
    while (1) {
        if (!fgets(cmd, sizeof(cmd), stdin)) break;
        if (cmd[0] == '*') break;
        // Xử lý lệnh
        if (strncmp(cmd, "MakeRoot", 8) == 0) {
            int u;
            sscanf(cmd + 8, "%d", &u);
            MakeRoot(u);
        } else if (strncmp(cmd, "Insert", 6) == 0) {
            int u, v;
            sscanf(cmd + 6, "%d%d", &u, &v);
            Insert(u, v);
        } else if (strncmp(cmd, "CountLeaves", 11) == 0) {
            int u;
            sscanf(cmd + 11, "%d", &u);
            printf("%d\n", CountLeaves(nodes[u]));
        } else if (strncmp(cmd, "CountKChildren", 14) == 0) {
            int u, k;
            sscanf(cmd + 14, "%d%d", &u, &k);
            printf("%d\n", CountKChildren(nodes[u], k));
        }
    }
    return 0;
}