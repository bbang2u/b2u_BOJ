#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int brown, int yellow) {
    for(int i=1;i<=yellow;i++){
        if(yellow % i == 0){
            if(2 * i + 2 * (yellow/i) + 4 == brown){
                return {max(i, yellow/i) + 2, min(i, yellow/i) + 2};
            }
        }
    }
}
