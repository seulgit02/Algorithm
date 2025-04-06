#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int N, K, temp;
    cin >> N >> K;
    vector<int> belt(2*N+1,0);
    vector<int> robot(N+1,0);
    for (int i = 1; i <= 2*N; i++) {
        cin >> belt[i];
    }

    int step = 1;
    while (1) {
        // 1. 각 칸 위에 있는 로봇과 함께 벨트를 한칸씩 회전
        temp = belt[2*N];
        for (int i = 2*N-1; i >= 1; i--) belt[i+1] = belt[i];
        belt[1] = temp;
        // 로봇 회전
        for (int i = N - 1; i >= 1; i--) robot[i + 1] = robot[i];
        robot[1] = false;  // 1번 자리 초기화
        robot[N] = false;  // 내려가는 위치 처리

        // 2. 로봇 이동
        // 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아있어야 함.
        for (int i = N-1; i >= 1; i--) {
            if (!robot[i + 1] && belt[i + 1] >0 && robot[i]) {
                robot[i] = false;
                robot[i + 1] = true;
                --belt[i + 1];
            }
        }
        // 로봇이 N번째 위치 도착시에는 즉시 그 턴에서 내려야 함.
        robot[N] = false;

        // 3. 로봇 올리기
        if (belt[1] > 0 && robot[1]==false) {
            robot[1] = true;
            --belt[1];
        }


        // 종료 조건
        int count = 0;
        for (int i = 1; i <= 2 * N; i++) {
            if (belt[i] == 0) count++;
        }
        if (count >= K) break;
        ++step;
    }
    cout << step << endl;
    return 0;
}