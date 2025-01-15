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

    // �������� ����
    sort(explorer.begin(), explorer.end());


    for (int e : explorer) {
        count++;
        if (count > e) {
            result++;
            count = 0; // ��� �� �ʱ�ȭ
        }
    }
    cout << "count: " << count << endl;

    return 0;
}