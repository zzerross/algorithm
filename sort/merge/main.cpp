#include <stdio.h>

template <typename T, int S>
void msrt(T* a, int l, int h) {
    static T b[S];

    if (l >= h)
        return;

    int m = (l + h) / 2;
    int i = l;
    int j = m + 1;
    int k = l;

    msrt<T, S>(a, l, m);
    msrt<T, S>(a, m + 1, h);

    while (i <= m && j <= h)
        b[k++] = a[i] < a[j] ? a[i++] : a[j++];

    while (i <= m)
        b[k++] = a[i++];

    while (j <= h)
        b[k++] = a[j++];

    for (i = l; i <= h; i++)
        a[i] = b[i];
}

int main() {
#define S 5
    int a[S] = { 2, 1, 4, 3, 0 }; 

    msrt<int, S>(a, 0, S - 1);

    for (int i = 0; i < S; i++)
        printf("%d ", a[i]);

    printf("\n");

    return 0;
}

/**
 * $ g++ main.cpp
 * $ ./a.out
 * 0 1 2 3 4 
 */
