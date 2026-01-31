#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

set<string> result_set;
bool visited[10];

bool isMatch(string user, string banned) {
    if (user.length() != banned.length()) return false;
    
    for (int i = 0; i < user.length(); i++) {
        if (banned[i] != '*' && user[i] != banned[i]) {
            return false;
        }
    }
    return true;
}


void dfs(int idx, string mask, const vector<string>& user_id, const vector<string>& banned_id) {
    if (idx == banned_id.size()) {
        sort(mask.begin(), mask.end());
        result_set.insert(mask); 
        return;
    }
    for (int i = 0; i < user_id.size(); i++) {
        
        if (visited[i]) continue;
        string prev = mask;
        
        if (isMatch(user_id[i], banned_id[idx])) {
            visited[i] = true;
            mask += to_string(i);
            
            dfs(idx + 1, mask, user_id, banned_id);
            
            visited[i] = false;
            mask = prev;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {

    for(int i=0; i<10; i++) visited[i] = false;

    dfs(0, "", user_id, banned_id);

    return result_set.size();
}
