#include <iostream>
using namespace std;

int main(void) {
    int arr[30001] = { 0, };
    int X;
    cin >> X;
    for (int i = 2; i < X+1; i++) {
        arr[i] = arr[i - 1] + 1;
        if (i % 5 == 0) {
            arr[i] = min(arr[i], arr[i/5]+1);
        }
        if (i % 3 == 0) {
            arr[i] = min(arr[i], arr[i/3] + 1);
        }
        if (i % 2 == 0) {
            arr[i] = min(arr[i], arr[i/2] + 1);
        }

    }
    cout << arr[X] << endl;
    return 0;
}