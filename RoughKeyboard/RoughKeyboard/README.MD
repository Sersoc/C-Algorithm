대충 만든 자판 문제
===============

## 앞서 풀었던 추억 점수 문제와 비슷한 문제이다. 앞서 풀었던 문제는 선형 탐색 알고리즘으로 풀었다면, 이번에는 MAP<>을 활용항 키 값을 대응시켜 값을 찾는 방식으로 문제를 풀었다.

```C++
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
```
