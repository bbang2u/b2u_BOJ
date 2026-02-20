#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    multiset<int> s;
    for(int i = 0; i < k; i++) {
        s.insert(stones[i]);
    }
    
    answer = *s.rbegin();
    for(int i=k; i<stones.size(); i++){
        s.erase(s.find(stones[i - k]));
        
        s.insert(stones[i]);
        
        answer = min(*s.rbegin(), answer);
    }
    
    return answer;
}
