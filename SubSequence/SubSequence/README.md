연속된 부분 수열의 합을 찾는 문제
===========
# 해당 문제는 투 포인터 알고리즘을 통해 푸는 문제이다.
해당 문제는 부분 수열 중에서 합이 k이고 길이가 가장 짧은 수열을 찾는 문제이다.
투 포인터 알고리즘이란 두 개의 포인터를 사용하여 문제를 푸는 알고리즘으로, left와 right나 start end 같은 식으로 포인터의 이름을 붙인다.
## 알고리즘
1. sum >=k 혹은 end(left)==N이면 sum에서 sequence[s]를 빼고 나서 s를 증가(s++)
2. 그렇지 않다면 end를 증가(e++)시키고 sum에 sequence[e]를 더한다 
3. sum==k이면 answer = {s,e-1} 여기서 e-1을 하는 이유는 조건문에서 e++를 하기 때문에 sum == k 인 시점은 e++실행되기 전인 e-1인 시점이기 때문이다
4. 또한 그 이후 sum == k일 때 answer보다 길이가 짧다면 새로운 부분 수열을 answer에 집어넣는다.

```C++
vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int sum = 0, s = 0, e = 0;
    while (s < sequence.size()) {
        if (sum >= k || e == sequence.size()) {
            sum -= sequence[s];
            s++;
        }
        else {
            sum += sequence[e];
            e++;
        }
        if (sum == k && answer.empty()) answer = { s,e - 1 };
        else if (sum == k && ((answer[1] - answer[0]) > (e - 1) - s)) answer = { s,e - 1 };
    }

    return answer;
}

```
