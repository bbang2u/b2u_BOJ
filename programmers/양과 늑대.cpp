#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> g_info;            
vector<vector<int>> adj;       
int max_sheep = 0;             


void dfs(int current, int sheep, int wolf, vector<int> candidates) {
    if(g_info[current] == 0){sheep++;}
    else{wolf++;}
    
    if(sheep <= wolf){return;}
    
    max_sheep = max(max_sheep, sheep);
    
    vector<int> new_candidates;
    
    for (int node : candidates) {
        if (node != current) {
            new_candidates.push_back(node);
        }
    }
    
    for(int i : adj[current]){
        new_candidates.push_back(i);
    }
    
    for(int i : new_candidates){
        dfs(i, sheep, wolf, new_candidates);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    adj.assign(info.size(), vector<int>());
    g_info = info;
    max_sheep = 0;
    for (const auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
    }

    dfs(0, 0, 0, {0});

    return max_sheep;
}
