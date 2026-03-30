#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int idx1=0;
    int idx2=0;
    for(string i:goal){
        if(i == cards1[idx1]){
            idx1++;
            continue;
        }
        if(i == cards2[idx2]){
            idx2++;
            continue;
        }
        return "No";
    }
    
    
    return "Yes";
}
