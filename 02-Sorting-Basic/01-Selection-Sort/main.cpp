#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
void selectionSort(T arr[], int n)
{
    for (int i = 0; i < n; ++i) {
        int minIndex = i;
        for (int j = i+1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        swap(arr[minIndex], arr[i]);
    }
}

int main(void)
{
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    selectionSort(a, 10);

    for (int i = 0; i < 10; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}