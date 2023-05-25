#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int sum = 0, s = 0, e = 0;
    while (s < sequence.size()) {
        if (sum >= k || e == sequence.size()) {
            sum -= sequence[s];
            s++;
        }
        else {
            sum += sequence[e];
            e++;
        }
        if (sum == k && answer.empty()) answer = { s,e - 1 };
        else if (sum == k && ((answer[1] - answer[0]) > (e - 1) - s)) answer = { s,e - 1 };
    }

    return answer;
}

int main() {
    vector<int> answer = solution({ 1, 1, 1, 2, 3, 4, 5 }, 5);
    cout<< answer.front()<<answer.back();
    return 0;
}