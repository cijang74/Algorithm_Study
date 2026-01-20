#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int brown, int yellow) 
{
    vector<int> answer;
    
    // 카펫 전체 넓이는 brown + yellow
    int entireSize = brown + yellow;

    // 세로 길이는 무조건 최소 3부터 시작해야 함 (세로가 무조건 가로보다 짧으니까 절반까지만 확인하면 됨)
    for(int i = 3; i < (int)sqrt(entireSize) + 1; i++)
    {
        if(entireSize % i == 0)
        {
            int y = i;
            int x = entireSize / i;

            // 찾아낸 가로-세로 쌍으로 만든 카펫의 노란색 넓이가 실제 노란색, 갈색 개수와 동일한지 체크해야 함 (24-24 케이스 참고.)
            // 노란색 부분의 전체 넓이는 (가로길이 - 2 * 세로길이 -2)
            if(yellow == (x - 2) * (y - 2) && x * y - yellow == brown)
            {
                // x, y 순서대로 넣기
                answer.push_back(x);
                answer.push_back(y);
            }
        }
    }
    return answer;
}
