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
bool V[N];

int shortest() {
    int v = 0;

    for (int d = INT_MAX, i = 0; i < N; i++)
        if (!V[i] && D[i] <= d)
            d = D[v = i];

    return v;
}

void dijkstra(int src) {
    for (int i = 0; i < N; i++) {
        D[i] = INT_MAX;
        V[i] = false;
    }

    D[src] = 0;

    for (int c = 0; c < N - 1; c++) {
        int i = shortest();

        V[i] = true;

        for (int j = 0; j < N; j++) {
            if (V[j])
                continue;

            if (!G[i][j])
                continue;

            if (D[i] == INT_MAX)
                continue;

            if (D[i] + G[i][j] < D[j])
                D[j] = D[i] + G[i][j];
        }
    }
}

int main() {
    dijkstra(0);

    for (int i = 0; i < N; i++)
        printf("%d: %2d\n", i, D[i]);

    return 0;
}
