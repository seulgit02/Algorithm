#include <iostream>
#include <vector>
using namespace std;
int result = 0, leftt = 0, front = 0;
int main(void) {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> arr(N, vector<int>(M));
    // 문제 조건 입력 받기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    // left, right
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j == 0) leftt += arr[i][j];
            else {
                if (arr[i][j] - arr[i][j - 1] > 0) leftt +=( arr[i][j] - arr[i][j - 1]);
            }
        }
    }

    // front, back
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            if (i == 0) front += arr[i][j];
            else {
                if (arr[i][j] - arr[i - 1][j] > 0) front += arr[i][j] - arr[i - 1][j];
            }
        }
    }

    // 위, 아래 면 너비의 합
    result += 2 *(N * M) +2*(leftt+front);


    cout << result;
    return 0;
}


// left, right: 1~N에서 맨 앞 블록 높이 + (j번째 블록 높이) - (j-1)번째 블록 높이) -> 양수일 때만
// front, back: 1~M에서 맨 앞 블록 높이 + (i번째 블록 높이) - (i-1)번째 블록 높이) -> 양수일 때만