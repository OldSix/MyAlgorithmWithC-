//
// Created by Queen on 2017/2/14.
//

#ifndef INC_04_OPTIONAL_3_SELECTION_TESTHELPER_H
#define INC_04_OPTIONAL_3_SELECTION_TESTHELPER_H

#include <cassert>
#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>

namespace TestHelper {

    int * generateRandomArray(int n, int rangeL, int rangeR)
    {
        int * arr = new int[n];

        srand((unsigned int)time(NULL));
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % (rangeR-rangeL+1)+rangeL;
        }

        return arr;
    }

    int * generateNearlyOrderedArray(int n, int swapTimes)
    {
        int * arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = i;
        }

        srand((unsigned int)time(NULL));
        for (int j = 0; j < swapTimes; ++j) {
            int posx = rand() % n;
            int posy = rand() % n;

            std::swap(arr[posx], arr[posy]);
        }

        return arr;
    }

    int * generateOrderedArray(int n)
    {
        return generateNearlyOrderedArray(n, 0);
    }

    int * generateInversedArray(int n)
    {
        int * arr = generateOrderedArray(n);
        for (int i = n/2-1; i >= 0; --i) {
            std::swap(arr[i], arr[n-1-i]);
        }

        return arr;
    }

}


#endif //INC_04_OPTIONAL_3_SELECTION_TESTHELPER_H
