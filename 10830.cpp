
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;
int arr[5][5];    int n; long long m;//int로 하면 틀림

bool isinside(int a, int b) { return a >= 0 && a < n && b >= 0 && b < m; }

void power(int arr[][5], long long m) {
    int newarr[5][5] = { 0 };
    for (int i = 0; i < n; i++) {
        newarr[i][i] = 1;
    }
    while (m > 0) {
        
        if (m % 2 == 1) {
            int temp[5][5] = { 0 };
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        temp[i][j] += newarr[i][k] * arr[k][j];
                        temp[i][j] %= 1000;
                    }
                    
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) { newarr[i][j] = temp[i][j]; }
            }
        }

        int tmp[5][5] = { 0 };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    tmp[i][j] += arr[i][k] * arr[k][j];
                    tmp[i][j] %= 1000;
                }
                
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) { arr[i][j] = tmp[i][j]; }
        }

        m /= 2;
        
    }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) { cout << newarr[i][j] << " "; }
            cout << endl;
        }
    
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { cin >> arr[i][j]; }
    }
    power(arr, m);
    return 0;
}
