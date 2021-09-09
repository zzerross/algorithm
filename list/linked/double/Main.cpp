#include <stdio.h>

#include "DoubleLinkedList.hpp"

int main() {
    setbuf(stdout, NULL);

    DoubleLinkedList<int> list;

    list.addFirst(3);
    list.addLast(4);

    list.addFirst(2);
    list.addFirst(1);

    list.addLast(5);
    list.addLast(6);

    list.remove(4);
    list.removeFirst();
    list.removeLast();

    return 0;
}
