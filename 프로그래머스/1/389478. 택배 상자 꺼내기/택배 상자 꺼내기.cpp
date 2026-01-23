#include <bits/stdc++.h>
using namespace std;

int answer = 0;

int solution(int n, int w, int num) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_multimap<int, int> m; // key값으로 인덱스, value값으로 해당 인덱스에 정리되어있는 박스의 숫자
    int countOfBoxes = 1;
    int targetIndex = 0;
    bool isStackingEnd = false;

    // 박스 정리 과정
    while(countOfBoxes <= n)
    {
        // 먼저 왼쪽에서 오른쪽으로 쌓기
        for(int i = 0; i < w; i++)
        {
            if(!isStackingEnd)
            {
                m.insert(make_pair(i, countOfBoxes));
                countOfBoxes++;
            }

            if(countOfBoxes > n)
            {
                isStackingEnd = true;
                break;
            }
        }

        // 이후에는 다시 오른쪽에서 왼쪽으로 쌓기
        for(int i = w - 1; i > -1; i--)
        {
            if(!isStackingEnd)
            {
                m.insert(make_pair(i, countOfBoxes));
                countOfBoxes++;
            }

            if(countOfBoxes > n)
            {
                isStackingEnd = true;
                break;
            }
        }
    }

    // 박스 찾기 과정
    for(int i = 0; i < w; i++)
    {
        auto range = m.equal_range(i);

        for(auto it = range.first; it != range.second; ++it)
        {
            if(it->second == num)
            {
                targetIndex = i;
                cout << "targetIndex: " << targetIndex << endl;
            }
        }
    }

    // 찾으려는 박스 위에있는 박스들 개수 찾기 과정
    auto range = m.equal_range(targetIndex);

    for(auto it = range.first; it != range.second; ++it)
    {
        if(it->second > num)
        {
            cout << "위에 있는 상자: " << it->second << endl;
            answer++;
        }
    }

    answer += 1; // 마지막 자기 자신까지 합산
    return answer;
}