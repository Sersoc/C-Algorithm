
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
