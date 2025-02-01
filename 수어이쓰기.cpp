#include <iostream>
#include <cmath>
using namespace std;
int main(void) {
    int N, result = 0;
    cin >> N;

    // N의 자릿수 구하기
    int copyN = N;
    int count = 0;
    while (copyN >= 1) {
        count++;
        copyN = copyN/10;
    }

    if (N < 10) {
        result = N;
    }else {
        result = 11;// 11자리부터 시작(13)

        // 1억까지가 최대 범위이므로, i(자릿수)가 10보다 작을때까지 순회
        for (int i = 2; i < 10; i++) {
            if (count == i) {
                result += i*(N-(pow(10, i-1)));
                break;
            }
            // 해당 자릿수에 해당하는 최댓값
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