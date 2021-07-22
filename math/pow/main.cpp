#include <stdio.h>
#include <math.h>

int D(int n, const char* e = nullptr) {
#if 1
    for (int i = sizeof(n) * 8 - 1; 0 <= i; i--)
        printf("%d%s", n >> i & 1, i % 4 ? "" : " ");

    printf(", %x, %d\n%s", n, n, e ? e : "");
#endif

    return n;
}

int ceil2pow(int a){
    D(a); printf("\n");

    --a;

    D(a |= D(D(a) >>  1), "\n");
    D(a |= D(D(a) >>  2), "\n");
    D(a |= D(D(a) >>  4), "\n");
    D(a |= D(D(a) >>  8), "\n");
    D(a |= D(D(a) >> 16), "\n");

    return D(a + 1);
}

int c2pow(int a) {
    --a;

    for (int s = 1; s <= 16; s *= 2)
        a |= (a >> s);

    return ++a;
}

int main() {
    int i = 0xffffffff;

    printf("%08x %d\n", i, i);

    i = i >> 1;
    printf("%08x %d\n", i, i);

    i = i >> 1;
    printf("%08x %d\n", i, i);

    for (int i = 0; i <= 10; i++) {
        printf("ceil2pow(%2d)=%2d ", i, ceil2pow(i));
        printf("c2pow(%2d)=%2d", i, c2pow(i));
        printf("\n\n");
    }

    return 0;
}
