#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[9];
int visited[9];

void permutation(int num) {
    if (num == N) {
        for (int i = 0; i < N; i++) { 
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            arr[num] = i + 1;
            cout << "arr[" << num << "] = " << i + 1 << ' ';
            permutation(num + 1);
            visited[i] = false;
        }
    }
    cout << endl;

}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    permutation(0);
    return 0;
}