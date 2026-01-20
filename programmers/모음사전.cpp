#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> dict;
string aeiou[5] = { "A","E","I","O","U" };
vector<string> generate(int a) {
    vector<string> cur;
    string t = "";
    for (int i = 0; i < a; i++) {
        vector<string> tmp;
        for (int j = 0; j < 5; j++) {
            if (i == 0) {
                tmp.push_back(t + aeiou[j]);
            }
            else {
                for (string c : cur) {
                    tmp.push_back(c + aeiou[j]);
                }
            }
        }
        cur = tmp;
    }
    return cur;
}
int solution(string word) {
    int answer = 0;
    for (int i = 1; i <= 5; i++) {
        vector<string> cur = generate(i);
        dict.insert(dict.end(), cur.begin(), cur.end());
    }
    sort(dict.begin(), dict.end());
    for (int i = 0; i < dict.size(); i++) {
        if (dict[i] == word) {
            return i + 1;
        }
    }
    return answer;
}
