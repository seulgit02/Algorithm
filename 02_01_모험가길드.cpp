#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{

    int n, count = 0, result = 0;
    cin >> n;

    vector<int> explorer(n);
    for (int i = 0; i < n; i++) {
        cin >> explorer[i];
    }

    // 오름차순 정렬
    sort(explorer.begin(), explorer.end());


    for (int e : explorer) {
        count++;
        if (count > e) {
            result++;
            count = 0; // 사람 수 초기화
        }
    }
    cout << "count: " << count << endl;

    return 0;
}