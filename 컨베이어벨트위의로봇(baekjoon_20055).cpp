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
        // 1. �� ĭ ���� �ִ� �κ��� �Բ� ��Ʈ�� ��ĭ�� ȸ��
        temp = belt[2*N];
        for (int i = 2*N-1; i >= 1; i--) belt[i+1] = belt[i];
        belt[1] = temp;
        // �κ� ȸ��
        for (int i = N - 1; i >= 1; i--) robot[i + 1] = robot[i];
        robot[1] = false;  // 1�� �ڸ� �ʱ�ȭ
        robot[N] = false;  // �������� ��ġ ó��

        // 2. �κ� �̵�
        // �̵��Ϸ��� ĭ�� �κ��� ������, �� ĭ�� �������� 1 �̻� �����־�� ��.
        for (int i = N-1; i >= 1; i--) {
            if (!robot[i + 1] && belt[i + 1] >0 && robot[i]) {
                robot[i] = false;
                robot[i + 1] = true;
                --belt[i + 1];
            }
        }
        // �κ��� N��° ��ġ �����ÿ��� ��� �� �Ͽ��� ������ ��.
        robot[N] = false;

        // 3. �κ� �ø���
        if (belt[1] > 0 && robot[1]==false) {
            robot[1] = true;
            --belt[1];
        }


        // ���� ����
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