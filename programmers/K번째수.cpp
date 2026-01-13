#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto& i : commands){
        vector<int> tmp;
        for(int j = i[0] - 1; j<=i[1] - 1;j++){
            tmp.push_back(array[j]);
        }
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[i[2] - 1]);
    }
    return answer;
}
