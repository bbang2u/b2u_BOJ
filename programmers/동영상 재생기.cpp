#include <string>
#include <vector>
#include <iostream>
using namespace std;

// commands_len은 배열 commands의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int vidlen, vidpos, opstart, opend;
string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    vidlen = 60 * stoi(video_len.substr(0, 2)) + stoi(video_len.substr(3, 5));
    vidpos = 60 * stoi(pos.substr(0, 2)) + stoi(pos.substr(3, 5));
    opstart = 60 * stoi(op_start.substr(0, 2)) + stoi(op_start.substr(3, 5));
    opend = 60 * stoi(op_end.substr(0, 2)) + stoi(op_end.substr(3, 5));

    
    for (int i = 0; i < commands.size(); i++) {
        if (vidpos >= opstart && vidpos < opend) { vidpos = opend; }
        if (commands[i] == "next") {
            vidpos += 10;
            if (vidpos > vidlen) { vidpos = vidlen; }
            if (vidpos >= opstart && vidpos < opend) { vidpos = opend; }
        }
        else if (commands[i] == "prev") {
            vidpos -= 10;
            if (vidpos < 0) { vidpos = 0; }
            if (vidpos >= opstart && vidpos < opend) { vidpos = opend; }
        }

    }

    string answer = "";
    int tmp = vidpos / 60;
    if (tmp < 10) { answer += '0'; }
    answer += to_string(tmp);
   
    answer += ":";

    tmp = vidpos % 60;
    if (tmp < 10) { answer += '0'; }
    answer += to_string(tmp);

    return answer;
}


int main() {
    vector<string> cmds = { "next"};

    std::cout << solution("07:22", "04:05", "00:15", "04:07", cmds);
}
