// �ð����⵵ O(n*n) ����
#include <iostream>
using namespace std;

int number = 6;
int INF = 999999999;

// ��ü �׷��� �ʱ�ȭ
int a[6][6] = {
    {
        0, 2, INF, 1, INF, INF
    },{
        2, 0, 3, 2, INF, INF
    }, {
        INF, 3, 0, INF, INF, INF
    }, {
        1, 2, INF, 0, 1, INF
    }, {
        INF, INF,INF, 1, 0, 2
    }, {
        INF, INF, 5, INF, 2, 0
    }
};
bool v[6] = { false, };  // �湮�� ���
int d[6];   // �ִ� �Ÿ�

// ���� �ּ� �Ÿ��� ������ ������ ��ȯ
int getSmallIndex() {
    int min = INF;
    int index = 0;
    for (int i = 0; i < number; i++) {
        // �湮���� ���� ��� �߿���, ���� �ִܰŸ����� �� ���� ���� ������ ��尡 �����Ѵٸ�
        if (d[i] < min && !v[i]) {
            min = d[i];
            index = i; // �׶��� ��ġ�� ���
        }
    }
    return index;
}

// ���ͽ�Ʈ�� �����ϴ� �Լ�
void dijkstra(int start) {
    for (int i = 0; i < number; i++) {
        d[i] = a[start][i];
    }
    v[start] = true; // ���۳�� �湮ó��
    for (int i = 0; i < number - 2; i++) { // �ڱ� �ڽ� ������ ��� ��ȸ
        int current = getSmallIndex();
        v[current] = true; // ��� �湮 ó��
        for (int j = 0; j < 6; j++) {
            if (!v[j]) {
                if (d[current] + a[current][j] < d[j]) {
                    d[j] = d[current] + a[current][j];
                }
            }
        }
    }
}

int main(void) {

    dijkstra(0);
    for (int i = 0; i < number; i++) {
        printf("%d\t", d[i]);
    }
    return 0;
}
