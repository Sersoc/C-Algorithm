추억 점수 문제
===========
# 해당 문제는 일반적인 선형 탐색 알고리즘으로 쉽게 풀 수 있다.
## 다른 방법으로는 MAP<>을 활용해서 키 값을 대응시켜 풀 수 있을 것으로 생각된다. 이는 대충 만든 자판 문제에서 적용한 방법이다.

```C++
vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    int sum = 0;
    int i,j,k;
    for(i=0;i<photo.size();i++){
        for(j=0;j<photo[i].size();j++){
            for(k=0;k<name.size();k++)
                if(photo[i][j] == name[k]){
                    sum += yearning[k];
                }
                    
        }
        answer.push_back(sum);
        sum = 0;
    }
    return answer;
}
```
