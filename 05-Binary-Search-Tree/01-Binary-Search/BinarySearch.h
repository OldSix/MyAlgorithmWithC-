//
// Created by Queen on 2017/2/19.
//

#ifndef INC_01_BINARY_SEARCH_BINARYSEARCH_H
#define INC_01_BINARY_SEARCH_BINARYSEARCH_H

template <typename T>
int binary_search(T arr[], int n, T target)
{
    // arr[l...] 区间内进行搜索
    int l = 0;
    int r = n-1;
    int mid;

    while (l <= r) {
        mid = l + (r-l)/2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            r = mid - 1;
        else // arr[mid] > target
            l = mid + 1;
    }

    return -1;
}


template <typename T>
int __binary_search(T arr[], int l, int r,T target)
{
    if (l > r)
        return -1;
    int mid = l + (r-l)/2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target)
        return __binary_search(arr, l, mid-1, target);
    else
        return __binary_search(arr, mid+1, r, target);
}

template <typename T>
int binary_search_recursive(T arr[], int n, T target)
{
    return __binary_search(arr, 0, n-1, target);
}


#endif //INC_01_BINARY_SEARCH_BINARYSEARCH_H
