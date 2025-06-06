#include <stdio.h>
#include <stdbool.h>

int n, a[10], used[10];

bool is_even(int x) {
    return x % 2 == 0;
}

void print_permutation() {
    for (int i = 1; i <= n; ++i) {
        printf("%d", a[i]);
        if (i < n) printf(" ");
    }
    printf("\n");
}

void backtrack(int pos) {
    if (pos > n) {
        print_permutation();
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            if (pos > 1 && is_even(a[pos-1]) && is_even(i))
                continue;
            a[pos] = i;
            used[i] = 1;
            backtrack(pos + 1);
            used[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    backtrack(1);
    return 0;
}