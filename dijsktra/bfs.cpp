#include <limits.h>
#include <stdio.h>

#define N 9

int G[N][N] = { 
    { 0,  4, 0,  0,  0,  0,  0,  8,  0 }, 
    { 4,  0, 8,  0,  0,  0,  0, 11,  0 }, 
    { 0,  8, 0,  7,  0,  4,  0,  0,  2 }, 
    { 0,  0, 7,  0,  9, 14,  0,  0,  0 }, 
    { 0,  0, 0,  9,  0, 10,  0,  0,  0 }, 
    { 0,  0, 4, 14, 10,  0,  2,  0,  0 }, 
    { 0,  0, 0,  0,  0,  2,  0,  1,  6 }, 
    { 8, 11, 0,  0,  0,  0,  1,  0,  7 }, 
    { 0,  0, 2,  0,  0,  0,  6,  7,  0 },
}; 

int D[N];

template <typename T>
void swap(T a, T b) {
    T t = a;
    a = b;
    b = t;
}

template <typename T, int S>
struct PriorityQueue {
    T buf[S];
    int tail = -1;

    int prn(int i) { return (i - 1) / 2; }
    int lch(int i) { return (i * 2) + 1; }
    int rch(int i) { return (i * 2) + 2; }
    int sch(int i) {
        int l = lch(i);
        int r = rch(i);

        if (tail < r)
            return l;

        return D[buf[l]] < D[buf[r]] ? l : r;
    }

    bool empty() {
        return tail < 0;
    }

    void push(T d) {
        buf[++tail] = d;

        for (int c = tail, p = prn(c); 0 < c; p = prn(c = p)) {
            if (D[buf[p]] < D[buf[c]])
                break;

            swap(buf[p], buf[c]);
        }
    }

    T pop() {
        T d = buf[0];
        buf[0] = buf[tail--];

        for (int p = 0, c = sch(p); c <= tail; c = sch(p = c)) {
            if (D[buf[p]] < D[buf[c]])
                break;

            swap(buf[p], buf[c]);
        }

        return d;
    }
};

struct PriorityQueue<int, N> Q;

void dijkstra(int src, int dst) {
    for (int i = 0; i < N; i++)
        D[i] = INT_MAX;

    D[src] = 0;
    Q.push(src);

    while (!Q.empty()) {
        int i = Q.pop();

        if (i == dst)
            break;

        for (int j = 0; j < N; j++) {
            if (!G[i][j])
                continue;

            if (D[i] + G[i][j] < D[j]) {
                D[j] = D[i] + G[i][j];
                Q.push(j);
            }
        }
    }
}

int main() {
    dijkstra(0, N - 1);

    for (int i = 0; i < N; i++)
        printf("%d: %2d\n", i, D[i]);

    return 0;
}
