//
// Created by Queen on 2017/2/16.
//

#ifndef INC_02_HEAPIFY_MAXHEAP_H
#define INC_02_HEAPIFY_MAXHEAP_H


/**
 *  数组实现法：下标从 1 开始
 *
 * */
template <typename Item>
class MaxHeap
{
private:
    Item *data;
    int count;
    int capacity;

    void shiftUp(int k) {

        // k == 1 时，已经到根节点，不需要再判断
        while (k > 1 && data[k/2] < data[k]) {// 最大堆：父节点大于任一子节点
            std::swap(data[k/2], data[k]);
            k /= 2;
        }
    }

    void shiftDown(int k) {
        while (2*k <= count) {// 是否有左子树， 没有左子树，就没有右子树，也就没有子节点
            int i = 2*k; // 本轮交换的位置,初始值为左子树
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
        data = new Item[capacity+1];
        count = 0;
        this->capacity = capacity;
    }

    MaxHeap(Item arr[], int n) {
        data = new Item[n+1];
        capacity = n;
        for (int i = 0; i < n; ++i) {
            data[i+1] = arr[i];
        }
        count = n;

        for (int i = count/2; i >= 1; --i) {
            shiftDown(i);
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
        // assert(count + 1 <= capacity);
        if (count + 1 <= capacity) {
            data[count+1] = item;
            count++;

            shiftUp(count);

        } else {
            // realloc
        }
    }

    Item extractMax() {
        assert(count > 0);

        Item ret = data[1];
        std::swap(data[1], data[count]);
        --count;

        shiftDown(1);

        return ret;
    }

};


#endif //INC_02_HEAPIFY_MAXHEAP_H
