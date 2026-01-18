#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int c, int d) {
    int answer = 0;
    int dice[7] = {0,};
    dice[a]++;
    dice[b]++;
    dice[c]++;
    dice[d]++;
    int tmp = 0;
    int before2 = 0;
    int before3 = 0;
    int aa = 0; int bb = 0; int cc = 0; int dd = 0;
    for(int i=1;i<=6;i++){
        if(dice[i] == 4){return i * 1111;}
        if(dice[i] == 3){before3 = i;}
        if(dice[i] == 2){
            if(before2==0){before2 = i;}
            else{return (i + before2) * (i - before2);}
        }
        if(dice[i] == 1){
            if(aa == 0){aa = i;}
            else if(bb == 0){bb = i;}
            else{
                if(cc == 0){cc=i;}
                else{dd = i;}
            }
        }
    }
    if(before3 != 0){return ((10 * before3) + aa) * ((10 * before3) + aa);}
    if(cc != 0){return aa;}
    else{ return aa * bb;}
    return answer;
}

// 어우 지저분해
