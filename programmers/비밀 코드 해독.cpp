#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    vector<int>v;
    for(int i = 1;i<=n;i++){v.push_back(i);}
    vector<int>temp(n);
    for(int i = 0;i<5;i++){temp[i] = 1;}
 
    do {
        vector<int> cur;
        for (int i = 0; i < v.size(); ++i) {
            if (temp[i] == 1)
                cur.push_back(v[i]);
        }
        bool valid = true;
        
        for(int i = 0 ;i < q.size();i++){
            int count = 0;
            unordered_set<int> curq;
            for(int j : q[i]){curq.insert(j);}
            
            int tmp = 0;
            for (int j : cur){
                if(curq.find(j) != curq.end()){count++;}
            }
            if(count != ans[i]){valid = false;}
        }
        if(valid){answer++;}
    } while (prev_permutation(temp.begin(), temp.end()));

 
    
    
    
    return answer;
}
