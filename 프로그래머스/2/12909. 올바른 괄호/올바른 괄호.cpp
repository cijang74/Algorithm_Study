#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    stack<char> st;
    
    for(int i = 0; i < s.length(); i++)
    {
        // 여는 괄호면 스택에 넣기
        if(s[i] == '(')
        {
            st.push(s[i]);
        }
        
        else if(s[i] == ')')
        {
            // ')'가 나왔는데, 스택이 비어있다는것은 앞에 '('가 없다는 뜻이므로 false
            if(st.empty())
            {
                return false;
            }
            
            else
            {
                st.pop();
            }
        }
    }
    
    // 위 과정이 끝났는데도 스택에 뭔가 남아있으면 올바르지 않은 괄호임
    if(!st.empty())
    {
        return false;
    }
    
    return true;
}