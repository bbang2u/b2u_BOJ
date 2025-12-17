#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer = players;
    unordered_map<string, int> p_r;
    for(int i=0;i<players.size();i++){
        p_r[players[i]] = i;
    }
    for(int i=0;i<callings.size();i++){
        string call = callings[i];
        
        // 1. 현재 불린 선수의 등수(인덱스) 확인
        int cur_idx = p_r[call]; 
        
        // 2. 바로 앞 선수의 등수(인덱스)와 이름 확인
        int prev_idx = cur_idx - 1;
        string prev_player = answer[prev_idx];
        
        // 3. 맵(Map) 갱신: 서로의 등수를 바꿈
        p_r[call] = prev_idx;       // 불린 선수는 앞으로 (인덱스 감소)
        p_r[prev_player] = cur_idx; // 앞 선수는 뒤로 (인덱스 증가)
        
        // 4. 벡터(Vector) 갱신: 실제 배열 위치를 바꿈
        answer[prev_idx] = call;
        answer[cur_idx] = prev_player;
    }
    
    return answer;
}
