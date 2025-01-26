#include <iostream>
#include <vector>
using namespace std;

void selection_sort(int* arr, int n) {
    for (int i = 0; i < n-1; i++) {
        int min = arr[i];
        int index = i;
        for (int j = index + 1; j < n; j++) {
            if (arr[j] < min) {
                min = arr[j];
                index = j;
            }
        }
        int temp = arr[i];
        arr[i] = min;
        arr[index] = temp;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main(void) {
    int arr[10] = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };
    selection_sort(arr, 10);

    return 0;
}