#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    int maxdist = 0;
    
    vector<vector<int>> adj;
    adj.assign(n + 1, vector<int>());
    
    for (const auto& e : edge) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    
    vector<int> dist(n+1);
    fill(dist.begin(), dist.end(), -1);
    
    queue<pair<int,int>> q;
    q.push({1,0});
    dist[1] = 0;
    
    while(!q.empty()){
        int cur = q.front().first;
        int distance = q.front().second;
        q.pop();
        
        for(int i : adj[cur]){
            if(dist[i] == -1){
                q.push({i, distance + 1});
                dist[i] = distance + 1;
                maxdist = max(maxdist, dist[i]);
            }
        }
    }
    
    for(int i:dist){
        if(i == maxdist){answer++;}
    }
    
    return answer;
}
