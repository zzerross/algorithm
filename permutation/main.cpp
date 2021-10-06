#include <stdio.h>

int dump(int* a, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    return 1;
}

template <typename T>
void swap(T& a, T& b) {
    T t = a;

    a = b;
    b = t;
}

template <typename T>
int perm(T* a, int n, int i = 0) {
    if (n <= i)
        return dump(a, n);

    int r = 0;

    for (int j = i; j < n; j++) {
        swap(a[i], a[j]);

        r += perm(a, n, i + 1);

        swap(a[i], a[j]);
    }

    return r;
}

int main() {
    int a[] = { 0, 1, 2 };

    printf("N=%d\n", perm(a, sizeof(a) / sizeof(a[0])));

    return 0;
}
