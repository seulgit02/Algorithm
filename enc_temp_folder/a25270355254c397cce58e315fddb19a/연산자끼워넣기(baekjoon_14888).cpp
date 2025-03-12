#include <iostream>

using namespace std;

int N;
int* operands = new int[N];
int operators[4];
int min_value = 1000000001;
int max_value = -1000000001;

void getAnswer(int result, int index) {
    if (index == N) {
        // N��° operands���� ������ �Ϸ�� ���
        if (result > max_value) max_value = result;
        if (result < min_value) min_value = result;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (operators[i] > 0) { // �ش� �����ڰ� ��� �Һ���� ���� ���
            operators[i]--; // ������ 
            if (i == 0) getAnswer(result + operands[index], index + 1);
            else if (i == 1) getAnswer(result - operands[index], index + 1);
            else if (i == 2) getAnswer(result * operands[index], index + 1);
            else getAnswer(result / operands[index], index + 1);
        }
    }
    return;
}

int main(void) {
    cin >> N; //���� ���� N(2<=N<=11)
    for (int i = 0; i < N; i++) cin >> operands[i]; // �ǿ����� �Է�
    for (int i = 0; i < 4; i++) cin >> operators[i]; // ������ ���� �Է�(������� +, -, *, /�� ����)
    getAnswer(operands[0], 1); 
    cout << max_value << '\n';
    cout << min_value << "\n";

    return 0;
}