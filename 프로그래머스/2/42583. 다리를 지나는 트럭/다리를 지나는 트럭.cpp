#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    int answer = 0;
    int currentWeight = 0;
    
    queue<int> q; // 다리를 건너는 트럭으로 사용할 큐
    
    // 맨 처음 큐를 다리에 올라갈 수 있는 트럭 수 만큼 초기화
    for(int i = 0; i < bridge_length; i++)
    {
        q.push(0); // 0은 비어있다는 의미
    }
    
    int index = 0;
    
    // 대기트럭의 수 만큼 반복
    while(index < truck_weights.size())
    {
        answer++;
        
        // 큐의 맨 앞 요소 빠져나오게 하기
        currentWeight -= q.front();
        q.pop();
        
        // 추가할 트럭의 무게가 현재 다리 위 트럭들의 무게 총합과 합쳐졌을 떄 무게 리미트 넘는지 체크
        int nextWeight = truck_weights[index];
        if(currentWeight + nextWeight <= weight)
        {
            // 큐에 추가해주고 인덱스 증가
            q.push(nextWeight);
            currentWeight += nextWeight;
            index++;
        }
        
        // 리미트 넘으면
        else if(currentWeight + nextWeight > weight)
        {
            q.push(0);
        }
    }
    
    // 마지막 트럭이 큐에 넣어 진 순간 반복문 종료되므로 마지막 트럭은 따로 합산
    // bridge_length만큼 시간이 경과할 것이므로 합산
    answer += bridge_length;
    
    return answer;
}