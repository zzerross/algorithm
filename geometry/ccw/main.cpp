#include <stdio.h>

template <typename T>
struct Vector2D {
    T x, y;

    Vector2D(): x(0), y(0) {
    }

    Vector2D(T x, T y): x(x), y(y) {
    }

    T cross(const Vector2D& o) const {
        return x * o.y - y * o.x;
    }

    T ccw(const Vector2D& o) const {
        return cross(o);
    }

    T ccw(const Vector2D& a, const Vector2D& b) const {
        Vector2D oa = a - *this;
        Vector2D ob = b - *this;

        return oa.cross(ob);
    }

    bool operator<(const Vector2D& o) const {
        return x == o.x ?  y < o.y : x < o.x;
    }

    Vector2D operator-(const Vector2D& o) const {
        return Vector2D<T>(x - o.x, y - o.y);
    }

    void dump(const char* s) {
        pr1("%8s: %d %d\n", s, x, y);
    }
};

int main() {
    Vector2D<int> o(0, 0);

    printf("\n"
            " 2 b . . \n"
            " 1 . a . \n"
            " 0 + . . \n"
            "   0 1 2 \n"
            "ccw(a->b): %d\n", o.ccw({1, 1}, {0, 2}));

    printf("\n"
            " 2 a . . \n"
            " 1 . b . \n"
            " 0 + . . \n"
            "   0 1 2 \n"
            "ccw(a->b): %d\n", o.ccw({0, 2}, {1, 1}));

    printf("\n"
            " 2 . . b \n"
            " 1 . a . \n"
            " 0 + . . \n"
            "   0 1 2 \n"
            "ccw(a->b): %d\n", o.ccw({1, 1}, {2, 2}));

    return 0;
}
