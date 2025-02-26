#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(void) {
    vector<int> arr;
    int N, element, sum, result = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> element;
        arr.push_back(element);
    }

    // 원소를 오름차순 정렬
    sort(arr.begin(), arr.end());

    // 완전 탐색
    while (next_permutation(arr.begin(), arr.end())) {
        sum = 0;
        for (int i = 0; i < arr.size() - 1; i++) {
            sum += abs(arr[i] - arr[i + 1]);
        }
        result = max(result, sum);
    }
    cout << result;
    return 0;
}

// next_permutation basic
/*
int main(void) {
    vector<int> v{ 1,2,3 };
    sort(v.begin(), v.end());
    do {
        for (auto it = v.begin(); it != v.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;

    } while (next_permutation(v.begin(), v.end()));
    return 0;
}
*/