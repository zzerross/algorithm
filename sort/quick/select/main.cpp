#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

template <typename T = int>
void swap(T& a, T& b) {
    T t = a;

    a = b;
    b = t;
}

template <typename T = int>
T qslt(T* a, int l, int h, int k) {
    if (l < h) {
        int i = l;
        int j = h;
        int p = h;

        while (i < j) {
            while (i < p && a[i] <= a[p]) i++;
            while (p < j && a[p] < a[j]) j--;

            if (i < j)
                swap(a[i], a[j]);
        }

        if (j != k) {
            swap(a[i], a[p]);

            qslt(a, l, p - 1, k);
            qslt(a, p + 1, h, k);
        }
    }

    return a[k];
}

int main() {
    srand((unsigned int) time(NULL));

    for (int n, t = 0; t < 10; t++) {
        int a[n = rand () % 10];

        for (int i = 0; i < n; i++)
            printf("%d ", a[i] = rand() % 10);
        printf("\n");

        for (int i = 0; i < n; i++)
            printf("%d ", qslt(a, 0, n - 1, i));
        printf("\n");
    }

    return 0;
}
