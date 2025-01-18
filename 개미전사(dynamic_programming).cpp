#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
    int n;
    cin >> n;
    int *arr= new int[n];
    int* result = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    result[0] = arr[0];
    result[1] = arr[1];
    for (int i = 2; i < n; i++) {
        result[i] = max(arr[i] + result[i - 2], result[i - 1]);

    }
    cout << result[n-1] << endl;
    return 0;
}