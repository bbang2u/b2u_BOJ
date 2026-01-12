#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    vector<int> v1;
    vector<int> v2;
    for(auto& i:sizes){
        sort(i.begin(), i.end());
        v1.push_back(i[0]);
        v2.push_back(i[1]);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    return v1[sizes.size()-1]*v2[sizes.size()-1];
}
