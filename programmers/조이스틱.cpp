#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int n = name.length();
    int answer = 0;
    int min_move = n - 1; 

    for (int i = 0; i < n; i++) {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);

        int next = i + 1;
        while (next < n && name[next] == 'A') {
            next++;
        }
        min_move = min(min_move, i + n - next + min(i, n - next));
    }

    answer += min_move;
    return answer;
}
