#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool compare(int i, int j) {
    return i < j;
}
int distance(int i, int j) {
    int dis;
    if (i == 0) i = 11;
    if (j == 0) j = 11;
    if (compare(i, j))
        dis = j - i;
    else
        dis = i - j;


    return dis / 3 + dis % 3;

}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10, right = 12;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1) {
            answer += 'L';
            left = numbers[i];
        }
        else if (numbers[i] == 4) {
            answer += 'L';
            left = numbers[i];
        }
        else if (numbers[i] == 7) {
            answer += 'L';
            left = numbers[i];
        }
        else if (numbers[i] == 3) {
            answer += 'R';
            right = numbers[i];
        }
        else if (numbers[i] == 6) {
            answer += 'R';
            right = numbers[i];
        }
        else if (numbers[i] == 9) {
            answer += 'R';
            right = numbers[i];
        }
        else {
            if (compare(distance(left, numbers[i]), distance(right, numbers[i]))) {
                answer += 'L';
                left = numbers[i];
            }
            else if (distance(left, numbers[i]) == distance(right, numbers[i])) {
                if (hand == "left") {
                    answer += 'L';
                    left = numbers[i];
                }
                else {
                    answer += 'R';
                    right = numbers[i];
                }

            }
            else {
                answer += 'R';
                right = numbers[i];
            }
        }


    }
    return answer;
}
int main() {

    cout << solution({1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5}, "right");
    return 0;
}