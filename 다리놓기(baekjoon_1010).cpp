// ������ ������ ���ϸ� �ɰͰ�����?
// M�� �� N���� ����Ʈ�� ���� ����� ��.(���� ��� X, ��������)
#include <iostream>
#include <vector>
using namespace std;
int N, M;
int cnt;
vector<int> results;
int combination[31][31];


int main(void) {
    combination[1][0] = 1;
    combination[1][1] = 1;

    for (int i = 0; i < cnt; i++) {
        cin >> N >> M;

        for (int i = 2; i <= M; i++) {
            combination[i][0] = 1;
            for (int j = 1; j <= N; j++) {
                combination[i][j] = combination[i - 1][j - 1] + combination[i - 1][j];
            }
        }

    }
    cout << combination[M][N];


    return 0;
}