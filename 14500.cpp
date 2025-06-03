#include <iostream>
#include <algorithm>
using namespace std;

int grid[500][500];
int a, b;

bool isinside(int x, int y) {
    return x >= 0 && y >= 0 && x < a && y < b;
}
//너무 무식하게 했나?
int blocks[19][4][2] = {
    {{0,0},{0,1},{0,2},{0,3}},  // ㅡ
    {{0,0},{1,0},{2,0},{3,0}},  // ㅣ
    {{0,0},{1,0},{0,1},{1,1}},  // ㅁ
    {{0,0},{0,1},{0,2},{1,2}},  // ㄴ
    {{0,0},{1,0},{2,0},{0,1}},  // ㄴ 회전
    {{0,0},{1,0},{1,1},{1,2}},  // ㄴ 뒤집기
    {{0,0},{0,1},{-1,1},{-2,1}},// ㄴ 뒤집기 회전
    {{0,0},{0,1},{1,1},{1,2}},  // ㄱ
    {{0,0},{1,0},{0,1},{-1,1}}, // ㄱ 회전
    {{0,0},{0,1},{0,2},{-1,2}}, // ㄱ 뒤집기
    {{0,0},{1,0},{2,0},{2,1}},  // ㄱ 뒤집기 회전
    {{0,0},{1,0},{0,1},{0,2}},  // T자
    {{0,0},{0,1},{1,1},{2,1}},  // T자 회전
    {{0,0},{0,1},{-1,1},{-1,2}},// Z자
    {{0,0},{1,0},{1,1},{2,1}},  // Z자 회전
    {{0,0},{1,0},{2,0},{1,1}},  // T자 변형1
    {{0,0},{0,1},{-1,1},{0,2}}, // T자 변형2
    {{0,0},{-1,1},{0,1},{1,1}}, // T자 변형3
    {{0,0},{0,1},{1,1},{0,2}}   // T자 변형4
};

int calc(int x, int y) {
    int ma = 0;
    for (int i = 0; i < 19; i++) {
        int tmp = 0;
        bool valid = true;
        for (int j = 0; j < 4; j++) {
            int nx = x + blocks[i][j][0];
            int ny = y + blocks[i][j][1];
            if (!isinside(nx, ny)) {
                valid = false;
                break;
            }
            tmp += grid[nx][ny];
        }
        if (valid) ma = max(ma, tmp);
    }
    return ma;
}

int main() {
    cin >> a >> b;
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            cin >> grid[i][j];

    int ans = 0;
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            ans = max(ans, calc(i, j));

    cout << ans;
    return 0;
}
