#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) 
{
    vector<int> answer(prices.size());
    stack<int> st; // 가격이 아직 떨어지지 않은 원소의 인덱스를 저장
    
    for(int i = 0; i < prices.size(); i++)
    {
        // 스택이 비어있지 않고 스택 최상단 인덱스의 원소가 현재 가격보다 높다 == 가격이 떨어진 것
        while(!st.empty() && prices[st.top()] > prices[i])
        {
            int index = st.top();
            answer[index] = i - index; // 현재 index - 가격이 떨어지지 않았던 최근 index == 버틴시간
            st.pop(); // 계산이 완료된 요소는 stack에서 제거
        }
        
        // 현재 시점 인덱스 stack에 넣기
        st.push(i);
    }
    
    // 남아있는 스택 원소들은 끝까지 가격이 떨어지지 않은 경우임.
    while(!st.empty())
    {
        int index = st.top();
        st.pop();
        answer[index] = ((prices.size() - 1) - index);
    }
    
    return answer;
}