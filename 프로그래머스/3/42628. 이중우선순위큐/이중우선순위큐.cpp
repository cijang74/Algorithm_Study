#include <bits/stdc++.h>
using namespace std;

void checkIsNumReal(priority_queue<int, vector<int>, greater<int>> &queue, unordered_map<int, int> &cnt)
{
    while (!queue.empty() && cnt[queue.top()] == 0)
    {
        queue.pop();
    }
}

void checkIsNumReal(priority_queue<int, vector<int>, less<int>> &queue, unordered_map<int, int> &cnt)
{
    while (!queue.empty() && cnt[queue.top()] == 0)
    {
        queue.pop();
    }
}

vector<int> solution(vector<string> operations) 
{
    vector<int> answer;
    
    priority_queue<int, vector<int>, greater<int>> pq_min; // 최솟값 연산 수행할 큐
    priority_queue<int, vector<int>, less<int>> pq_max; // 최댓값 연산 수행할 큐

    unordered_map<int, int> cnt; // 삽입한 각 숫자들의 개수 체킹용 해시

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < operations.size(); i++)
    {
        string operation = operations[i];

        if(operation == "D 1")
        {
            // 현재 큐에있는 최대값 확인하며 큐에 실제로 존재하는 값이 아닌것들 삭제
            checkIsNumReal(pq_max, cnt);
            
            if(!pq_max.empty())
            {
                cnt[pq_max.top()]--;
                pq_max.pop();
            }
        }
        
        else if(operation == "D -1")
        {
            // 현재 큐에있는 최소값 확인하며 큐에 실제로 존재하는 값이 아닌것들 삭제
            checkIsNumReal(pq_min, cnt);
            
            if(!pq_min.empty())
            {
                cnt[pq_min.top()]--;
                pq_min.pop();
            }
        }
        
        else if(operation[0] == 'I')
        {
            // 큐에 숫자 삽입 연산 수행
            operation.erase(0, 1);
            int number = stoi(operation);
            
            // 백터, 큐에 새로운 숫자 삽입
            pq_min.push(number);
            pq_max.push(number);

            cnt[number]++;
        }
    }

    // 마지막으로 다시 한번 존재하지 않는 값 체크
    checkIsNumReal(pq_min, cnt);
    checkIsNumReal(pq_max, cnt);
    
    if(pq_min.empty() && pq_max.empty())
    {
        answer = {0, 0};
    }
    
    else
    {
        int max = pq_max.top();
        int min = pq_min.top();
        answer = {max, min};
    }

    return answer;
}