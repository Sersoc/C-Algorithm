#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    int pick_sum = 0;
    int sum = 0, mineral;
    vector<int> ft;
    vector<vector<int>> fatigue;
    for (int i = 0; i < picks.size(); i++) {
        pick_sum += picks[i];
    }

    int n = 0, t = 1;
    while (minerals.size() > n && pick_sum * 5 > n) {

        if (minerals[n] == "diamond")
            mineral = 25;
        else if (minerals[n] == "iron")
            mineral = 5;
        else mineral = 1;

        sum += mineral;

        if (n == minerals.size() - 1) {
            fatigue.push_back({ sum,t });
            break;
        }
        if (t == 5) {
            fatigue.push_back({ sum,t });
            t = 1;
            n++;
            sum = 0;
            continue;
        }
        n++;
        t++;
    }
    sort(fatigue.begin(), fatigue.end());
    while (!fatigue.empty()) {
        ft = fatigue.back();
        fatigue.pop_back();
        if (picks[0] != 0) {
            answer += ft[1];
            picks[0]--;
        }
        else if (picks[1] != 0) {
            if (ft[0] == 5)
                answer += ft[1];
            else
                answer += ft[0] / 5 + ft[0] % 5;
            picks[1]--;

        }
        else {
            answer += ft[0];
            picks[2]--;
        }
    }

    return answer;
}

int main() {
    cout << solution({ 1, 3, 2 }, { "diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone" }) << endl;
    cout << solution({ 0, 1, 1 }, { "diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond" }) << endl;
    cout << solution({ 1,1,0 }, { "diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone", "iron", "iron", "diamond", "diamond" }) << endl;
    cout << solution({ 0,1,0 }, { "stone" ,"stone" ,"stone" ,"stone" ,"stone" }) << endl;
    cout << solution({ 1, 0, 1 }, { "iron", "iron", "iron", "iron", "diamond", "diamond", "diamond" }) << endl; 
    cout << solution({ 0, 1, 99 }, { "diamond", "diamond", "diamond", "diamond", "diamond", "diamond" });
    return 0;
}