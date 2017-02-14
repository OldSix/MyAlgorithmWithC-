#include <iostream>
#include <ctime>
#include <cassert>
#include <algorithm>
#include "TestHelper.h"

int partition(int nums[], int l, int r)
{
    int p = rand() % (r-l+1)+l;
    std::swap(nums[l], nums[p]);

    int j = l;// arr[l+1...j] < p ; arr[j+1...r] > p
    for (int i = l+1; i <= r; ++i) {
        if (nums[i] < nums[l]) {
            std::swap(nums[i], nums[++j]);
        }
    }

    std::swap(nums[l], nums[j]);

    return j;
}

int __selection(int nums[], int l, int r, int k)
{
    if (l==r) {
        return nums[l];
    }

    int p = partition(nums, l, r);

    if (p==k) {
        return nums[p];
    } else if (k < p) {
        return __selection(nums, l, p-1, k);
    } else {
        return __selection(nums, p+1, r, k);
    }
}

int selection(int nums[], int n, int k)
{
    srand((unsigned int)time(NULL));
    return __selection(nums, 0, n-1, k);
}

int main()
{
    int n = 100000;

    int * arr = TestHelper::generateOrderArray(n);
    TestHelper::shuffleArray(arr, n);

    for (int i = 0; i < n; ++i) {
        assert(selection(arr, n, i) == i);
        std::cout << "test " << i << " complete." << std::endl;
    }
    std::cout << "Test selection completed." << std::endl;

    delete[] arr;
    return 0;
}