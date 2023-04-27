#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int i;
    for (i = 0; i < goal.size(); i++) {
        if (cards1.front() == goal[i]) {
            cards1.erase(cards1.begin());
            if (i == goal.size() - 1)
                answer = "Yes";
            continue;
        }
        else if (cards2.front() == goal[i]) {
            cards2.erase(cards2.begin());
            if (i == goal.size() - 1)
                answer = "Yes";
            continue;
        }
        else {
            answer = "No";
            break;
        }
    }
    return answer;
}