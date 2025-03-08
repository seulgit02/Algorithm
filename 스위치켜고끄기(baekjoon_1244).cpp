#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int switch_num, student_num;
    cin >> switch_num;

    // 1-based �迭 ���
    int* switches = new int[switch_num + 1];

    for (int i = 1; i <= switch_num; i++) {
        cin >> switches[i];
    }

    cin >> student_num;
    vector<pair<int, int>> students;

    for (int i = 0; i < student_num; i++) {
        int gender, btn;
        cin >> gender >> btn;
        students.push_back(make_pair(gender, btn));
    }

    for (auto student : students) {
        int gender = student.first;
        int btn = student.second;

        if (gender == 1) {  // ���л� (��� ���)
            for (int i = btn; i <= switch_num; i += btn) {
                switches[i] = (switches[i] == 1) ? 0 : 1;
            }
        }
        else {  // ���л� (��Ī ���)
            int left = btn, right = btn;
            for (int i = 1; btn - i >= 1 && btn + i <= switch_num; i++) {
                if (switches[btn - i] == switches[btn + i]) {
                    left = btn - i;
                    right = btn + i;
                }
                else {
                    break;
                }
            }

            for (int i = left; i <= right; i++) {
                switches[i] = (switches[i] == 1) ? 0 : 1;
            }
        }
    }

    for (int i = 1; i <= switch_num; i++) {
        cout << switches[i] << " ";
        if (i % 20 == 0) cout << endl;
    }
    cout << endl;  // ������ ���� �߰�

    delete[] switches;  // ���� �Ҵ� ����
    return 0;
}



//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main(void) {
//
//    int switch_num, student_num, gender, btn;
//    cin >> switch_num;
//    int* switches = new int[switch_num+1];
//
//    for (int i = 1; i <= switch_num; i++) {
//        cin >> switches[i];
//    }
//
//    cin >> student_num;
//    vector<pair<int,int>> students;
//
//    for (int i = 1; i <= student_num; i++) {
//        cin>>gender>>btn;
//        students.push_back(make_pair(gender, btn));
//    }
//
//    for (auto student: students) {
//        if (student.first == 1) {
//            int target = student.second;
//            // ��� switch
//            for (int i = target; i <= switch_num; i += target) {
//                switches[i-1] = (switches[i-1] == 1) ? 0 : 1;
//            }
//        }
//        else if (student.first == 2) {
//            // ��Ī�� ã�Ƽ� switch
//            int target = student.second;
//            int max = target;
//            for (int i = 1; target - i >= 1 && target + i <= switch_num; i++) {
//                if (switches[target - i] == switches[target + i]) {
//                    max = target + i;
//                }
//                else {
//                    break;  // ��Ī�� ������ �ߴ�
//                }
//            }
//            switches[target] = (switches[target] == 1) ? 0 : 1;
//
//            for (int i = 1; i <= max-target; i++) {
//                switches[target-i] =(switches[target-i] == 1) ? 0:1;
//                switches[target + i] = (switches[target + i] == 1) ? 0 : 1;
//                
//            }
//        }
//
//    }
//
//    for (int i = 1; i <= switch_num; i++) {
//        cout << switches[i] << " ";
//        //if (i % 20 == 0) cout << endl;
//
//    }
//    return 0;
//}
//// 0 1 0 1 0 0 0 1
//// 0 1 1 1 0 1 0 1
//// 1 0 1 0 1 1 0 1