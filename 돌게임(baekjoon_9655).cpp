#include <iostream>
#include <vector>
#include <algorithm>
// DP로 풀어보기, 근데 사실 돌 개수가 홀수면 무조건 SK, 짝수면 무조건 CY가 이김.
using namespace std;
int main(void) {
    int rocks;
    int dp[1001];
    // dp 배열을 이용해서 풀되, dp의 value는 게임이 진행된 횟수.
    // 상근이가 먼저 시작 -> 누적 횟수가 홀수면 SK, 짝수면 CY 승.
    cin >> rocks;

    // Dynamic Programming
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= rocks; i++) {
        // 돌은 한번에 1 or 3개 줍는 선택지밖에 없음.
        dp[i] = min(dp[i-1]+1, dp[i-3]+1);
    }
    if (dp[rocks] % 2 != 0) cout << "SK" << endl;
    else cout << "CY" << endl;
    

    return 0;
}