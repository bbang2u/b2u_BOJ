#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    int tmp[1000000]; 
    for (int i = 0; i < 1000000; i++) { tmp[i] = -1; }

    stack<int> idx;

    for (int i = 0; i < numbers.size(); i++) {
        while (!idx.empty()) {
            int cur = idx.top(); 
            if (numbers[cur] < numbers[i]) {
                tmp[cur] = i; idx.pop();
            }
            else { break; }
        }
        idx.push(i);
    }
    vector<int> answer;
    for (int i = 0; i < numbers.size(); i++) {
        if (tmp[i] == -1) { answer.push_back(-1); }
        else { answer.push_back(numbers[tmp[i]]); }
    }
    
    return answer;
}
