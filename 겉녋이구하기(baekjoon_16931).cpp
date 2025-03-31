#include <iostream>
#include <vector>
using namespace std;
int result = 0, leftt = 0, front = 0;
int main(void) {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> arr(N, vector<int>(M));
    // ���� ���� �Է� �ޱ�
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

    // ��, �Ʒ� �� �ʺ��� ��
    result += 2 *(N * M) +2*(leftt+front);


    cout << result;
    return 0;
}


// left, right: 1~N���� �� �� ��� ���� + (j��° ��� ����) - (j-1)��° ��� ����) -> ����� ����
// front, back: 1~M���� �� �� ��� ���� + (i��° ��� ����) - (i-1)��° ��� ����) -> ����� ����