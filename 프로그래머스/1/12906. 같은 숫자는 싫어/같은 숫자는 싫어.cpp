#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    queue<int> q;
    int lastNum = -1;
    int currentNum = -1;
    
    // queue에 arr에 있는 값 넣어주기
    for(int i = 0; i < arr.size(); i++)
    {
        q.push(arr[i]);
    }
    
    // 큐 빌때까지 반복
    while(!q.empty())
    {
        // 맨 앞에놈 꺼내고
        currentNum = q.front();
        q.pop();
        
        // 이전 원소와 동일하지 않을때만 answer백터에 집어넣기
        if(currentNum != lastNum)
        {
            answer.push_back(currentNum);
        }
        
        // lastNum 갱신
        lastNum = currentNum;
    }
    
    return answer;
}