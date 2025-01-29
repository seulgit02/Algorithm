#include <iostream>
#include <vector>
using namespace std;

int N, maxCandy = 1;
vector<string> arr;

void checkMaxCandy() {

    // ���ι��� check
    for (int i = 0; i < N; i++) {
        int count = 1;
        for (int j = 1; j < N; j++) {
            if (arr[i][j] == arr[i][j - 1]) {
                count++;
            }
            else {
                count = 1;
            }
            maxCandy = max(maxCandy, count);
        }
    }

    // ���ι��� check
    for (int i = 0; i < N; i++) {
        int count = 1;
        for (int j = 1; j < N; j++) {
            if (arr[j][i] == arr[j - 1][i]) {
                count++;
            }
            else {
                count = 1;
            }
            maxCandy = max(maxCandy, count);
        }
    }
}

int main(void) {
    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // ������ �� ���� ��ȯ ��, �ִ� ���� ���
    for (int i = 0; i < N; i++) {
        // ���� ��ȯ
        for (int j = 0; j < N; j++) {
            if (j + 1 < N && arr[i][j] != arr[i][j + 1]) {
                swap(arr[i][j], arr[i][j + 1]);
                checkMaxCandy();
                // ���󺹱� �ʿ�
                swap(arr[i][j], arr[i][j + 1]);
            }
            if (i + 1 < N && arr[i][j] != arr[i + 1][j]) {
                swap(arr[i][j], arr[i + 1][j]);
                checkMaxCandy();
                swap(arr[i][j], arr[i + 1][j]);

            }
        }   
    }

    for (int i = 0; i < N; i++) {
        // ���� ��ȯ
        for (int j = 0; j < N; j++) {
            if (i + 1 < N && arr[i][j] != arr[i + 1][j]) {
                swap(arr[i][j], arr[i + 1][j]);
                checkMaxCandy();
                swap(arr[i][j], arr[i + 1][j]);

            }
        }
    }
    cout << maxCandy << endl;
    return 0;
}