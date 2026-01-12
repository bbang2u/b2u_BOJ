#include <string>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false; 
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    unordered_set<int> unique_nums;

    sort(numbers.begin(), numbers.end());
    do {
        string temp = "";
        for (int i = 0; i < numbers.size(); i++) {
            temp += numbers[i];
            unique_nums.insert(stoi(temp));
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    for (int num : unique_nums) {
        if (isPrime(num)) {
            answer++;
        }
    }
    
    return answer;
}
