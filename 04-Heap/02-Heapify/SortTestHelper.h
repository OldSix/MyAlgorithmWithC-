//
// Created by Queen on 2017/2/16.
//

#ifndef INC_02_HEAPIFY_SORTTESTHELPER_H
#define INC_02_HEAPIFY_SORTTESTHELPER_H

#include <algorithm>
#include <iostream>
#include <ctime>
#include <cassert>

namespace SortTestHelper {

    int * generateRandomArray (int n, int rangeL, int rangeR) {
        int * arr = new int[n];

        srand((unsigned int)time(NULL));
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % (rangeR-rangeL+1)+rangeL;
        }

        return arr;
    }

    int * generateRandomNearlyOrderedArray(int n, int swapTimes)
    {
        int * arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = i;
        }

        for (int j = 0; j < swapTimes; ++j) {
            int posx = rand() % n;
            int posy = rand() % n;

            std::swap(arr[posx], arr[posy]);
        }

        return arr;
    }

    int * copyIntArray(int *a, int n)
    {
        int * arr = new int[n];
        std::copy(a, a+n, arr);

        return arr;
    }

    template <typename T>
    bool isSorted(T arr[], int n)
    {
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i+1]) {
                return false;
            }
        }

        return true;
    }

    template <typename T>
    void testSort(const std::string sortName, void (*sort)(T [], int n), T arr[], int n)
    {
        clock_t start = clock();
        sort(arr, n);
        clock_t finish = clock();

        std::cout << sortName << ": " << double(finish-start) / CLOCKS_PER_SEC << " s" << std::endl;

        assert(isSorted(arr, n));
    }
}



#endif //INC_02_HEAPIFY_SORTTESTHELPER_H
