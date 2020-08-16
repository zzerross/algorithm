#include <stdio.h>
#include <algorithm>

using namespace std;

int* bnd(int* a, int l, int h, int t, bool u = false) {
    while (l < h) {
        int m = (l + h) / 2;

        if (a[m] < t || (u && a[m] == t))
            l = m + 1;
        else
            h = m;
    }

    return a + l;
}

int main() {
#define S 3
    int A[S] = { 1, 4, 8 };

    for (int i = 0; i < S; i++)
        printf("%d ", A[i]);
    printf("\n");

    printf("Target Lower Upper\n");
    printf("       Bound Bound\n");

    for (int i = 0; i < 10; i++) {
        if (!(i % 4))
            printf("\n");

        printf("%6d ", i);
        printf("%2d/%2d ", *bnd(A, 0, S - 1, i, false), *lower_bound(A, A + S - 1, i));
        printf("%2d/%2d\n", *bnd(A, 0, S - 1, i, true), *upper_bound(A, A + S - 1, i));
    }

    return 0;
}

#ifdef output
1 4 8 
Target Lower Upper
       Bound Bound

     0  1/ 1  1/ 1
     1  1/ 1  4/ 4
     2  4/ 4  4/ 4
     3  4/ 4  4/ 4

     4  4/ 4  8/ 8
     5  8/ 8  8/ 8
     6  8/ 8  8/ 8
     7  8/ 8  8/ 8

     8  8/ 8  8/ 8
     9  8/ 8  8/ 8
#endif
