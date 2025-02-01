#include <iostream>
#include <vector>
using namespace std;

int getAnswer(int num, int *d) {
    if (d[num] != 0) return d[num];
    else return (getAnswer(num-1, d)+getAnswer(num-2, d)+getAnswer(num-3, d));
}

int main(void) {
    int N;
    int d[11] = { 0, };
    vector<int> inputs;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    cin >> N;
    inputs.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> inputs[i];
    }
    for (int input : inputs) {
        int result = getAnswer(input, d);
        cout << result << endl;
    }
    return 0;
}

/*
1   -> (1)

1+1, 2  -> (2)

1+1+1, 1+2, 3   -> (4)

1+1+1+1, 1+1+2, 2+2, 1+3    -(7)

1+1+1+1+1, 1+1+1+2, 1+2+2, 1+1+3, 2+3  - (13)

1+1+1+1+1+1, 1+1+1+1+2, 1+1+2+2, 2+2+2, 1+1+1+3, 1+2+3, 3+3    - (1 + 5 + 6 + 1+ 4 + 6 + 1 = 24)

...

d[n] = d[n-1] +d[n-2] +d[n-3]

*/

