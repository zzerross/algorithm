#include <stdio.h>

using namespace std;

#if 1 <= DEBUG
#define D1(fmt, ...) printf(fmt, ##__VA_ARGS__)
#endif

#ifndef D1
#define D1(fmt, ...)
#endif

#define DISTANCE 0x07ffffff

template <typename T, int S>
struct Array {
    T buf[S];
    int len;

    T& operator[](int i) {
        return buf[i];
    }
};

template <typename T>
struct Point2d {
    T x, y;

    void init() {
        x = 0;
        y = 0;
    }

    T distance(const Point2d& o) const {
        return (x - o.x)*(x - o.x) + (y - o.y)*(y - o.y);
    }
};

template <int S>
struct DoublePoint2dArray : public Array<Point2d<double>, S> {
    void read() {
        scanf("%d", &this->len);

        for (int c = 0; c < this->len; c++)
            scanf("%lf %lf", &this->buf[c].x, &this->buf[c].y);
    }
};

#define CLUSTERS 10
DoublePoint2dArray<CLUSTERS> gClusters;
DoublePoint2dArray<CLUSTERS> gCenters;

#define POINTS 1000
DoublePoint2dArray<POINTS> gPoints;

Array<int, POINTS> gClusterOf;

void nearest() {
    for (int p = 0; p < gPoints.len; p++) {
        int m = DISTANCE;

        for (int c = 0; c < gClusters.len; c++) {
            int d = gPoints[p].distance(gClusters[c]);
            if (d < m) {
                m = d;
                gClusterOf[p] = c;
            }
        }

        D1("P[%d] %.1f %.1f: %d\n", p, gPoints[p].x, gPoints[p].y, gClusterOf[p]);
    }
}

void center() {
    int points[CLUSTERS] = { 0, };

    for (int c = 0; c < gClusters.len; c++) {
        gCenters[c].init();

        for (int p = 0; p < gPoints.len; p++) {
            if (c != gClusterOf[p])
                continue;

            points[c]++;

            gCenters[c].x = (gCenters[c].x + gPoints[p].x) / points[c];
            gCenters[c].y = (gCenters[c].y + gPoints[p].y) / points[c];
        }
    }
}

int main() {
    gClusters.read();
    gPoints.read();

    for (int p = 0; p < gPoints.len; p++)
        gClusterOf[p] = 0;

    while (true) {
        nearest();
        center();
    }

    return 0;
}
