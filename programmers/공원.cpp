#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    int parkA = park.size();
    int parkB = park[0].size();
    
    for(int i : mats) {
        if (i <= 0 || i > parkA || i > parkB) continue;
        
      
        for(int j = 0; j <= parkB - i; j++){ 
            for(int k = 0; k <= parkA - i; k++){ 
                bool able = true;
                for(int a = 0; a < i; a++){
                    if (!able) break;
                    for(int b = 0; b < i; b++){
                        if(park[k + a][j + b] != "-1"){
                            able = false;
                            break;
                        }
                    }
                }
                
                if(able){
                    answer = max(answer, i);
                }
            }
        }
    }
    return answer;
}
