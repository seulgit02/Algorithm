#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector <bool>broken;
int channel, clickCount, brokenCnt, brokenNum;

void dfs(int idx, int click) {
    for (int i = 0; i < 10; i++) {
        if (!broken[i]) {
            int newBtn = click * 10 + i;
            string strNewBtn = to_string(newBtn);
            int cnt = abs(channel - newBtn) + strNewBtn.length();
            clickCount = min(clickCount, cnt);

            if (idx < 6) {
                dfs(idx + 1, newBtn);
            }
        }
    }
}

int main(void) {
    cin >> channel; 
    cin >> brokenCnt;
    broken.resize(brokenCnt+1, false);
    for (int i = 0; i < brokenCnt; i++) {
        cin >> brokenNum;
        broken[brokenNum + 1] = true;

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

