#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 연산을 사용하는 횟수의 최솟값.
//1: 1
//2: 1
//3: 1
//4: 2 -> 1 = 2
//5: 4 -> 2 -> 1 = 3
//6: 2 -> 1 = 2
int main(void) {
    int N;
    cin >> N;
    vector<int> arr(N+1);
    arr[1] = 0;
    for (int i = 2; i <= N; i++) {
        arr[i] = arr[i-1] + 1;
        if (i % 3 == 0) {
            arr[i] = min(arr[i / 3] + 1, arr[i]);
        }
        if (i % 2 == 0) {
            arr[i] = min(arr[i / 2] + 1, arr[i]);
        }
        
    }
    cout << arr[N] << endl;
    return 0;
}