/*
[�޸� �ʰ� ���� �ڵ�]

[Ǯ�� �ع�]
-> reverse�ؼ� ���������� �Ǵ� ù��° ���� �ľ�: arr[i-1] > arr[i] -> arr[i-1]�� �� ���� ���ҵ� �� arr[i-1]���ٴ� �����鼭, �� �� ���� ū ���� ��ȯ
arr[i]���� arr[n-1]���� �������� ����
-> ���� ������ ���������̸� '-1' ���
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;



int main(void) {
    int n, element;
    bool isSwap = false;
    cin >> n;
    vector<int> arr;
   
    for (int i = 0; i < n; i++) {
        cin >> element;
        arr.push_back(element);
    }


    int index;
    for (int i = n-1; i >=1; i--) {
        if (arr[i] < arr[i - 1]) {
            int max = 0, index;
            for (int j = i; j < n; j++) {
                if (max < arr[j] && arr[j] < arr[i - 1]) {
                    max = arr[j];
                    index = j;
                }
            }
            swap(arr[i-1], arr[index]);
            sort(arr.begin()+i, arr.end(), greater<>());
            isSwap = true;
            break;
        }
    }
    if (isSwap) {
        for (int i = 0; i < n;i++) {
            if (i < n - 1) {
                cout << arr[i] << " ";
            }
            else {
                cout << arr[i] << endl;
            }
        }
    }
    else {
        cout << -1 << endl;
    }

    return 0;
}
// �ڿ��� ���� ū���̶� ��ȯ�� ��, arr[i-1]���ٴ� ���� ���� ��ȯ�ؾ� ��.
// �ռ� ������ ���ؾ��ϴ� �Ŵϱ�.



/*
[�޸� �ʰ� �ڵ�]
1) ���� �Է� �޾� ������������ ����
2) ���ĵ� ù��° �����κ��� next_permutaion �̿��� ������ ��� ����� �� ���Ϳ� ����
3) �Է¹��� ���� �ٷ� ������ ���� index�� ã�� �ش� ���� ���
*/
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//using namespace std;
//
//int main(void) {
//    int n;
//    string result, input;
//    cin >> n;
//    vector<int> elements(n);
//
//    for (int i = 0; i < n; i++) {
//        cin >> elements[i];
//        input += to_string(elements[i]);
//    }
//
//    sort(elements.begin(), elements.end());
//
//    //�ش� ������ ��� ������ ����Ǽ� ������ ������ �ش� vector�� ����
//    vector<string>results;
//
//    // ������ ��� ���� �����ؼ� ����
//    do {
//        for(int e:elements){
//            result+=to_string(e);
//        }
//        results.push_back(result);
//        result = "";
//    } while(next_permutation(elements.begin(), elements.end()));
//    sort(results.begin(), results.end());
//    if (results[0] == input){
//        cout<<-1<<endl;
//    } else{
//        auto iterator = find(results.begin(), results.end(), input);
//        auto answer_index = iterator - results.begin();
//        for (int i = 0; i < n; i++) {
//            cout<< results[answer_index - 1][i] <<" ";
//        }
//
//    };
//    return 0;
//}
