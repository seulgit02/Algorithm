#include <iostream>
#include <vector>
#include <algorithm>
// DP�� Ǯ���, �ٵ� ��� �� ������ Ȧ���� ������ SK, ¦���� ������ CY�� �̱�.
using namespace std;
int main(void) {
    int rocks;
    int dp[1001];
    // dp �迭�� �̿��ؼ� Ǯ��, dp�� value�� ������ ����� Ƚ��.
    // ����̰� ���� ���� -> ���� Ƚ���� Ȧ���� SK, ¦���� CY ��.
    cin >> rocks;

    // Dynamic Programming
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= rocks; i++) {
        // ���� �ѹ��� 1 or 3�� �ݴ� �������ۿ� ����.
        dp[i] = min(dp[i-1]+1, dp[i-3]+1);
    }
    if (dp[rocks] % 2 != 0) cout << "SK" << endl;
    else cout << "CY" << endl;
    

    return 0;
}