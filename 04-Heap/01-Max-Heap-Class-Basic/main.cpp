#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;

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

    void testPrint() {
        cout << "data in heap : ";
        for (int i = 1; i < this->size(); ++i) {
            cout << this->data[i] << " ";
        }
        cout << endl;
    }

};

int main(void)
{
    MaxHeap<int> maxheap = MaxHeap<int>(100);
    cout << maxheap.size() << endl;

    srand((unsigned int)time(NULL));
    for (int i = 0; i < 15; ++i) {
        maxheap.insertItem(rand()%100);
    }

    maxheap.testPrint();

    return 0;
}