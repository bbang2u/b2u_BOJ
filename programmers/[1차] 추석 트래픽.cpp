#include <string>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> conv(string line) {
    int converted = 0;
    int h = stoi(line.substr(11, 2));
    int m = stoi(line.substr(14, 2));
    int s = stoi(line.substr(17, 2));

    converted = h * 3600 + m * 60 + s;

    int milli = stoi(line.substr(20, 3));

    converted *= 1000;
    converted += milli;

    

    double process = stod(line.substr(24));

    int end = (int)(process * 1000);

    return { converted - end + 1, converted};
}

int solution(vector<string> lines) {
    int answer = 1;

    vector<pair<int, int>> times;
    for (string i : lines) {
        times.push_back(conv(i));
    }

    for (int i = 0; i < times.size(); i++) {
        int count = 1;
        int start = times[i].second;;
        int end = start + 999;
        for (int j = i + 1; j < times.size(); j++) {
            if (times[j].first <= end && start <= times[j].second) { count++; }
        }

        answer = max(answer, count);
    }
    

    return answer;
}
