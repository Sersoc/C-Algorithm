//
//  main.cpp
//  WalkInThePark
//
//  Created by 이재익 on 2023/04/26.
//

#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

using namespace::std;
// section_len은 배열 section의 길이입니다.
int solution(int n, int m, int section[], size_t section_len) {
    int answer = 0;
    int x = section_len-1, y = 0, i;
    
    y = section[x] - m;
    answer++;
        for(i=x;i>=0;i--){
            if(section[i] <= y){
                x = i;
                y = section[x] - m;
                answer++;
                continue;
            }
            else if(i>0) continue;
            else if(i=0&&section[i]<=y){
                answer++;
                x = 0;
                return answer;
            };
            
        }
    return answer;
}int main(int argc, const char * argv[]) {
    // insert code here...
    int a[2] = {1,3};
    int b[4] = {1,2,3,4};
    int c[3] = {2,3,6};
    cout << solution(5, 4,a, 2);
    return 0;
}
