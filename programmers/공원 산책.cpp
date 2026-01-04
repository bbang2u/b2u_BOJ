#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    pair<int, int> cur;
    int H = park.size();
    int W = park[0].size();
    
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(park[i][j] == 'S'){
                cur = {i, j};
                break;
            }
        }
    }
    for(int i=0; i<routes.size(); i++){
        char dir = routes[i][0];
        int dist = routes[i][2] - '0';
        
        int dr = 0, dc = 0;
        if(dir == 'N') dr = -1;
        else if(dir == 'S') dr = 1;
        else if(dir == 'W') dc = -1;
        else if(dir == 'E') dc = 1;
        
        bool valid = true;
        pair<int, int> temp = cur; 
        
        for(int j=1; j<=dist; j++){
            temp.first += dr;
            temp.second += dc;
            if(temp.first < 0 || temp.first >= H || temp.second < 0 || temp.second >= W){
                valid = false;
                break;
            }
            if(park[temp.first][temp.second] == 'X'){
                valid = false;
                break;
            }
        }

        if(valid){
            cur = temp;
        }
    }
    
    return {cur.first, cur.second};
}
