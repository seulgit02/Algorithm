// 시간복잡도 O(n*n) 버전
#include <iostream>
using namespace std;

int number = 6;
int INF = 999999999;

// 전체 그래프 초기화
int a[6][6] = {
    {
        0, 2, INF, 1, INF, INF
    },{
        2, 0, 3, 2, INF, INF
    }, {
        INF, 3, 0, INF, INF, INF
    }, {
        1, 2, INF, 0, 1, INF
    }, {
        INF, INF,INF, 1, 0, 2
    }, {
        INF, INF, 5, INF, 2, 0
    }
};
bool v[6] = { false, };  // 방문한 노드
int d[6];   // 최단 거리

// 가장 최소 거리를 가지는 정점을 반환
int getSmallIndex() {
    int min = INF;
    int index = 0;
    for (int i = 0; i < number; i++) {
        // 방문하지 않은 노드 중에서, 현재 최단거리보다 더 작은 값을 가지는 노드가 존재한다면
        if (d[i] < min && !v[i]) {
            min = d[i];
            index = i; // 그때의 위치를 기록
        }
    }
    return index;
}

// 다익스트라를 수행하는 함수
void dijkstra(int start) {
    for (int i = 0; i < number; i++) {
        d[i] = a[start][i];
    }
    v[start] = true; // 시작노드 방문처리
    for (int i = 0; i < number - 2; i++) { // 자기 자신 제외한 노드 순회
        int current = getSmallIndex();
        v[current] = true; // 노드 방문 처리
        for (int j = 0; j < 6; j++) {
            if (!v[j]) {
                if (d[current] + a[current][j] < d[j]) {
                    d[j] = d[current] + a[current][j];
                }
            }
        }
    }
}

int main(void) {

    dijkstra(0);
    for (int i = 0; i < number; i++) {
        printf("%d\t", d[i]);
    }
    return 0;
}
