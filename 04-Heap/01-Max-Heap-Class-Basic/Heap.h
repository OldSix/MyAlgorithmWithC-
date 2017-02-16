//
// Created by Queen on 2017/2/16.
//

#ifndef INC_01_MAX_HEAP_CLASS_BASIC_HEAP_H
#define INC_01_MAX_HEAP_CLASS_BASIC_HEAP_H

#include <iostream>
#include <algorithm>


template <typename Item>
class MaxHeap
{
private:
    Item *data;
    int count;
    int capacity;

    // 将索引 k 的位置向上移动，使堆恢复最大堆的性质
    void shiftUp(int k) {
        // 判断当前位置的值与其父节点的值的大小
        // k == 1 时，已经到达的堆的根节点，不需要再进行比较，直接退出就好
        while (k > 1 && data[k/2] < data[k]) {// 如果比父节点大，那么就交换
            swap(data[k/2], data[k]);
            k /= 2;
        }
    }

    void shiftDown(int k) {
        // 完全二叉树中，一个节点只要没有左孩子，那么也一定没有右孩子。
        // 所以只要判断左孩子是否存在就行了
        while (2*k <= count) {// 节点k有孩子，没有孩子的话，就不用比较了
            int i = 2*k;// 在此轮循环中，data[k] 与 data[i] 进行交换
            // 判断是否有右孩子， 且右孩子比左孩子大，那么交换的位置应该是右节点，也就是i+1
            if (i+1 <= count && data[i+1] > data[i]) {
                i += 1;
            }
            // 此时 data[i] 中存放的节点就是两个字节点中最大的那个节点

            // 如果父节点仍然比两个节点中大，那么不需要交换，循环终止即可
            if (data[k] >= data[i]) break;

            // 如果节点 k 的值还是小，那就交换
            swap(data[k], data[i]);

            // 更新 k 节点的最新下标
            k = i;
        }
    }

public:
    MaxHeap(int capacity) {
        data = new Item[capacity+1];
        count = 0;
        this->capacity = capacity;
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
        assert(count+1 <= capacity);
        data[count+1] = item;
        count++;
        shiftUp(count);
    }

    Item extractMax() {
        assert(count > 0);

        Item ret = data[1];
        swap(data[1], data[count]);
        count--;
        shiftDown(1);

        return ret;
    }

    void testPrint() {
        cout << "data in heap : " << this->size() << endl;
        for (int i = 1; i <= this->size(); ++i) {
            cout << this->data[i] << " ";
        }
        cout << endl;
    }
};

#endif //INC_01_MAX_HEAP_CLASS_BASIC_HEAP_H
