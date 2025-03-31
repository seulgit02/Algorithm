// 조합의 개수를 구하면 될것같은데?
// M개 중 N개의 사이트를 고르는 경우의 수.(순서 고려 X, 조합으로)
#include <iostream>
#include <vector>
using namespace std;
int N, M;
int cnt;
vector<int> results;
int combination[31][31];


int main(void) {
    cin >> cnt;
    combination[1][0] = 1;
    combination[1][1] = 1;

    for (int i = 0; i < cnt; i++) {
        cin >> N >> M;

        for (int i = 2; i <= M; i++) {
            combination[i][0] = 1;
            for (int j = 1; j <= N; j++) {
                // (특정 원소를 포함해 j개를 선택하는 경우) + (특정 원소 포함하지 않고 j개를 선택하는 경우)
                combination[i][j] = combination[i - 1][j - 1] + combination[i - 1][j];
            }
        }
        results.push_back(combination[M][N]);

    }
    
    for (int result : results) {
        cout << result << '\n';
    }

    return 0;
}