//
// Created by Queen on 2017/2/18.
//

#ifndef INC_04_INDEXMAXHEAP_MAXHEAP_H
#define INC_04_INDEXMAXHEAP_MAXHEAP_H

template <typename Item>
class MaxHeap
{
private:
    Item * data;
    int capacity;
    int count;

    void shiftUp(int k) {
        while (k > 1 && data[k/2] < data[k]) {
            std::swap(data[k/2], data[k]);
            k /= 2;
        }
    }

    void shiftDown(int k) {
        while (2*k <= count) {
            int i = 2*k;
            if (i+1 <= count && data[i+1] > data[i])
                i += 1;
            if (data[k] >= data[i])
                break;
            std::swap(data[k], data[i]);
            k = i;
        }
    }

public:
    MaxHeap(int capacity): capacity(capacity), count(0) {
        data = new Item[capacity+1];
    }

    MaxHeap(Item arr[], int n): capacity(n), count(n) {
        data = new Item[n+1];
        for (int i = 0; i < n; ++i) {
            data[i+1] = arr[i];
        }

        for (int j = n/2; j >= 1; --j) {
            shiftDown(j);
        }
    }

    ~MaxHeap() {
        delete[] data;
    }

    void insertItem(Item item) {
        if (count == capacity) {
            Item *tmp = new Item[2*capacity];
            std::copy(data, data+capacity, tmp);
            delete[] data;
            this->capacity = 2*capacity;
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


#endif //INC_04_INDEXMAXHEAP_MAXHEAP_H
