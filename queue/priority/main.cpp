#include <stdio.h>
#include <math.h>

template <typename T>
void swap(T& a, T& b) {
    T t = a;
    a = b;
    b = t;
}

template <typename T, size_t S>
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

        return buf[l] < buf[r] ? l : r;
    }

    bool empty() {
        return tail < 0;
    }

    T& push(T& d) {
        buf[++tail] = d;

        for (int c = tail, p = prn(c); 0 < c; p = prn(p = c)) {
            if (buf[p] < buf[c])
                break;

            swap(buf[p], buf[c]);
        }

        return d;
    }

    T pop() {
        T t = buf[0];
        buf[0] = buf[tail--];

        for (int p = 0, c = sch(p); c <= tail; c = sch(p = c)) {
            if (buf[p] < buf[c])
                break;

            swap(buf[p], buf[c]);
        }

        return t;
    }

    void dump(const char* s, T d) {
        printf("%4s: d=%d, tail=%2d, ", s, d, tail);

        for (int i = 0; i <= tail; i++)
            printf("%d ", buf[i]);

        printf("\n");
    }
};

int main() {
    PriorityQueue<int, 5> q;

    for (int i; 1 < (i = (rand() % 10));) {
        if (i % 2)
            q.dump("push", q.push(i));
        else if (!q.empty())
            q.dump("pop", q.pop());
    }

    return 0;
}

#if 0
push: d=3, tail= 0, 3 
 pop: d=3, tail=-1, 
push: d=7, tail= 0, 7 
push: d=5, tail= 1, 5 7 
push: d=3, tail= 2, 3 7 5 
push: d=5, tail= 3, 3 5 5 7 
 pop: d=3, tail= 2, 5 5 7 
 pop: d=5, tail= 1, 5 7 
push: d=9, tail= 2, 5 7 9 
#endif
