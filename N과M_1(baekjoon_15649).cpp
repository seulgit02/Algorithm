#include <iostream>
using namespace std;
/*1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열*/
int N, M;
int arr[10];
bool isused[10];

void func(int k) {
    if (k == M) {
        cout<<"k = " << M << "에 도달했습니다!"<<endl;
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout <<'\n';
        return;
    }
    for (int i = 1; i <= N; i++) {
        cout << "i = " << i << endl;
        if (!isused[i]) {
            arr[k] = i;
            isused[i] = 1;
            func(k + 1);
            isused[i] = 0;
        }
        cout << "isused[" << i << "] = " << isused[i] << ' ';
    }
    cout << '\n';
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    func(0);
    return 0;
}

// 4 2

//arr[0] = 1
// isused[1] = true
// func(1)
// arr[1] = 2
// isused[2] = true
// func(2)
// arr[2] = 3
// isused[3]=true
// func(3)
// arr[3] = 4
// isused[4] = true
// func(4)
// isused[1] = false
// arr[0] = 2
// isused[2] = true
// func(1)
// ...