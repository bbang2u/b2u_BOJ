#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_set<string> s;
    for (string i : phone_book) { s.insert(i); }
    for (string i : phone_book) {
        for (int j = 1; j <= i.length(); j++) {
            string tmp = i.substr(0, j);
            if (s.find(tmp) != s.end() && tmp != i) {
                return false;
            }
        }
    }
    return true;
}
