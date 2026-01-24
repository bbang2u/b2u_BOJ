#include<vector>
#include <queue>
using namespace std;
int visited[100][100] = {0,};
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size() - 1;
    int m = maps[0].size() - 1;
    queue<pair<pair<int,int>, int>> q;
    q.push({{0,0},1});
    visited[0][0] = 1;
    while(!q.empty()){
        int cn = q.front().first.first;
        int cm = q.front().first.second;
        q.pop();
        for(int i=0;i<4;i++){
            int nn = cn + dx[i];
            int nm = cm + dy[i];
            if(nn>=0&&nn<=n&&nm>=0&&nm<=m){
                if(visited[nn][nm] == 0 && maps[nn][nm] == 1){
                    q.push({{nn,nm}, visited[cn][cm] + 1});
                    
                    //visited 처리는 push할때 해야함
                    visited[nn][nm] = visited[cn][cm] + 1; 
                }
            }
        }
    }
    if(visited[n][m] == 0){return -1;}
    return visited[n][m];
}
