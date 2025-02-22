#include <iostream>
#include <algorithm>
#define INF 10000
using namespace std;
int result, N;
int visited[20] = { 0, };
int S[20][20];
/*
* start���� link�� �ɷ�ġ ������ �ּҰ� ���ϱ�
 start ��) visited[x] == 1�� ����
 link ��) visited[x] == 0�� ����
*/
void team(int a, int n) {
    cout << "team(" << a << ", " << n << ")\n";
    // �� �����ο��� �� �� ��� ���� �ɷ�ġ ���
    if (a == N / 2) {
        int start = 0, link = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i] && visited[j]) {
                    start += S[i][j];
                }
                else if (!visited[i] && !visited[j]) {
                    link += S[i][j];
                }
            }
        }
        result = min(result, abs(start - link));
        return;
    }
    // �� �����ο� �߰� �Ҵ�
    else {
        for (int i = n; i < N; i++) {
            if (!visited[i]) {
                visited[i] = 1;
                team(a + 1, i + 1);
                cout << "���� [" << i << "] �ݳ�\n";
                visited[i] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
        }

    }
    result = INF;
    team(0, 0);
    cout << result;
    return 0;
}