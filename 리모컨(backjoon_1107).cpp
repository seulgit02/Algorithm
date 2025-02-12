#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector <bool>broken;
int channel, clickCount, brokenCnt, brokenNum;

/*탐색*/
void dfs(int idx, int click) {
    // 버튼 순차적으로 탐색
    for (int i = 0; i < 10; i++) {
        if (!broken[i]) {
            int newBtn = click * 10 + i; //숫자입력으로 자릿수 추가
            string strNewBtn = to_string(newBtn); 
            int cnt = abs(channel - newBtn) + strNewBtn.length(); // 숫자 자릿수 카운트
            clickCount = min(clickCount, cnt);
            // 최대 6자리 숫자까지 탐색(채널 범위: 0~500,000)
            if (idx < 6) {
                dfs(idx + 1, newBtn);
            }
        }
    }
}

int main(void) {
    cin >> channel; // 타겟 채널
    cin >> brokenCnt; // 고장난 버튼 개수
    broken.resize(brokenCnt+1, false);
    for (int i = 0; i < brokenCnt; i++) {
        cin >> brokenNum;
        broken[brokenNum] = true;

    }
    // 1) channel == 100인 경우
    if (channel == 100) {
        cout << 0 << endl;
        return 0;
    };
    // 2) +, -로만 채널을 이동하는 경우
    clickCount = abs(channel - 100);
    // 3) 버튼 선택 & 방향키(+,-) 모두 사용하는 경우
    dfs(0, 0);
    cout << clickCount << endl;
    return 0;
}

