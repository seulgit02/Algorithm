#include <iostream>
#include <vector>
using namespace std;
// 집합 s와 k가 주어졌을 때, 수를 고르는 모든 방법을 구하는 프로그램
int s, k;
int set[49];
vector<int> subset;
void backTracking(int index, int order) {
    // 6개 모두 선택 완료했으면, 배열 출력
    if (order == 6) {
        for (int i = 0; i < order; i++) {
            // 지금까지 저장된 배열 출력
            cout << subset[i] << ' ';    
        };  
        cout << endl;
        return;
    }

    for (int i = index; i < s; i++) {
        subset.push_back(set[i]);
        backTracking(i + 1, order + 1);
        subset.pop_back(); // backtracking 수행 후 원소 제거
    }

}

int main(void) {
    while (true) {
        cin >> s;
        if (s == 0) break;
        for (int i = 0; i < s; i++) {
            cin >> set[i];
        }
        backTracking(0, 0);
        cout << endl;
    }

    return 0;
}