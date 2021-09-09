#if D
#include <stdio.h>
#define D0(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define D1(fmt, ...) D0("%16s: " fmt, __func__, ##__VA_ARGS__);
#else
#define D0(fmt, ...)
#define D1(fmt, ...)
#endif

#define MAX_NODE 10000

template <typename T>
struct Node {
public:
    T data;
    Node<T>* prev;
    Node<T>* next;

    Node(): data(0), prev(nullptr), next(nullptr) {
    }

    Node(T data): data(data) {
        Node();
    }

    virtual void addNext(Node<T>* prev, Node<T>* next) {
        next->prev = prev;
        next->next = prev->next;

        prev->next->prev = next;
        prev->next = next;
    }

    virtual void addPrev(Node<T>* prev, Node<T>* next) {
        prev->prev = next->prev;
        prev->next = next;

        next->prev->next = prev;
        next->prev = prev;
    }

    virtual Node<T>* remove(Node<T>* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;

        return node;
    }
};

template <typename T>
class DoubleLinkedList : public Node<T> {
private:
#define DUMP(ptr) \
    do { \
        D1("cnt=%4lu, ", size); \
        \
        Node<T>* node = ptr; \
        for (int i = 0; i < size; i++, node = node->ptr) { \
            D0("%4d ", node->data); \
        } \
        \
        if (node) { \
            D0(", %d\n", node->data); \
        } else { \
            D0(", (nil)\n"); \
        } \
    } while(0);

#define DUMP2() \
    DUMP(Node<T>::next); \
    DUMP(Node<T>::prev);

public:
    DoubleLinkedList() {
        Node<T>();

        init();
    }

    void add(int index, T data) {
        D1("data=%d index=%d\n", data, index);

        Node<T>* node = this;
        for (int i = 1; i < index; i++)
            node = node->next;

        Node<T>::addNext(node, new Node<T>(data));
        size++;

        DUMP2();
    }

    void addFirst(T data) {
        D1("data=%d\n", data);

        Node<T>::addNext(this, new Node<T>(data));
        size++;

        DUMP2();
    }

    void addLast(T data) {
        D1("data=%d\n", data);

        Node<T>::addPrev(new Node<T>(data), this);
        size++;

        DUMP2();
    }

    size_t find(T data) {
        Node<T>* node = Node<T>::next;
        for (int i = 0; i < size; i++, node = node->next)
            if (node->data == data)
                return i;

        return 0;
    }

    Node<T>* remove(T data) {
        D1("data=%d\n", data);

        Node<T>* node = Node<T>::next;
        for (int i = 0; i < size; i++, node = node->next) {
            if (node->data == data) {
                size--;
                Node<T>::remove(node);
            }
        }

        DUMP2();
        return node;
    }

    void removeFirst() {
        delete Node<T>::remove(Node<T>::next);
    }

    void removeLast() {
        delete Node<T>::remove(Node<T>::prev);
    }

    int toArray(int output[MAX_NODE]) {
        Node<T>* node = Node<T>::next;
        for (int i = 0; i < size; i++, node = node->next)
            output[i] = node->data;

        return size;
    }

    int toReversedArray(int output[MAX_NODE]) {
        Node<T>* node = Node<T>::prev;
        for (int i = 0; i < size; i++, node = node->prev)
            output[i] = node->data;

        return size;;
    }

    void removeAll() {
        Node<T>* node = Node<T>::next;
        for (int i = 0; i < size; i++, node = node->prev)
            delete Node<T>::remove(node);
            
        init();
    }

    void init() {
        Node<T>::prev = this;
        Node<T>::next = this;
        size = 0;
    }

protected:
private:
    size_t size;
};
