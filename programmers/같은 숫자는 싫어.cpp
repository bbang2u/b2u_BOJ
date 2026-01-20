#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    return arr;
    
    /*vector<int> answer;
    stack<int> s;
    s.push(arr[0]);
    answer.push_back(arr[0]);
    for(int i=0;i<arr.size();i++){
        if(arr[i] == s.top()){continue;}
        else{
            s.pop();
            s.push(arr[i]);
            answer.push_back(arr[i]);
        }
    }


    return answer;*/
}
