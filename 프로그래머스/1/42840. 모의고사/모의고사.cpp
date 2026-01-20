#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> answers) 
{
    vector<int> result; // 문제의 정답
    vector<int> v; // 수포자가 제출한 정답
    vector<int> h; // 각 수포자 별 문제 찍는 유형
    vector<int> cnt(3); // 각 수포자가 맞춘 문제 개수
    
    // 1번 수포자
    h = {1, 2, 3, 4, 5};
    while(v.size() < 10000)
    {
        v.insert(v.end(), h.begin(), h.end());
    }
    
    for(int i = 0; i < answers.size(); i++)
    {
        // 정답 체크
        if(answers[i] == v[i])
        {
            cnt[0]++;
        }
    }
    v.clear();
    
    // 2번 수포자
    h = {2, 1, 2, 3, 2, 4, 2, 5};
    while(v.size() < 10000)
    {
        v.insert(v.end(), h.begin(), h.end());
    }
    
    for(int i = 0; i < answers.size(); i++)
    {
        // 정답 체크
        if(answers[i] == v[i])
        {
            cnt[1]++;
        }
    }
    v.clear();
    
    // 3번 수포자
    h = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    while(v.size() < 10000)
    {
        v.insert(v.end(), h.begin(), h.end());
    }
    
    for(int i = 0; i < answers.size(); i++)
    {
        // 정답 체크
        if(answers[i] == v[i])
        {
            cnt[2]++;
        }
    }
    
    int max = -1;
    
    // 맞춘 사람 중 제일 많이 맞춘 사람 체크
    for(int i = 0; i < cnt.size(); i++)
    {
        if(max < cnt[i])
        {
            max = cnt[i];
        }
    }
    
    for(int i = 0; i < cnt.size(); i++)
    {
        if(max == cnt[i])
        {
            result.push_back(i+1);
        }
    }
    
    return result;
}