#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int convert_time(string a) {
    int front = stoi(a.substr(0, 2));
    int back = stoi(a.substr(3, 2));
    return (front * 60) + back;
}
bool compare_time(vector<string> a, vector<string> b) {
    return convert_time(a[1]) < convert_time(b[1]);
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;

    sort(plans.begin(), plans.end(), compare_time);


    stack<pair<int, int>> stop_task;

    for (int i = 0; i < plans.size(); i++) {
        if (i == plans.size() - 1) {
            answer.push_back(plans[i][0]);
            continue;
        }

        int start_curr = convert_time(plans[i][1]);
        int time_curr = stoi(plans[i][2]);
        int start_next = convert_time(plans[i + 1][1]);

        int gap = start_next - start_curr;

        if (time_curr <= gap) {
            answer.push_back(plans[i][0]);
            int remain_gap = gap - time_curr; 

            while (remain_gap > 0 && !stop_task.empty()) {
                int stop_idx = stop_task.top().first;
                int stop_remain = stop_task.top().second;
                stop_task.pop();

                if (stop_remain <= remain_gap) {
                    answer.push_back(plans[stop_idx][0]);
                    remain_gap -= stop_remain;
                }
                else {
                    stop_task.push({ stop_idx, stop_remain - remain_gap });
                    remain_gap = 0;
                }
            }
        }
        else {
            stop_task.push({ i, time_curr - gap });
        }
    }

    while (!stop_task.empty()) {
        answer.push_back(plans[stop_task.top().first][0]);
        stop_task.pop();
    }

    return answer;
}
