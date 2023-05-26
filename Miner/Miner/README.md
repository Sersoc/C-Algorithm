일을 했을 때 최소한의 피로도를 구하는 문제
===========
# 해당 문제는 탐욕 알고리즘을 통해 푸는 문제이다.
곡괭이에 따라 광물을 캐는 피로도가 다른데 이를 가장 적은 피로도로 캤을 때의 피로도를 구하는 문제이다.
https://school.programmers.co.kr/learn/courses/30/lessons/172927
![image](https://github.com/Sersoc/C-Algorithm/assets/45021157/6a0a1688-732e-4ca7-acf5-605c8772dd34)

탐욕 알고리즘이란 현재 시점에서 최적의 결과만을 골라 최종적인 답을 도출하는 알고리즘이다.
해당 문제가 탐욕 알고리즘이 되는 이유는 5개의 광물 묶음의 피로도 합을 돌 곡괭이로 팠을 때로 가정하여 구한 후 정렬하면, 
당연히 가장 피로도가 큰 광물 묶음은 다이야 곡괭이로 캐야 한다. 이렇게 정렬된 피로도를 최적의 곡괭이로 파다 보면 가장 적은 피로도가 나오게 된다.
## 알고리즘
1. minerals[n] == "diamond" 일 때 sum += 25, "iron" 일 때 +=5 나머지는 +=1
2. n++, t++ 해가면서 minerals.size() > n && pick_sum * 5 > n을 만족할 때 까지 반복한다.
3. vector<vector<int>> fatigue를 오름차순 정렬 후 뒤에서 부터 확인하여 answer에 피로도를 추가한다.
4. 다이야 곡괭이(picks[0])가 !=0 이면 t(묶음 갯수) 값을 추가
5. 철 곡괭이(picks[1])가 !=0 이면 sum/5 + sum%5 값을 추가
6. 마지막으로 돌 곡괭이는 그냥 값을 추가한다.

## 예외
1. 철 곡괭이로 광물을 캘 시 묶음이 {"iron"}과 {"stone","stone","stone","stone","stone"} 는 5로 돌곡괭이로 팠을 때 피로도가 같다. 하지만 철 곡괭이 피로도는 1과 5로 차이가 나기 때문에t(묶음 갯수)로 구분하여 answer에 추가한다.
2. 또한 다이야 곡괭이로 캐면 다 피로도가 1이어서 상관 없지만, { "diamond"} 와 {"iron", "iron","iron", "iron","iron"} 도 똑같이 위 처럼 돌 곡괭이 피로도는 25로 같지만, 다이야 곡괭이 피로도는 1과 5로 다르기 때문에 t값을 추가해주면 문제가 발생하지 않는다.

```C++
int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    int pick_sum = 0;
    int sum = 0, mineral;
    vector<int> ft;
    vector<vector<int>> fatigue;
    for (int i = 0; i < picks.size(); i++) {
        pick_sum += picks[i];
    }

    int n = 0, t = 1;
    while (minerals.size() > n && pick_sum * 5 > n) {

        if (minerals[n] == "diamond")
            mineral = 25;
        else if (minerals[n] == "iron")
            mineral = 5;
        else mineral = 1;

        sum += mineral;

        if (n == minerals.size() - 1) {
            fatigue.push_back({ sum,t });
            break;
        }
        if (t == 5) {
            fatigue.push_back({ sum,t });
            t = 1;
            n++;
            sum = 0;
            continue;
        }
        n++;
        t++;
    }
    sort(fatigue.begin(), fatigue.end());
    while (!fatigue.empty()) {
        ft = fatigue.back();
        fatigue.pop_back();
        if (picks[0] != 0) {
            answer += ft[1];
            picks[0]--;
        }
        else if (picks[1] != 0) {
            if (ft[0] == 5)
                answer += ft[1];
            else
                answer += ft[0] / 5 + ft[0] % 5;
            picks[1]--;

        }
        else {
            answer += ft[0];
            picks[2]--;
        }
    }

    return answer;
}

```