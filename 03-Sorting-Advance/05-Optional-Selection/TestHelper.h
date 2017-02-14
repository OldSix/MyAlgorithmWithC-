//
// Created by Queen on 2017/2/14.
//

#ifndef INC_05_OPTIONAL_SELECTION_TESTHELPER_H
#define INC_05_OPTIONAL_SELECTION_TESTHELPER_H

#include <iostream>

namespace TestHelper {
    int * generateOrderArray(int n)
    {
        int * arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = i;
        }

        return arr;
    }

    void shuffleArray(int arr[], int n)
    {
        srand((unsigned int)time(NULL));

        for (int i = 0; i < n; ++i) {
            int j = rand() % (n-)+i;
            std::swap(arr[i], arr[j]);
        }
    }

}


#endif //INC_05_OPTIONAL_SELECTION_TESTHELPER_H
