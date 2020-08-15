#include <stdio.h>
#include <algorithm>

using namespace std;

int* lbnd(int* a, int l, int h, int t) {
    while (l < h) {
        int m = (l + h) / 2;

        if (a[m] < t)
            l = m + 1;
        else
            h = m;
    }

    return a + l;
}

int main() {
#define S 3
    int A[S] = { 0, 5, 9 };

    for (int i = 0; i < S; i++)
        printf("%d ", A[i]);
    printf("\n");

    printf("Target Lower\n");
    printf("       Bound\n");

    for (int i = 0; i < 10; i++) {
        if (!(i % 5))
            printf("\n");

        printf("%6d ", i);
        printf("%2d/%2d\n", *lbnd(A, 0, S - 1, i), *lower_bound(A, A + S - 1, i));
    }

    return 0;
}

#ifdef output
0 5 9 
Target Lower
       Bound

     0  0/ 0
     1  5/ 5
     2  5/ 5
     3  5/ 5
     4  5/ 5

     5  5/ 5
     6  9/ 9
     7  9/ 9
     8  9/ 9
     9  9/ 9
#endif
