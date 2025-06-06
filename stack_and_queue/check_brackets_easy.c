#include <stdio.h>
#include <string.h>

#define MAX 1000005

char s[MAX];        // Chuỗi nhập vào
char stack[MAX];    // Ngăn xếp (stack) để lưu các dấu mở
int top = -1;       // Đỉnh của stack, -1 là stack rỗng

// Hàm kiểm tra 2 dấu có hợp nhau không (dấu mở và dấu đóng)
int is_pair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '[' && close == ']') return 1;
    if (open == '{' && close == '}') return 1;
    return 0;
}

int main() {
    scanf("%s", s);
    int len = strlen(s);

    for (int i = 0; i < len; ++i) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            // Nếu là dấu mở, đẩy vào stack
            stack[++top] = c;
        } else if (c == ')' || c == ']' || c == '}') {
            // Nếu là dấu đóng
            if (top == -1) {
                // Nếu stack rỗng => sai
                printf("0\n");
                return 0;
            }
            if (!is_pair(stack[top], c)) {
                // Nếu không khớp với dấu mở trên cùng => sai
                printf("0\n");
                return 0;
            }
            --top; // Đúng thì bỏ dấu mở trên cùng ra khỏi stack
        }
    }

    // Nếu sau khi duyệt hết mà stack vẫn còn dấu mở => sai
    if (top == -1) printf("1\n");
    else printf("0\n");

    return 0;
}