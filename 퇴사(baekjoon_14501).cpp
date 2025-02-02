#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    vector<pair<int, int>> table;
    int n, t, p;
    cin >> n;
    vector<int> dp(n+1, 0);

    // 상담 일정표 입력받기
    for (int i = 0; i < n; i++) {
        cin >> t >> p; // 소요시간, 보상
        table.push_back(make_pair(t, p));
    }

    for (int i = n - 1; i >=0; i--) {
        // 마지막 근무 일자를 초과하는 경우, X
        if (table[i].first + i > n) {
            dp[i] = dp[i + 1];
        }
        else {
            dp[i] = max(dp[i+1], dp[i+table[i].first] + table[i].second);
        }
    }
    cout << dp[0] << endl;
    return 0;
}