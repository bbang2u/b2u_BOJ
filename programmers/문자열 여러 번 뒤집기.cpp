#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    string answer = my_string;
    for(vector<int> i : queries){
        while(i[0] < i[1]){
            char tmp = answer[i[0]];
            answer[i[0]] = answer[i[1]];
            answer[i[1]] = tmp;
            i[0]++; i[1]--;
        }
    }
    return answer;
}
