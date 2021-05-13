#include <cstdio>
#include <climits>

template <typename T>
T max(T a, T b) {
    return a < b ? b : a;
}

size_t digits(long long n) {
    size_t d = 1;

    for (; n /= 10; d++);

    return d;
}

size_t mdigits(size_t a, size_t b) {
    size_t d = 0;

    d += (a == 1 ? 0 : a);
    d += (b == 1 ? 0 : b);

    return max(d, 1UL);
}

int main() {
    for (long long n = LLONG_MAX; 0 < n; n /= 10)
        printf("digits(%-20lld)=%2lu\n", n, digits(n));

    for (long long n = LLONG_MIN; n < 0; n /= 10)
        printf("digits(%-20lld)=%2lu\n", n, digits(n));

    for (int a = SHRT_MAX; 0 < a; a /= 10) {
        for (int b = SHRT_MAX; 0 < b; b /= 10) {
            long long m = a * b;

            printf("\n");
            printf("%-5d x %-5d = %lld\n", a, b, m);
            printf("%-5lu x %-5lu = %lu, %lu\n",
                    digits(a), digits(b),
                    digits(m),
                    mdigits(digits(a), digits(b)));
        }
    }

    return 0;
}
