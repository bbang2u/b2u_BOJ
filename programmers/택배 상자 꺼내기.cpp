#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    vector<vector<int>> grid(w);
    int direction = 1;
    int cur = 0;
    int i=1;
    while(i<=n){
        grid[cur].push_back(i);
        cur+=direction;
        if(cur<0){
            cur=0; direction*=-1;
        }
        if(cur>=w){
            cur=w-1; direction*=-1;
        }
        i++;
    }
    for(int j=0;j<grid.size();j++){
        for(int k=0;k<grid[j].size();k++){
            if(grid[j][k]==num){
                return grid[j].size() - k;
            }
        }
    }
    return answer;
}
