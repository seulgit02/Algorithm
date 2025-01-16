#include <iostream>
#include <ctime>
using namespace std;

// Dynamic Programming으로 구현
int fibonacci(int n, long long* result) {
    if (n == 1 or n == 2) {
        return 1;
    }
    else if (result[n] != 0) {
        return result[n];
    }
    else {
        result[n] = fibonacci(n - 1, result) + fibonacci(n - 2, result);
        return fibonacci(n - 1, result) + fibonacci(n - 2, result);
        
    }
    
}

int main(void) {
    // 시간 측정용
    clock_t start, finish;
    double duration;

    int n;
    cin >> n;
    long long* result = new long long[n+1]{0, };
    start = clock();
    int answer = fibonacci(n, result);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;

    cout << "f(" << n << ") = " << answer << endl;
    cout << "소요시간(sec): " << duration << endl;
    return 0;
}