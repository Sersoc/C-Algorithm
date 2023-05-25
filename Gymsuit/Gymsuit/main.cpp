#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int lender = lost.size();
    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            if (lost[i] == reserve[j]) {
                reserve.erase(reserve.begin() + j);
                lender--;
            }
        }
    }
    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            if (lost[i] - 1 == reserve[j] || lost[i] + 1 == reserve[j]) {
                reserve.erase(reserve.begin() + j);
                lender--;
            }
        }
    }
    answer = n - lender;
    return answer;
}

int main() {
    cout << solution(5,{ 4,5 }, { 3,4 });

        return 0;
}