#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n, num, element, movecnt;

    // �迭 ����
    cin >> n;
    vector<vector<int>> line(n+1);

    // �迭 �Է�
    for (int i = 0; i < n; i++) {
        cin >> num;
        for (int j = 0; j < 20; j++) {
            cin >> element;
            line[i].push_back(element);
        }
    }

    // �� �迭���� �̵��� ���� �� ���
    // (n-x+1)��ŭ ���� �� �̵�
    for (int i = 0; i < n; i++) {
        movecnt = 0;
        // cout << "[���ο� �迭 ī��Ʈ ����]" << endl;
        for (int j = 1; j < 20;j++) {
            int target = line[i][j];
            int k = j - 1;
            /*target ������ ��ġ ã��*/
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