#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> score;
    score.insert({ 'R',0 });
    score.insert({ 'T',0 });
    score.insert({ 'C',0 });
    score.insert({ 'F',0 });
    score.insert({ 'J',0 });
    score.insert({ 'M',0 });
    score.insert({ 'A',0 });
    score.insert({ 'N',0 });

    for (int i = 0; i < survey.size(); i++) {
        if (choices[i] > 4)
            score[survey[i][1]] += choices[i] % 4;
        else if (choices[i] == 1)
            score[survey[i][0]] += 3;
        else if (choices[i] == 2)
            score[survey[i][0]] += 2;
        else if (choices[i] == 3)
            score[survey[i][0]] += 1;
    }
    if (score['R'] >= score['T'])
        answer += 'R';
    else
        answer += 'T';

    if (score['C'] >= score['F'])
        answer += 'C';
    else
        answer += 'F';

    if (score['J'] >= score['M'])
        answer += 'J';
    else
        answer += 'M';

    if (score['A'] >= score['N'])
        answer += 'A';
    else
        answer += 'N';

    return answer;
}
int main() {
    cout << solution({ "AN", "CF", "MJ", "RT", "NA" }, { 5, 3, 2, 7, 5 });

    return 0;
}