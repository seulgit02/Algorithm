#include <iostream>
#include <vector>
using namespace std;
int N, S, element, cnt = 0;
vector<int> elements;

void subset_sum(int index, int sum) {
    if (index >= N) return;
    sum += elements[index];
    // 부분집합의 sum이 목표값 S와 같아지면 카운팅
    if (sum == S) cnt += 1;

    // 현재 원소 포함해서 추가 탐색
    subset_sum(index + 1, sum);
    // 현재 원소 불포함해서 추가탐색
    subset_sum(index + 1, sum - elements[index]);
}

int main(void) {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> element;
        elements.push_back(element);
    }
    subset_sum(0, 0);
    cout << cnt << endl;
    return 0;
}