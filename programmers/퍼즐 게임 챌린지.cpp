#include <string>
#include <vector>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int left = 1; int right = 300000; int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        bool able = true;

        {
            long long time = 0; long long time_prev = 0;
            for (int i = 0; i < diffs.size(); i++) {
                if (diffs[i] <= mid) {
                    time_prev = times[i];
                }
                else {
                    int tmp = (i == 0) ? 0 : times[i - 1];
                    time_prev = ((tmp + times[i]) * (diffs[i] - mid)) + times[i];
                }
                time += time_prev;
                if (time > limit) { able = false; break; }
            }
        }

        if (able) {
            answer = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
        mid = (left + right) / 2;
    }
    return answer;
}




