#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> box;
    int mi;
    for (int i = 0; i < moves.size(); i++) {
        mi = moves[i] - 1;
        for (int j = 0; j < board.size(); j++) {

            if (board[j][mi] == 0) continue;
            else {
                if (box.empty() == true) box.push_back(board[j][mi]);
                else if (box.back() == board[j][mi]) {
                    answer += 2;
                    box.pop_back();

                }
                else if (box.back() != board[j][mi])
                    box.push_back(board[j][mi]);
                board[j][mi] = 0;
                break;
            }
        }
    }

    return answer;
}
int main()
{
    cout << solution({ {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} }, {1, 5, 3, 5, 1, 2, 1, 4});

	return 0;
}