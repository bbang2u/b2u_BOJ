#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<int, string> genremap;
map<string, int> popular;
vector<int> playscopy;
bool compare(int a, int b){
    if(popular[genremap[a]] == popular[genremap[b]]){
        if(playscopy[a] == playscopy[b]){
            return a < b;
        }
        return playscopy[a] > playscopy[b];
    }
    return popular[genremap[a]] > popular[genremap[b]];
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    playscopy = plays;
    for(int i=0;i<genres.size();i++){
        answer.push_back(i);
        genremap[i] = genres[i];
    }
    for(int i=0;i<plays.size();i++){
        popular[genremap[i]]+=plays[i];
    }
    
    sort(answer.begin(), answer.end(), compare);
    
    map<string, int> genrecount;
    for(string i : genres){genrecount[i] = 0;}
    
    vector<int> tmp;
    
    for(int i=0;i<answer.size();i++){
        if(genrecount[genremap[answer[i]]] == 2){continue;}
        tmp.push_back(answer[i]);
        genrecount[genremap[answer[i]]]++;
    }
    return tmp;
}
