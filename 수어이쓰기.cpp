#include <iostream>
#include <cmath>
using namespace std;
int main(void) {
    int N, result = 0;
    cin >> N;

    // N�� �ڸ��� ���ϱ�
    int copyN = N;
    int count = 0;
    while (copyN >= 1) {
        count++;
        copyN = copyN/10;
    }

    if (N < 10) {
        result = N;
    }else {
        result = 11;// 11�ڸ����� ����(13)

        // 1������� �ִ� �����̹Ƿ�, i(�ڸ���)�� 10���� ���������� ��ȸ
        for (int i = 2; i < 10; i++) {
            if (count == i) {
                result += i*(N-(pow(10, i-1)));
                break;
            }
            // �ش� �ڸ����� �ش��ϴ� �ִ�
            else {
                result += i * (9 * pow(10, i - 1))+1;
            }
            
        }

    }
    //if 2)10~99 -> (99-10+1)*2
    //if 3) 100~999 ->(999-100+1)*3
    cout << result << endl;
    return 0;
};