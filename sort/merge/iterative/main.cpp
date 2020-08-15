#include <stdio.h>

#define S 5

int min(const int& i, const int& j) {
    return i < j ? i : j;
}

void msrt(int* a, int n) { 
    for (int s = 1; s < n; s *= 2) {
        for (int p = 0; p < n;) {
            static int b[S], i, j;
            int l = p;
            int m = min(p += s, n) - 1;
            int h = min(p += s, n) - 1;

            for (i = l; i <= h; i++)
                b[i] = a[i];

            for (i = l, j = m + 1; i <= m && j <= h;)
                a[l++] = b[i] <= b[j] ? b[i++] : b[j++];

            while (i <= m)
                a[l++] = b[i++];

            while (j <= h)
                a[l++] = b[j++];
        }
    }
}

int main() {
    int A[S] = { 4, 2, 0, 2, 1 };

    msrt(A, S);

    for (int i = 0; i < S; i++)
        printf("%d ", A[i]);

    return 0;
}
