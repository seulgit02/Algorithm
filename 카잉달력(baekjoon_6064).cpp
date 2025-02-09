#include <iostream>
#include <vector>
using namespace std;

// �ִ����� ���ϱ�
int gcd(int a, int b) {
    int c = a % b;
    while (c != 0) {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}
//�ּҰ���� ���ϱ�
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}


int calculateDate(int M, int N, int X, int Y) {
    int lcmResult, result = -1;
    // 1) M, N�� �ּҰ���� ���ϱ�
    lcmResult = lcm(M, N);
    // 2) x, y�� ���° ������ ���ϱ�
    result = -1;
    for (int i = X; i <= lcmResult; i++) {
        if (i % M == X && i % N == Y) {
            result = i;
            break;
        }
    }
    for (int i = X; i <= lcmResult; i +=M) {
        if (i % N == Y % N) {
            result = i;
            break;
        }
    }
    return result;
}

int main(void) {
    int n, M, N, X, Y;
    vector<int> answerList;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> M >> N >> X >> Y;
        int result = calculateDate(M, N, X, Y);
        answerList.push_back(result);
    }
    for (int answer : answerList) {
        cout << answer << endl;
    }
    return 0;
}