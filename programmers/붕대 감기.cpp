#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int time = 0; int firsthealth = health;
    bool haveattack[1001] = { false, };
    for (int i = 0; i < attacks.size(); i++) {
        haveattack[attacks[i][0]] = true;
    }
    int healcount = 1; int attackcount = 0;
    for (int i = 1; i <= 1000; i++) {
        if (haveattack[i]) {
            health -= attacks[attackcount++][1];
            healcount = 1;
            
            if (health <= 0) { return -1; }
            if (attackcount == attacks.size()) { return health; }
        }
        else {
            if (health < firsthealth) {
                health += bandage[1];
                if (healcount++ == bandage[0]) {
                    health += bandage[2];
                    healcount = 1;
                }
            }
            if (health > firsthealth) {
                health = firsthealth;
            }
        }
    }

    return health;
}
