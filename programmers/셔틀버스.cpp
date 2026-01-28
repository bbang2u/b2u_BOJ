#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int conv(string s) {
    return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
}
string conv2(int i) {
    string first = to_string(i / 60);
    string second = to_string(i % 60);
    if (first.length() == 1) { first = "0" + first; }
    if (second.length() == 1) { second = "0" + second; }
    return first + ":" + second;
}

string solution(int n, int t, int m, vector<string> timetable) {
    map<int, int> times;
    for (string s : timetable) { times[conv(s)]++; }

    int shuttle_idx = 0;      
    int shuttle_cnt = 0;      
    int shuttle_time = conv("09:00"); 

    for (auto& pair : times) {
        int crew_time = pair.first;
        int crew_cnt = pair.second;

        while (crew_cnt > 0) {
            
            if (shuttle_idx >= n) break;

            
            if (crew_time > shuttle_time) {
                shuttle_idx++;
                shuttle_time += t;
                shuttle_cnt = 0;
                continue;
            }

            int space = m - shuttle_cnt;

            if (crew_cnt >= space) {
                if (shuttle_idx == n - 1) {
                    return conv2(crew_time - 1);
                }

                crew_cnt -= space;
                shuttle_idx++;
                shuttle_time += t;
                shuttle_cnt = 0;
            }
            else {
                shuttle_cnt += crew_cnt;
                crew_cnt = 0;
            }
        }
    }

    return conv2(conv("09:00") + (n - 1) * t);
}
