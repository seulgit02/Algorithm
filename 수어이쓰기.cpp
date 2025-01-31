#include <iostream>
#include <sstream>
using namespace std;
int main(void) {
    int N, result = 0;
    cin >> N;
    for (int i = 1; i <= N; i *= 10) {
        result += N - i + 1;
        cout << result << endl;
    }
    cout << result << endl;
    // 120 -> 1, 100 ....
    // result = 0
    // result += (120 - 1 + 1) => 0 + 120
    // result += (120 - 10 + 1) => 120 + 111 = 231
    // result += (120 - 100 + 1) => 20 + 1 = 221 + 21 = 252

    // 1200 -> 1, 100, 1000 ....
    //result = 0
    // result += (1200 - 1 + 1) => 1200
    // result += (1200 - 100 + 1) => 1200 + 1101 => 2301
    // result += (1200 - 1000 + 1) => 2301 + 201 => 2502
    return 0;
};