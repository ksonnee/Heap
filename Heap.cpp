#include "heap.h"
#include <iostream>

Heap::Heap() : size(0) {}

void Heap::insert(int value) {
    data.push_back(value);
    size++;
    int i = size - 1;
    while (i > 0 && data[(i - 1) / 2] < data[i]) {
        std::swap(data[i], data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void Heap::heapify(int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && data[left] > data[largest])
        largest = left;

    if (right < size && data[right] > data[largest])
        largest = right;

    if (largest != index) {
        std::swap(data[index], data[largest]);
        heapify(largest);
    }
}

void Heap::heapSort() {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(i);

    for (int i = size - 1; i >= 0; i--) {
        std::swap(data[0], data[i]);
        size--;
        heapify(0);
    }
}

void Heap::printHeap() {
    for (int i = 0; i < size; i++)
        std::cout << data[i] << " ";
    std::cout << std::endl;
}
