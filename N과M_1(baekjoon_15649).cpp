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
            // �ٽ� �̻�� ó��
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

/*1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ����*/
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
            // ��� ó��
            isused[i] = 1;
            cout << "isused[" << i << "]=" << isused[i] << ' ';
            func(k + 1);
            // ���̰� M�� �迭 ���� ������, �ٽ� �̻�� ���·� �ʱ�ȭ
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