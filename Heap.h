#ifndef HEAP_H
#define HEAP_H

#include <vector>

class Heap {
private:
    std::vector<int> data;
    int size;

    void heapify(int index);

public:
    Heap();

    void insert(int value);

    void heapSort();

    void printHeap();
};

#endif // HEAP_H

