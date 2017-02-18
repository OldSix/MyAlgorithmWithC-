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
    Item * data;// 注意：data中可能面临是的离散存储
    int  * indexes;// 索引堆中的位置所对应的索引
    int  * reverse;// 索引所对应的在索引堆中的位置
    int capacity;
    int count;

    void shiftUp(int k) {
        // 非根节点，且当前节点大于父节点，进入循环
        while (k > 1 && data[indexes[k/2]] < data[indexes[k]]) {
            std::swap(indexes[k/2], indexes[k]);
            reverse[indexes[k/2]] = k/2;
            reverse[indexes[k]] = k;

            k /= 2;
        }
    }

    void shiftDown(int k) {
        // 有子节点进入循环
        while (2*k <= count) {
            int i = 2*k;
            if (i+1<=count && data[indexes[i+1]] > data[indexes[i]]) {
                i += 1;
            }
            if (data[indexes[k]] > data[indexes[i]]) break;
            std::swap(indexes[k], indexes[i]);
            reverse[indexes[k]] = k;
            reverse[indexes[i]] = i;

            k = i;
        }
    }

public:
    IndexMaxHeap(int capacity) {
        data = new Item[capacity+1];
        indexes = new int[capacity+1];
        reverse = new int[capacity+1];
        for (int i = 0; i <= capacity; ++i) {
            reverse[i] = 0;
        }
        this->capacity = capacity;
        count = 0;
    }

    ~IndexMaxHeap() {
        delete[] data;
        delete[] indexes;
        delete[] reverse;
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    // 外部传入的索引，默认从 0 开始
    void insert(int i, Item item) {
        assert(count+1 <= capacity);
        assert(i+1>=1 && i+1<=capacity);

        i += 1;
        data[i] = item;
        indexes[count+1] = i;
        reverse[i] = count+1;
        ++count;
        shiftUp(count);
    }

    Item extractMax() {
        assert(count > 0);

        Item ret = data[indexes[1]];
        std::swap(indexes[1], indexes[count]);
        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;
        --count;
        shiftDown(1);

        return ret;
    }

    int extractMaxIndex() {
        assert(count > 0);

        int ret = indexes[1] - 1;
        std::swap(indexes[1], indexes[count]);
        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;
        --count;
        shiftDown(1);

        return ret;
    }

    bool containItem(int i) {
        assert(i+1>=1 && i+1<=capacity);
        return reverse[i+1] != 0;
    }

    void change(int i, Item newItem) {
        assert(containItem(i));

        i += 1;
        data[i] = newItem;

        int j = reverse[i];
        shiftDown(j);
        shiftUp(j);
    }
};


#endif //INC_04_INDEXMAXHEAP_INDEXMAXHEAP_H
