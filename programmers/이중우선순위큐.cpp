
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> solution(vector<string> operations) {
    unordered_map<int, int> deleted_min;
    unordered_map<int, int> deleted_max;
    vector<int> answer;
    priority_queue<int, vector<int>, less<int>> pq_Max;
    priority_queue<int, vector<int>, greater<int>> pq_Min;

    for (string i : operations) {
        if (i[0] == 'I') {
            pq_Max.push(stoi(i.substr(2)));
            pq_Min.push(stoi(i.substr(2)));
        }
        else {
            if (i[2] == '1') {
                if (pq_Max.empty()) { continue; }

                while (!(deleted_min.find(pq_Max.top()) == deleted_min.end() || deleted_min[pq_Max.top()] == 0)) {
                    deleted_min[pq_Max.top()]--;
                    pq_Max.pop();
                    if (pq_Max.empty()) { break; }
                }

                if (pq_Max.empty()) { continue; }

                deleted_max[pq_Max.top()]++;
                pq_Max.pop();

                if (pq_Max.empty()) { continue; }

                while (!(deleted_min.find(pq_Max.top()) == deleted_min.end() || deleted_min[pq_Max.top()] == 0)) {
                    deleted_min[pq_Max.top()]--;
                    pq_Max.pop();
                    if (pq_Max.empty()) { break; }
                }
            }
            else {
                if (pq_Min.empty()) { continue; }

                while (!(deleted_max.find(pq_Min.top()) == deleted_max.end() || deleted_max[pq_Min.top()] == 0)) {
                    deleted_max[pq_Min.top()]--;
                    pq_Min.pop();
                    if (pq_Min.empty()) { break; }
                }

                if (pq_Min.empty()) { continue; }

                deleted_min[pq_Min.top()]++;
                pq_Min.pop();

                if (pq_Min.empty()) { continue; }

                while (!(deleted_max.find(pq_Min.top()) == deleted_max.end() || deleted_max[pq_Min.top()] == 0)) {
                    deleted_max[pq_Min.top()]--;
                    pq_Min.pop();
                    if (pq_Min.empty()) { break; }
                }
            }
        }
    }

    if (pq_Min.empty()) { return { 0,0 }; }
    else {
        answer.push_back(pq_Max.top());
        answer.push_back(pq_Min.top());
    }
    int count = 0;



    return answer;
}

//어우 지저분해
