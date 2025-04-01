// �� ����� �ð����⵵�� O(n*n) �̹Ƿ�, �������� �˰������� Ǯ���. -> O(n)
#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

int main(void) {
    int N, M;
    int cnt = 0;
    int sum = 0;
    cin >> N >> M;
    arr.resize(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            sum += arr[j];
            if (sum == M) {
                sum = 0;
                cnt++;
                break;
            }
        }
        if (sum != 0) sum = 0;
    }
    cout << cnt << endl;

    return 0;
}