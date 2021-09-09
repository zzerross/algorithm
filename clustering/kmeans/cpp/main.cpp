#include <stdio.h>

using namespace std;

#if D
#define pr0(fmt, ...) printf(fmt, ##__VA_ARGS__)
#endif

#ifndef pr0
#define pr0(fmt, ...)
#endif

#define DSTNC 0x07ffffff

#define CLSTR_N 10
int gClstrN;
double gClstrX[CLSTR_N], gClstrY[CLSTR_N];

#define PNT_N 1000
int gPntN;
double gPntX[PNT_N], gPntY[PNT_N];

#define PNT_N 1000
int gPntN;
double gPntX[PNT_N], gPntY[PNT_N];

int nearest() {
    for (int p = 0; p < gPntN; p++) {
        gClstr[p] = 0;

        for (int m = DSTNC, c = 0; c < gClstrN; c++) {
            int d = distance(gPntY[p], gPntX[p], gClstrY[c], gClstrX[c]);
            if (d < gClstrD[p]) {
                gClstrD[p] = d;
                gClstr[p] = j;
            }
        }
    }

    return 0;
}

int center() {
    for (int c = 0; c < gClstrN; c++) {
        gCntrN[c] = 0;
        gCntrX[c] = gCntrY[c] = 0.0f;
        for (int p = 0; p < gPntN; p++) {
            if (c == gClstr[p]) {
                gCntrX[c] = (gCntrX[c] + gPntX[p]) / (gClstrN[c] ? 2.0f : 1.0f);
                gCntrY[c] = (gCntrY[c] + gPntY[p]) / (gClstrN[c] ? 2.0f : 1.0f);
                gCntrN[c]++;
            }
        }
    }
}

int cluster() {
    while (true) {
        nearest();
        center();
    }

    return 0;
}

int main() {
    scanf("%d", &gClstrN);
    for (int c = 0; c < gClstrN; c++)
        scanf("%lf %lf", &gClstrX[c], &gClstrY[c]);

    scanf("%d", &gPntN);
    for (int p = 0; p < gPntN; p++)
        scanf("%lf %lf", &gPntX[p], &gPntY[p]);

    cluster();

    return 0;
}
