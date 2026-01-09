#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 10000000 // 1e9보다 적당히 안전한 값 사용 (더할 때 오버플로우 방지)

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    long long answer = INF;
    

    int grid[201][201];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) grid[i][j] = 0;
            else grid[i][j] = INF;
        }
    }
    
    for(auto& edge : fares){
        grid[edge[0]][edge[1]] = edge[2];
        grid[edge[1]][edge[0]] = edge[2];
    }
    
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(grid[i][j] > grid[i][k] + grid[k][j]){
                    grid[i][j] = grid[i][k] + grid[k][j];
                }
            }
        }
    }
    
    for(int k = 1; k <= n; k++){
        if(grid[s][k] != INF && grid[k][a] != INF && grid[k][b] != INF) {
            long long total_fare = (long long)grid[s][k] + grid[k][a] + grid[k][b];
            answer = min(answer, total_fare);
        }
    }
    
    return (int)answer;
}

// 오답
// #include <string>
// #include <vector>
// #include <queue>
// #include <algorithm>
// using namespace std;

// int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
//     long long answer = (int)1e9;
    
//     int grid[201][201];
//     for(int i=0;i<201;i++){
//         for(int j=0;j<201;j++){
//             grid[i][j] = (int)1e9;
//         }
//     }
//     for(vector<int> i : fares){
//         grid[i[0]][i[1]] = i[2];
//         grid[i[1]][i[0]] = i[2];
//     }
    
//     vector<long long> duofare(n + 1);
//     fill(duofare.begin(), duofare.end(), (int)1e9);
//     duofare[s] = 0;
//     queue<pair<int,int>> q;
//     q.push({s, 0});
//     while(!q.empty()){
//         int cur = q.front().first;
//         int fee = q.front().second;
//         q.pop();
//         for(int i=1;i<=n;i++){
//             if(i==cur){continue;}
//             if(duofare[i] > fee + grid[cur][i]){
//                 q.push({i, fee + grid[cur][i]});
//                 duofare[i] = fee + grid[cur][i];
//             }
//         }
//     }
    
//     for(int s=1;s<=n;s++){
//         vector<long long> monofare(n + 1);
//         fill(monofare.begin(), monofare.end(), (int)1e9);
//         monofare[s] = 0;
//         queue<pair<int,int>> q2;
//         q2.push({s, 0});
//         while(!q2.empty()){
//             int cur = q2.front().first;
//             int fee = q2.front().second;
//             q2.pop();
//             for(int i=1;i<=n;i++){
//                 if(i==cur){continue;}
//                 if(monofare[i] > fee + grid[cur][i]){
//                     q2.push({i, fee + grid[cur][i]});
//                     monofare[i] = fee + grid[cur][i];
//                 }
//             }
//         }
//         answer = min(answer, duofare[s] + monofare[a] + monofare[b]);
//     }
    
//     return answer;
// } 
