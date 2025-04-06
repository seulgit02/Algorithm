#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int N, K, temp;
    cin >> N >> K;
    vector<int> belt(2*N+1);
    vector<int> robot(N+1);
    for (int i = 1; i <= 2*N; i++) {
        cin >> belt[i];
    }

    int step = 1;
    while (1) {
        // 1. �� ĭ ���� �ִ� �κ��� �Բ� ��Ʈ�� ��ĭ�� ȸ��
        temp = belt[2*N];
        for (int i = 2*N-1; i >= 1; i++) belt[i+1] = belt[i];
        belt[1] = temp;
        if (robot[N] == true) robot[N] = false;
        /*
        for (int i = N-1; i >= 1; i--) {
            if (robot[i] == true) {
                robot[i] = false;
                robot[i + 1] = true;
            }    
        }
        */
        // 2. �κ� ȸ��
        // �̵��Ϸ��� ĭ�� �κ��� ������, �� ĭ�� �������� 1 �̻� �����־�� ��.
        for (int i = N; i >= 1; i--) {
            if ((i+1) > N) robot[i] = false;
            else {
                if (robot[i + 1] == false && belt[i + 1] >= 1) {
                    robot[i] = false;
                    robot[i + 1] = true;
                    --belt[i + 1];
                }
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