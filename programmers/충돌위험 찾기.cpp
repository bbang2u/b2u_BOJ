#include <string>
#include <vector>
#include <iostream>
#include <map>


using namespace std;

vector<pair<int, int>> get_path(const vector<vector<int>>& points, const vector<int>& route) {
    vector<pair<int, int>> path;

    int start_idx = route[0] - 1;
    int r = points[start_idx][0];
    int c = points[start_idx][1];
    path.push_back({ r, c });

    for (int i = 1; i < route.size(); i++) {
        int next_idx = route[i] - 1;
        int target_r = points[next_idx][0];
        int target_c = points[next_idx][1];

        while (r != target_r) {
            if (r < target_r) r++;
            else r--;
            path.push_back({ r, c });
        }

        while (c != target_c) {
            if (c < target_c) c++;
            else c--;
            path.push_back({ r, c });
        }
    }
    return path;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;

    vector<vector<pair<int, int>>> all_robot_paths;
    int max_time = 0;

    for (const auto& route : routes) {
        vector<pair<int, int>> p = get_path(points, route);
        all_robot_paths.push_back(p);
        if (p.size() > max_time) {
            max_time = p.size();
        }
    }

    for (int t = 0; t < max_time; t++) {

        map<pair<int, int>, int> count_map;

        for (const auto& path : all_robot_paths) {
            if (t < path.size()) {
                count_map[path[t]]++;
            }
        }

        for (auto const& [pos, cnt] : count_map) {
            if (cnt >= 2) {
                answer++;
            }
        }
    }

    return answer;
}
