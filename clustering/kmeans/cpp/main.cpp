#include <array>
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

#if DEBUG == 1
#define pr0(fmt, ...) printf(fmt, ##__VA_ARGS__)
#endif

#ifndef pr0
#define pr0(fmt, ...)
#endif

#define POINTS 100000
#define RESULTS 3

template <typename T, typename R = unsigned short, int BITS = 16>
struct Random {
public:
    T next() {
        static R delta = 1;

        return (T) random() / (T) (random() + delta);
    }

    void test(int n) {
#if DEBUG == 1
        for (int i = 0; i < n; i++) {
            pr0("%.10lf\n", next());
        }
#endif
    }

private:
    constexpr static unsigned long long MAGIC = 25214903917ULL;

    unsigned long long SEED = 5;

    R random() {
        return ((R) ((SEED = SEED * (MAGIC) + 11ULL) >> BITS));
    }
};

template <typename T>
struct Point {
    T x;
    T y;
    T z;

    Point(): x(0), y(0), z(0) {
    }

    Point(T x, T y, T z): x(x), y(y), z(z) {
    }
};

template <typename T>
struct RandomPoints {
    array<Point<T>, POINTS> points;

    RandomPoints() {
        Random<T> r;

        generate(points.begin(), points.end(), [r]() mutable {
            return Point<T>(r.next(), r.next(), r.next());
        });
    }

    void dump(const char* s = nullptr) {
#if DEBUG == 1
        pr0("%10s: ", s ? s : "");

        for (auto& p : points) {
            // cout << "{ " << p.x << " " << p.y << " " << p.z << "}" << endl;
            pr0("%2.10lf, %2.10lf, %2.10lf,\n", p.x, p.y, p.z);
        }

        pr0("\n");
#endif
    }
};

int main() {
    RandomPoints<double> points;

    points.dump();

    cluster(points, );

    return 0;
}
