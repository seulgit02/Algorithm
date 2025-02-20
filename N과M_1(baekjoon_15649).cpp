#include <iostream>
using namespace std;

int N, M;
int arr[10];
int isused[10] = { 0, };
void func(int k) {
    if (k == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << "/n";
    }
    for (int i = 1; i <= N; i++) {
        if (!isused[i]) {
            arr[k] = i;
            func(k + 1);
            // 다시 미사용 처리
            isused[i] = 0;
        }
    }
}

int main(void) {
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

/*1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열*/
/*
#include <iostream>
using namespace std;
int N, M;
int arr[10];
bool isused[10];

void func(int k) {
    if (k == M) {
        cout << "finish." << endl;
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; i++) {
        if (!isused[i]) {
            arr[k] = i;
            cout << "arr[" << k << "]=" << arr[k] << ' ';
            // 사용 처리
            isused[i] = 1;
            cout << "isused[" << i << "]=" << isused[i] << ' ';
            func(k + 1);
            // 길이가 M인 배열 생성 끝나면, 다시 미사용 상태로 초기화
            isused[i] = 0;
            cout << "isused[" << i << "]=" << isused[i] << ' ';
        }
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
*/