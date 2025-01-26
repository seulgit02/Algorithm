#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
            else {
                break;
            }
        }

    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main(void) {
    cout << "[Selection Sort]" << endl;
    int arr[10] = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };
    insertion_sort(arr, 10);
    return 0;
}