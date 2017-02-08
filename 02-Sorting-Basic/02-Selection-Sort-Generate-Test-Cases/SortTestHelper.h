//
// Created by Queen on 2017/2/8.
//

#ifndef INC_02_SELECTION_SORT_GENERATE_TEST_CASES_SORTTESTHELPER_H
#define INC_02_SELECTION_SORT_GENERATE_TEST_CASES_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>

namespace SortTestHelper {

    // 生成有n个元素的随机数组，每个元素的随机范围为[rangrL, rangeR]
    int *generateRandomArray(int n, int rangeL, int rangeR) {

        assert(rangeL <= rangeR);

        int *arr = new int[n];

        srand((unsigned int)time(NULL));
        for (int i = 0; i < n; ++i) {
            // rand() % 10 ==> [0,9]
            // 如果要求生成范围是 [1, 10]
            // rand() % 10 + 1 ==> [1, 10]
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }

        return arr;
    }

    template <typename T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    template <typename T>
    bool isSorted(T arr[], int n) {
        for (int i = 0; i < n-1; ++i) {
            if (arr[i] > arr[i+1])
                return false;
        }
        return true;
    }

    template <typename T>
    void testSort(const std::string &sortName, void (*sort)(T [], int), T arr[], int n) {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t  endTime = clock();

        assert(isSorted(arr, n));
        std::cout << sortName << ":" << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << std::endl;
    }
}


#endif //INC_02_SELECTION_SORT_GENERATE_TEST_CASES_SORTTESTHELPER_H
