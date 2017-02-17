//
// Created by Queen on 2017/2/16.
//

#ifndef INC_03_HEAP_ADVANCED_MAXHEAP_H
#define INC_03_HEAP_ADVANCED_MAXHEAP_H

#include <algorithm>
#include <cassert>

template <typename Item>
class MaxHeap
{
private:
    Item * data;
    int capacity;
    int count;

    void shiftUp(int k) {
        while (k > 1 && data[k/2] < data[k]) {// 父节点小于子节点才进行交换
            std::swap(data[k/2], data[k]);
            k /= 2;
        }
    }

    void shiftDown(int k) {
        while (2*k <= count) {// 循环停止条件，没有子节点，完全二叉树中，如果没有左子节点，那么一定也没有右子节点
            int i = 2*k;
            if (i+1 <= count && data[i+1] > data[i]) {
                i += 1;
            }
            if (data[k] >= data[i]) break;
            std::swap(data[k], data[i]);

            k = i;
        }
    }

public:
    MaxHeap(int capacity) {
        data = new Item[capacity+1];// 下标从1开始，索引 0 的位置空出
        this->capacity = capacity;
        count = 0;
    }

    MaxHeap(Item arr[], int n) {
        data = new Item[n+1];
        capacity = n;
        for (int i = 0; i < n; ++i) {
            data[i+1] = arr[i];
        }

        count = n;
        for (int j = n/2; j >= 1; --j) {
            shiftDown(j);
        }
    }

    ~MaxHeap() {
        delete[] data;
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insertItem(Item item) {
        if (count == capacity) {
            Item * tmp = new Item[2*capacity];
            std::copy(data, data+capacity, tmp);
            delete[] data;
            data = tmp;
            capacity *= 2;
        }

        data[count+1] = item;
        count++;

        shiftUp(count);
    }

    Item extractMax() {
        assert(count > 0);

        Item ret = data[1];
        std::swap(data[1], data[count]);
        count--;
        shiftDown(1);

        return ret;
    }

};


#endif //INC_03_HEAP_ADVANCED_MAXHEAP_H
