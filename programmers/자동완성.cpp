#include <string>
#include <vector>

using namespace std;


class TrieNode {
public:
    TrieNode* children[26];
    int cnt; 

    TrieNode() {
        cnt = 0;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }

    ~TrieNode() {
        for (int i = 0; i < 26; ++i) {
            if (children[i]) delete children[i];
        }
    }
};

TrieNode* root;

// 단어 삽입
void InsertWord(string s) {
    TrieNode* t = root;
    for (int i = 0; i < s.size(); i++) {
        int index = s[i] - 'a';

        if (t->children[index] == nullptr) {
            t->children[index] = new TrieNode();
        }

        t = t->children[index];
        t->cnt++;
    }
}

int solve(string s) {
    TrieNode* t = root;
    int keystrokes = 0;

    for (int i = 0; i < s.size(); i++) {
        int index = s[i] - 'a';
        t = t->children[index];

        keystrokes++;

        if (t->cnt == 1) {
            return keystrokes;
        }
    }
    return keystrokes;
}

int solution(vector<string> words) {
    int answer = 0;

    root = new TrieNode();

    for (string s : words) {
        InsertWord(s);
    }

    for (string s : words) {
        answer += solve(s);
    }



    return answer;
}
