#include <iostream>
#include <vector>
using namespace std;

// 최대공약수 구하기
int gcd(int a, int b) {
    int c = a % b;
    while (c != 0) {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}
//최소공배수 구하기
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}


int calculateDate(int M, int N, int X, int Y) {
    int lcmResult, result = -1;
    // 1) M, N의 최소공배수 구하기
    lcmResult = lcm(M, N);
    // 2) x, y가 몇번째 해인지 구하기
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