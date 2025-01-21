#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    int N, M;
    cin >> N>>M;

    vector<int> currency(N);
    vector<int> dp(M+1, 10001);
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        cin >> currency[i];
    }

    for (int c: currency) {
        for (int i = c; i < M+1; i++) {
            if (dp[i-c] != 10001) {
                dp[i] = min(dp[i - c]+1, dp[i]);
            }
        }
    }
    if (dp[M] == 10001) {
        cout << -1 << endl;
    }
    else {
        cout << dp[M] << endl;
    }
    
    return 0;
}
