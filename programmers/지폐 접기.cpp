#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    if(wallet[0]<wallet[1]){
        int tmp=wallet[1];
        wallet[1] = wallet[0];
        wallet[0] = tmp;
    }
    while(true){
        if(bill[0]<bill[1]){
            int tmp=bill[1];
            bill[1] = bill[0];
            bill[0] = tmp;
        }
        if(wallet[0] >= bill[0] && wallet[1] >= bill[1]){
            break;
        }
        else{
            answer++;
            bill[0]/=2;
        }
    }
    return answer;
}
