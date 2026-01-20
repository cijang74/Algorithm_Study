#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> sizes) 
{
    int answer = 0;
    int maxX = 0;
    int maxY = 0;

    for(int i = 0; i < sizes.size(); i++)
    {
        // 가로 길이가 세로 길이보다 항상 크도록 바꿔주기
        if(sizes[i][0] < sizes[i][1])
        {
            swap(sizes[i][0], sizes[i][1]);
        }
    }

    // 최대X와 최대Y를 구해서 곱하기
    for(int i = 0; i < sizes.size(); i++)
    {
        if(maxX < sizes[i][0])
        {
            maxX = sizes[i][0];
        }

        if(maxY < sizes[i][1])
        {
            maxY = sizes[i][1];
        }
    }
    
    answer = maxX * maxY;
    return answer;
}