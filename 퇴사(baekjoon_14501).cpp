#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    vector<pair<int, int>> table;
    int n, t, p;
    cin >> n;
    vector<int> dp(n+1, 0);

    // ��� ����ǥ �Է¹ޱ�
    for (int i = 0; i < n; i++) {
        cin >> t >> p; // �ҿ�ð�, ����
        table.push_back(make_pair(t, p));
    }

    for (int i = n - 1; i >=0; i--) {
        // ������ �ٹ� ���ڸ� �ʰ��ϴ� ���, X
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