#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n, num, element, movecnt;

    // 배열 개수
    cin >> n;
    vector<vector<int>> line(n+1);

    // 배열 입력
    for (int i = 0; i < n; i++) {
        cin >> num;
        for (int j = 0; j < 20; j++) {
            cin >> element;
            line[i].push_back(element);
        }
    }

    // 각 배열마다 이동한 걸음 수 출력
    // (n-x+1)만큼 걸음 수 이동
    for (int i = 0; i < n; i++) {
        movecnt = 0;
        // cout << "[새로운 배열 카운트 시작]" << endl;
        for (int j = 1; j < 20;j++) {
            int target = line[i][j];
            int k = j - 1;
            /*target 삽입할 위치 찾기*/
            while (k >= 0 && line[i][k] > target) {
                line[i][k + 1] = line[i][k];
                movecnt++;
                k--;
            }
            line[i][k + 1] = target;
        }
        cout << i+1 <<' ' << movecnt << endl;
    }


    return 0;
}