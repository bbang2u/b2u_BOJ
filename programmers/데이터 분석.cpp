#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int sort_val;

bool compare(vector<int> a, vector<int> b){
    return a[sort_val] < b[sort_val];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    int data_val; 
    if(ext == "code"){data_val = 0;}
    else if (ext == "date"){data_val = 1;}
    else if (ext == "maximum"){data_val = 2;}
    else if (ext == "remain"){data_val = 3;}
    
    if(sort_by == "code"){sort_val = 0;}
    else if (sort_by == "date"){sort_val = 1;}
    else if (sort_by == "maximum"){sort_val = 2;}
    else if (sort_by == "remain"){sort_val = 3;}


    for(vector<int> i : data){
        if(i[data_val] < val_ext){
            answer.push_back(i);
        }
    }
    
    sort(answer.begin(), answer.end(), compare);
    
    return answer;
}
