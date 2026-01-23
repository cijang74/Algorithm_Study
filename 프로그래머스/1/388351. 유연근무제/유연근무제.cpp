#include <bits/stdc++.h>
using namespace std;

int answer = 0;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    set<int> s;
    
    for(int i = 0; i < schedules.size(); i++)
    {
        int count = startday;
        int currentTime = 0;;
        
        for(int j = 0; j < timelogs[i].size(); j++)
        {
            if(count % 7 == 6 || count % 7 == 0)
            {
                count++;
                continue;
            }

            // 지각했으면
            if((schedules[i] + 10) % 100 >= 60)
            {
                currentTime = schedules[i] + 10;

                currentTime += 100; 
                currentTime -= 60;
            }

            else
            {
                currentTime = schedules[i] + 10;
            }

            if(currentTime < timelogs[i][j]) // 여기서 인덱스 뻑나는데.
            {
                // set에 집어넣기
                s.insert(i);
            }
            count++;
        }
    }

    // 전체 인원수 - 지각인원수
    answer = schedules.size() - s.size();
    return answer;
}