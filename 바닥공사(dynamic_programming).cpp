#include <iostream>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    int* arr = new int{ N+1 };

    arr[1] = 1;
    arr[2] = 3;

    for (int i = 3; i < N + 1; i++) {
        arr[i] = arr[i - 1] + arr[i - 2] * 2;
    }
    int result = arr[N] % 796796;
    cout << result << endl;
    return 0;
}