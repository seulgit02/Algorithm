/*
[메모리 초과 개선 코드]

[풀이 해법]
-> reverse해서 오름차순이 되는 첫번째 구간 파악: arr[i-1] > arr[i] -> arr[i-1]과 그 이후 원소들 중 arr[i-1]보다는 작으면서, 그 중 가장 큰 값을 교환
arr[i]부터 arr[n-1]까지 내림차순 정렬
-> 만약 끝까지 내림차순이면 '-1' 출력
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
// 뒤에서 가장 큰값이랑 교환할 때, arr[i-1]보다는 작은 값과 교환해야 함.
// 앞선 순열을 구해야하는 거니까.



/*
[메모리 초과 코드]
1) 수열 입력 받아 오름차순으로 정렬
2) 정렬된 첫번째 수열로부터 next_permutaion 이용해 가능한 모든 경우의 수 벡터에 저장
3) 입력받은 수열 바로 이전의 수열 index를 찾아 해당 수열 출력
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
//    //해당 수열의 모든 가능한 경우의수 조합을 돌려서 해당 vector에 저장
//    vector<string>results;
//
//    // 가능한 모든 순열 생성해서 저장
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
