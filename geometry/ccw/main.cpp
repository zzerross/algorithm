#include <stdio.h>

template <typename T>
struct vector2d {
    T x, y;

    vector2d(T x, T y): x(x), y(y) {
    }

    T cross(const vector2d& o) const {
        return x * o.y - y * o.x;
    }

    T ccw(const vector2d& o) const {
        return cross(o);
    }
};

int main() {
    {
        vector2d<int> v(1, 1);
        printf("\n"
               " 2 b . . \n"
               " 1 . a . \n"
               " 0 + . . \n"
               "   0 1 2 \n"
               "ccw(a->b): %d\n", v.ccw({0, 2}));
    }
    {
        vector2d<int> v(0, 2);
        printf("\n"
               " 2 a . . \n"
               " 1 . b . \n"
               " 0 + . . \n"
               "   0 1 2 \n"
               "ccw(a->b): %d\n", v.ccw({1, 1}));
    }
    {
        vector2d<int> v(1, 1);
        printf("\n"
               " 2 . . b \n"
               " 1 . a . \n"
               " 0 + . . \n"
               "   0 1 2 \n"
               "ccw(a->b): %d\n", v.ccw({2, 2}));
    }

    return 0;
}
