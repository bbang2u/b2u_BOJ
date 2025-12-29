#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

int ipow(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}
int getMaxDigit(string s) {
    int maxD = 0;
    for (char c : s) {
        if (isdigit(c)) {
            maxD = max(maxD, c - '0');
        }
    }
    return maxD;
}

vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    vector<string> front; vector<string> back; vector<string> res;
    vector<string> yeon;

    int max_digit_in_all = 0;

    for (int i = 0; i < expressions.size(); i++) {
        stringstream ss(expressions[i]);
        string segment;
        vector<string> tokens;
        while (ss >> segment) {
            tokens.push_back(segment);
        }
        front.push_back(tokens[0]);
        yeon.push_back(tokens[1]);
        back.push_back(tokens[2]);
        res.push_back(tokens[4]);

        max_digit_in_all = max(max_digit_in_all, getMaxDigit(tokens[0]));
        max_digit_in_all = max(max_digit_in_all, getMaxDigit(tokens[2]));
        if (tokens[4] != "X") {
            max_digit_in_all = max(max_digit_in_all, getMaxDigit(tokens[4]));
        }
    }

    int jin;
    map<int, int> result;
    vector<int> possiblejin;
    set<int> Xloc;
    for (jin = 2; jin <= 9; jin++) {
        if (jin <= max_digit_in_all) continue;
        bool ans = true;
        for (int i = 0; i < front.size(); i++) {
            if (res[i] == "X") { Xloc.insert(i); continue; }
            

            int x = 0; int p = 0;
            for (int j = front[i].size() - 1; j >= 0; j--) {
                x += (ipow(jin, p)) * (front[i][j] - '0');
                p++;
            }
            int y = 0; p = 0;
            for (int j = back[i].size() - 1; j >= 0; j--) {
                y += (ipow(jin, p)) * (back[i][j] - '0');
                p++;
            }
            int z = 0; p = 0;
            for (int j = res[i].size() - 1; j >= 0; j--) {
                z += (ipow(jin, p)) * (res[i][j] - '0');
                p++;
            }
            
            int r;
            if (yeon[i] == "+") { r = x + y; }
            else if(yeon[i] == "-") { r = x - y; }

            if (r != z) { ans = false; break; }

        }
        if (ans) { possiblejin.push_back(jin); }
    }

    for (int i : Xloc) {
        string ans = front[i] + " " + yeon[i] + " " + back[i] + " = ";
        string curz = "";
        for (int k = 0; k < possiblejin.size(); k++) {
            int x = 0; int p = 0;
            for (int j = front[i].size() - 1; j >= 0; j--) {
                x += (ipow(possiblejin[k], p)) * (front[i][j] - '0');
                p++;
            }
            int y = 0; p = 0;
            for (int j = back[i].size() - 1; j >= 0; j--) {
                y += (ipow(possiblejin[k], p)) * (back[i][j] - '0');
                p++;
            }
            int r;
            if (yeon[i] == "+") { r = x + y; }
            else if (yeon[i] == "-") { r = x - y; }

            string z = "";
            while (true) {
                int m = r / possiblejin[k];
                z = z + to_string(r % possiblejin[k]);
                if (m == 0) { break; }
                r = m;
            }
            reverse(z.begin(), z.end());
            if (k == 0) { curz = z; }
            else if (curz != z) { curz = "?"; break; }
        }
        ans += curz;
        answer.push_back(ans);
    }


    return answer;
}

int main() {
    vector<string> tmp;
    tmp.push_back("1 + 1 = 2");
    tmp.push_back("1 + 3 = 4");
    tmp.push_back("1 + 5 = X");
    tmp.push_back("1 + 2 = X");

    vector<string> ans = solution(tmp);
}
