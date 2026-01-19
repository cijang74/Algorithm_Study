#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
    // vector<int> startProgresses = progresses; // 깊은 복사
    queue<int> q;
    int cnt = 0;
    int startIndex = 0;
    
    // 큐에 각 작업들 넣어놓기
    for(int i = 0; i < progresses.size(); i++)
    {
        q.push(progresses[i]);
    }
    
    // 큐 빌때까지 반복
    while(!q.empty())
    {
        cnt = 0;
        
        for(int i = startIndex; i < progresses.size(); i++)
        {
            // 작업량 증가 시켜가면서
            progresses[i] += speeds[i];

            // 앞놈이 진행률 100%가 넘으면 큐에서 제거, 한번만 수행
            if(progresses[i] >= 100 && startIndex == i)
            {
                q.pop();
                cnt++;
                startIndex++;
            }
        }  
        
        if(cnt != 0)
        {
            answer.push_back(cnt);
        }
    }
    
    return answer;
}