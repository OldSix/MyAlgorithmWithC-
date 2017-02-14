#include <iostream>
#include "TestHelper.h"

long long __merge(int arr[], int l, int mid, int r)
{
    int * aux = new int[r-l+1];
    for (int i = l; i <= r; ++i) {
        aux[i-l] = arr[i];
    }

    long long res = 0;
    int i = l;// i 代表 arr[l...mid] 中的第一个元素
    int j = mid+1;// j 代表 arr[mid+1...r] 中的第一个元素

    for (int k = l; k <= r; ++k) {
        if (i > mid) {
            arr[k] = aux[j-l];
            j++;
        } else if (j > r) {
            arr[k] = aux[i-l];
            i++;
        } else if (aux[i-l] < aux[j-l]) {
            arr[k] = aux[i-l];
            i++;
        } else {
            arr[k] = aux[j-l];
            j++;
            /* [2 3 5 8  1 4 5 7]*/
            res += (mid-i+1);
        }
    }

    delete[] aux;

    return res;
}

long long __inversionCount(int arr[], int l, int r)
{
    if (l >= r) {
        return 0;
    }

    int mid = (l+r)/2;
    long long res1 = __inversionCount(arr, l, mid);
    long long res2 = __inversionCount(arr, mid+1, r);

    return res1+res2+__merge(arr, l, mid, r);
}

// 逆序对
long long inversionCount(int arr[], int n)
{
    return __inversionCount(arr, 0, n-1);
}

int main()
{
    int n = 1000000;

    int * arr = TestHelper::generateRandomArray(n, 0, n);
    std::cout << inversionCount(arr, n) << std::endl;
    delete[] arr;

    arr = TestHelper::generateOrderedArray(n);
    std::cout << inversionCount(arr, n) << std::endl;
    delete[] arr;

    arr = TestHelper::generateInversedArray(n);
    std::cout << inversionCount(arr, n) << std::endl;
    delete[] arr;


    return 0;
}