#include <iostream>
#include <algorithm>
using namespace std;

int grid[500][500];
int a, b, c;

int main() {
    cin >> a >> b >> c;
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            cin >> grid[i][j];

    int ans = (int)1e9; int height = 0;
    for (int k = 0; k <= 256; k++) {
        int tmp = 0; int offset = 0;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (k < grid[i][j]) {
                    tmp += 2 * (grid[i][j] - k);
                    offset -= (grid[i][j] - k);
                }
                else {
                    tmp += (k - grid[i][j]);
                    offset += (k - grid[i][j]);
                }
            }
        }
        if (offset <= c && tmp<=ans) {
            ans = tmp; height = k;
        }
    }
    

    cout << ans << " " << height;
    return 0;
}
