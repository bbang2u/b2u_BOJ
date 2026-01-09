#include <string>
#include <vector>
#include <queue>

using namespace std;

bool changable(string a, string b){
    int tmp = 0;
    for(int i=0;i<a.size();i++){
        if(a[i] == b[i]){tmp++;}
    }
    return (a.size() - tmp == 1);
}
bool cmp(string a, string b){
    int tmp = 0;
    for(int i=0;i<a.size();i++){
        if(a[i] == b[i]){tmp++;}
    }
    return a.size() - tmp;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<int> distance(words.size());
    fill(distance.begin(), distance.end(), -1);
    
    bool able = false; int dest;
    for(int i=0;i<words.size();i++){
        if(cmp(words[i], target) == 0){
            able = true; dest = i;
        }
    }
    if(!able){return 0;}
    
    queue<pair<string, int>> q;
    q.push({begin, 0});
    while(!q.empty()){
        string cur = q.front().first;
        int turn = q.front().second;
        q.pop();
        for(int i=0;i<words.size();i++){
            if(changable(cur, words[i])){
                if(distance[i] == -1 || turn + 1 < distance[i]){
                    q.push({words[i], turn + 1});
                    distance[i] = turn + 1;
                }
            }
        }
    }
    
    return distance[dest];
}
