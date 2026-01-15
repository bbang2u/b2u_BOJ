#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int num;
bool compare(string a, string b){
    if(a[num] == b[num]){
        return a < b;
    }
    return a[num] < b[num];
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer = strings;
    num = n;
    sort(answer.begin(), answer.end(), compare);
    
    return answer;
}
