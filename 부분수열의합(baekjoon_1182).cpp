#include <iostream>
#include <vector>
using namespace std;
int N, S, element, cnt = 0;
vector<int> elements;

void subset_sum(int index, int sum) {
    if (index >= N) return;
    sum += elements[index];
    // �κ������� sum�� ��ǥ�� S�� �������� ī����
    if (sum == S) cnt += 1;

    // ���� ���� �����ؼ� �߰� Ž��
    subset_sum(index + 1, sum);
    // ���� ���� �������ؼ� �߰�Ž��
    subset_sum(index + 1, sum - elements[index]);
}

int main(void) {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> element;
        elements.push_back(element);
    }
    subset_sum(0, 0);
    cout << cnt << endl;
    return 0;
}