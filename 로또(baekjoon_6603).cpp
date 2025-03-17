#include <iostream>
#include <vector>
using namespace std;
// ���� s�� k�� �־����� ��, ���� ���� ��� ����� ���ϴ� ���α׷�
int s, k;
int set[49];
vector<int> subset;
void backTracking(int index, int order) {
    // 6�� ��� ���� �Ϸ�������, �迭 ���
    if (order == 6) {
        for (int i = 0; i < order; i++) {
            // ���ݱ��� ����� �迭 ���
            cout << subset[i] << ' ';    
        };  
        cout << endl;
        return;
    }

    for (int i = index; i < s; i++) {
        subset.push_back(set[i]);
        backTracking(i + 1, order + 1);
        subset.pop_back(); // backtracking ���� �� ���� ����
    }

}

int main(void) {
    while (true) {
        cin >> s;
        if (s == 0) break;
        for (int i = 0; i < s; i++) {
            cin >> set[i];
        }
        backTracking(0, 0);
        cout << endl;
    }

    return 0;
}