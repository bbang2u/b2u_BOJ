#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    for(int i=citations.size();i>=0;i--){
        int count = 0;
        for(int j=citations.size() - 1;j>=0;j--){
            if(citations[j] >= i){count++;}
            if(count >= i){return i;}
        }
    }
    return answer;
}
