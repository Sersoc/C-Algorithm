//
//  main.cpp
//  RoughKeyboard
//
//  Created by 이재익 on 2023/04/26.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> key;
    int sum=0;
    int i,j;
    for(i=0;i<keymap.size();i++){
        for(j=0;j<keymap[i].size();j++){
            if(key.find(keymap[i][j])==key.end())
                key.insert({keymap[i][j],j+1});
            else if(key.find(keymap[i][j])!=key.end() && key[keymap[i][j]]>j)
                key[keymap[i][j]] = j+1;
        }
    }
    for(i=0;i<targets.size();i++){
        for(j=0;j<targets[i].size();j++){
            if(key.find(targets[i][j])!=key.end())
                sum += key[targets[i][j]];
            else {
                sum = -1;
                break;
            }
        }
        
        answer.push_back(sum);
        sum = 0;
    }
    return answer;
}
int main(int argc, const char * argv[]) {

    return 0;
}
