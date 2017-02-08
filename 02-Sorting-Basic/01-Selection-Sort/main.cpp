#include <iostream>

template <typename T>
void selectionSort(T arr[], int n)
{
    for (int i = 0; i < n; ++i) {
        int minIndex = i;
        for (int j = i+1; j < n; ++j) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        std::swap(arr[i], arr[minIndex]);
    }
}

int main(void)
{
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    selectionSort(a, 10);

    for (int i = 0; i < 10; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}