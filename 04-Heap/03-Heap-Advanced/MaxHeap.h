//
// Created by Queen on 2017/2/16.
//

#ifndef INC_03_HEAP_ADVANCED_MAXHEAP_H
#define INC_03_HEAP_ADVANCED_MAXHEAP_H

template <typename Item>
class MaxHeap
{
private:
    Item * data;
    int capacity;
    int count;

    void shiftUp(int k) {}
    void shiftDown(int k) {}

public:
    MaxHeap(int capacity) {}
    MaxHeap(Item arr[], int n) {}
    ~MaxHeap() {}

    int size() {}
    bool isEmpty() {}
    void insertItem(Item item) {}
    Item extractMax() {}
};


#endif //INC_03_HEAP_ADVANCED_MAXHEAP_H
