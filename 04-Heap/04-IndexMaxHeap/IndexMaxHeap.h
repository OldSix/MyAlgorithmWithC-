//
// Created by Queen on 2017/2/17.
//

#ifndef INC_04_INDEXMAXHEAP_INDEXMAXHEAP_H
#define INC_04_INDEXMAXHEAP_INDEXMAXHEAP_H

#include <algorithm>
#include <cassert>

template <typename Item>
class IndexMaxHeap
{
private:
    Item * data;
    int * indexes;
    int capacity;
    int count;

    void shiftUp(int k) {
        while (k > 1 && data[indexes[k/2]] < data[indexes[k]]) {
            std::swap(indexes[k/2], indexes[k]);
            k /= 2;
        }
    }

    void shiftDown(int k) {
        while (2*k <= count) {
            int i = 2*k;
            if (i+1 <= count && data[indexes[i+1]] > data[indexes[i]]) {
                i += 1;
            }
            if (data[indexes[k]] >= data[indexes[i]]) break;
            std::swap(indexes[k], indexes[i]);

            k = i;
        }
    }

public:
    IndexMaxHeap(int capacity) {
        data = new Item[capacity+1];
        indexes = new Item[capacity+1];

        this->capacity = capacity;
        count = 0;
    }

    ~IndexMaxHeap() {
        delete[] data;
        delete[] indexes;
    }

    void insert(int i, Item item) {
        assert(count+1<=capacity);
        assert(i+1>=1 && i+1<=capacity);

        i += 1;
        data[i] = item;
        indexes[count+1] = i;
        count++;

        shiftUp(count);
    }

    Item extractMax() {
        assert(count > 0);

        Item ret = data[indexes[1]];
        std::swap(indexes[1], indexes[count]);
        count--;
        shiftDown(1);

        return ret;
    }

    int extractMaxIndex() {
        assert(count > 0);

        int ret = indexes[1] - 1;
        std::swap(indexes[1], indexes[count]);
        count--;
        shiftDown(1);

        return ret;
    }

    Item getMax() {
        assert(count > 0);
        return data[indexes[1]];
    }

    Item getItem(int i) {
        return data[i+1];
    }

    int getMaxIndex() {
        assert(count > 0);
        return indexes[1]-1;
    }

    void change(int i, Item newItem) {
        i += 1;
        data[i] = newItem;

        for (int j = 1; j <= count; ++j) {
            if (indexes[j] == i) {
                shiftUp(j);
                shiftDown(j);
                return;
            }
        }
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

};


#endif //INC_04_INDEXMAXHEAP_INDEXMAXHEAP_H
