#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) 
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    // 우선순위큐에 모든 음식의 스코빌 지수 넣기
    for(int i = 0; i < scoville.size(); i++)
    {
        pq.push(scoville[i]);
    }
    
    // 가장 작은 스코빌지수가 top에 오므로, top만 검사해도 모든 수치가 K를 넘었는지 알 수 있음
    while(pq.top() < K && pq.size() > 1)
    {
        // 가장 작은놈
        int first = pq.top();
        pq.pop();
        
        // 두번째로 작은 놈
        int second = pq.top();
        pq.pop();
        
        // 쓰까서 다시 넣기
        int newThing = first + (second * 2);
        pq.push(newThing);
        
        answer++;
    }
    
    // 마지막 두개 쓰까서 하나만 남았을 때 K를 넘지 못하면 -1 리턴
    if(pq.top() < K)
    {
        return -1;
    }
    
    return answer;
}