#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int min(const int& i, const int& j) { return i < j ? i : j; }

bool ascending(int a, int b) { return a < b; }

template <typename T, bool (*P)(T, T)>
void msrt(T* a, int s) {
  T b[s];

  for (int n = 1; n < s; n *= 2) {
    for (int i, j, p = 0; p < s;) {
      int l = p;
      int m = min(p += n, s) - 1;
      int h = min(p += n, s) - 1;

      for (i = l; i <= h; i++) b[i] = a[i];

      for (i = l, j = m + 1; i <= m && j <= h;)
        a[l++] = P(b[i], b[j]) ? b[i++] : b[j++];

      while (i <= m) a[l++] = b[i++];
      while (j <= h) a[l++] = b[j++];
    }
  }
}

void dump(int* a, int n) {
  printf("size=%d, ", n);

  for (int i = 0; i < n; i++) printf("%d ", a[i]);

  printf("\n");
}

int main() {
  srand((unsigned int)time(NULL));

  for (int a[9], s; 0 < (s = (rand() % 10));) {
    for (int i = 0; i < s; i++) a[i] = rand() % 10;

    msrt<int, ascending>(a, s);

    dump(a, s);
  }

  return 0;
}
