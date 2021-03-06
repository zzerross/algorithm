#include <stdio.h>
#include <stdlib.h>
#include <time.h>

template <typename T = int>
void swap(T& a, T& b) {
    T t = a;

    a = b;
    b = t;
}

template <typename T = int>
void qsrt(T* a, int l, int h) {
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

        swap(a[i], a[p]);

        qsrt(a, l, p - 1);
        qsrt(a, p + 1, h);
    }
}

int main() {
    srand((unsigned int) time(NULL));

    for (int n, t = 0; t < 10; t++) {
        int a[n = rand () % 10];

        for (int i = 0; i < n; i++)
            printf("%d ", a[i] = rand() % 10);
        printf("\n");

        qsrt(a, 0, n - 1);

        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }

    return 0;
}
