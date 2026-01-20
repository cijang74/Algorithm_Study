#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) 
{
    int answer = 1;
    
    // 우선순위로만 큐에 넣으면 추후 loaction을 통해 '특정 프로세스'가 몇 번째로 실행되는지 특정불가
    // 따라서 맨 처음 priorities를 통해 입력받을 때 원래 위치도 함께 쌍으로 저장
    queue<pair<int, int>> q;
    
    for(int i = 0; i < priorities.size(); i++)
    {
        // 큐에 우선순위, 원래 index(식별자)로 저장
        q.push({priorities[i], i});
    }
    
    // 높은 우선순위 먼저 뽑아야 하므로 내림차순 정렬
    sort(priorities.begin(), priorities.end(), greater<>());
    
    int index = 0;
    
    while(!q.empty())
    {
        // 큐 뒤져보면서 우선순위 제일 높은거 찾기
        if(q.front().first == priorities[index])
        {
            // 내가 찾는 특정 위치의 원소라면 그 즉시 리턴
            if(q.front().second == location)
            {
                return answer;
            }
            
            // 아니라면 실행순서 카운트 및 탐색 인덱스 증가
            answer++;
            index++;
        }
        
        // 현재 큐에서 뽑을놈이 우선순위가 제일 높은놈이 아니면 다시 뒤로 보내기
        else if (q.front().first != priorities[index])
        {
            q.push({q.front().first, q.front().second});
        }
        
        // 큐 앞에서 삭제
        q.pop();
    }
    
    return answer;
}