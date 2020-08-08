#include <stdio.h>

#define N 5

template <typename T = int>
void swap(T& a, T& b) {
    T t = a;

    a = b;
    b = t;
}

template <typename T = int>
void qsrt(T* a, int l, int h) {
    if (l >= h)
        return;

    int i = l;
    int j = h;
    int p = h;

    while (1) {
        while (i < p && a[i] <= a[p]) i++;
        while (p < j && a[p] < a[j]) j--;

        if (i >= j)
            break;

        swap(a[i], a[j]);
    }

    swap(a[i], a[p]);

    qsrt(a, l, p - 1);
    qsrt(a, p + 1, h);
}

int main() {
    int a[N] = { 4, 2, 0, 3, 1 };

    qsrt(a, 0, N - 1);

    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);

    return printf("\n");
}
