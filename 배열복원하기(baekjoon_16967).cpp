#include <iostream>
#include <vector>
using namespace std;

int H, W, X, Y;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> H >> W >> X >> Y;
    vector<vector<int>> origin(H+X, vector<int>(W+Y));
    vector<vector<int>> result(H + X, vector<int>(W + Y));
    for (int i = 0; i < H + X; i++) {
        for (int j = 0; j < W + Y; j++) {
            cin>>result[i][j];
        }
    }

    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            origin[i][j] = result[i][j];
            // origin 배열과 result 배열이 겹치는 경우
            if (i >= X && j >= Y) {
                origin[i][j] -= origin[i - X][j - Y];
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << origin[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}