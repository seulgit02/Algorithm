#include <iostream>
#include <vector>
using namespace std;

int N, maxCandy = 1;
vector<string> arr;

int checkMaxCandy() {

    // 가로방향 check
    for (int i = 0; i < N; i++) {
        int count = 1;
        for (int j = 1; j < N; j++) {
            if (arr[i][j] == arr[j][j - 1]) {
                count++;
            }
            else {
                count = 1;
            }
            maxCandy = max(maxCandy, count);
        }
    }

    // 세로방향 check
    for (int i = 0; i < N; i++) {
        int count = 1;
        for (int j = 1; j < N; j++) {
            if (arr[j][i] == arr[j - 1][i]) {
                count++;
            }
            else {
                count = 1;
            }
        }
        maxCandy = max(maxCandy, count);
    }
    return maxCandy;
}

int main(void) {
    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 인접한 두 사탕 교환 후, 최대 개수 계산
    for (int i = 0; i < N; i++) {
        // 가로 교환
        for (int j = 0; j < N; j++) {
            if (j + 1 < N && arr[i][j] != arr[i][j + 1]) {
                swap(arr[i][j], arr[i][j + 1]);
                maxCandy = checkMaxCandy();
                // 원상복구 필요
                swap(arr[i][j], arr[i][j + 1]);
            }
        }
        // 세로 교환
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i + 1 < N && arr[i][j] != arr[i + 1][j]) {
                    swap(arr[i][j], arr[i + 1][j]);
                    maxCandy = checkMaxCandy();
                    swap(arr[i][j], arr[i + 1][j]);

                }
            }
        }
    }



    

    cout << maxCandy << endl;
    return 0;
}