#include <bits/stdc++.h>
using namespace std;

int countingVisitDungeons(int k, vector<vector<int>> dungeons, vector<int> visitOrderdungeon)
{
    int health = k;
    int cnt = 0;

    for(int i = 0; i < visitOrderdungeon.size(); i++)
    {
        // 최소 피로도 이상인지 체크
        if(health >= dungeons[visitOrderdungeon[i]][0])
        {
            // 피로도 소모시키고 카운트 증가
            health -= dungeons[visitOrderdungeon[i]][1];
            cnt++;
        }
    }

    return cnt;
}

int solution(int k, vector<vector<int>> dungeons) 
{
    int answer = -1;
    vector<int> dungeonIndex; // 던전 인덱스로 사용할 배열
    vector<int> visitOrderdungeon; // 방문 순서 저장용 배열

    // v에 1번 던전, 2번 던전, 3번 던전... 을 가르키는 인덱스 저장
    for(int i = 0; i < dungeons.size(); i++)
    {
        dungeonIndex.push_back(i);
    }

    // next_permutation 메서드 사용하기 위해 정렬
    sort(dungeonIndex.begin(), dungeonIndex.end());

    // 순열 뽑기 (이캠 참고)
    do 
    {
        for (auto &it : dungeonIndex)
        {
            // 순열을 visitOrderdungeon에 차곡차곡 저장
            visitOrderdungeon.push_back(it);
        }

        // 던전 방문하며 카운트 기록
        int temp = countingVisitDungeons(k, dungeons, visitOrderdungeon);

        // 카운트가 기존 기록보다 더 높으면 업데이트
        if(answer < temp)
        {
            answer = temp;
        }

        visitOrderdungeon.clear();
    } while(next_permutation(dungeonIndex.begin(), dungeonIndex.end()));
    
    return answer;
}