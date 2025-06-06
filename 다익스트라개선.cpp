#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int number = 6;
int INF = 10000000;
vector<pair<int, int>> a[7];
int d[7];

void dijkstra(int start) {
    d[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(start, 0));
    // 최소힙 구조를 이용해 시간복잡도 개선
    while (!pq.empty()) {
        int current = pq.top().first;
        int distance = -pq.top().second;
        pq.pop();
        if (d[current] < distance) continue;
        for (int i = 0; i < a[current].size(); i++) {
            //current 노드의 인접 노드
            int next = a[current][i].first;
            int nextDistance = distance + a[current][i].second;
            // 기존 최소비용보다 더 작은 비용일 시, 거리를 업데이트
            if (nextDistance < d[next]) {
                d[next] = nextDistance;
                pq.push(make_pair(next, -nextDistance));
            }
        }
    }
}
int main(void) {
    for (int i = 1; i <= number; i++) {
        d[i] = INF;
    }
    a[1].push_back(make_pair(2, 2));
    a[1].push_back(make_pair(3, 5));
    a[1].push_back(make_pair(4, 1));

    a[2].push_back(make_pair(1, 2));
    a[2].push_back(make_pair(3, 3));
    a[2].push_back(make_pair(4, 2));

    a[3].push_back(make_pair(1, 5));
    a[3].push_back(make_pair(2, 3));
    a[3].push_back(make_pair(4, 3));
    a[3].push_back(make_pair(5, 1));
    a[3].push_back(make_pair(6, 5));

    a[4].push_back(make_pair(1, 1));
    a[4].push_back(make_pair(2, 2));
    a[4].push_back(make_pair(3, 3));
    a[4].push_back(make_pair(5, 1));

    a[5].push_back(make_pair(3, 1));
    a[5].push_back(make_pair(4, 1));
    a[5].push_back(make_pair(6, 2));

    a[6].push_back(make_pair(3, 5));
    a[6].push_back(make_pair(5, 2));


    dijkstra(1);

    for (int i = 1; i <= number; i++) {
        printf("%d ", d[i]);
    }
    return 0;
}