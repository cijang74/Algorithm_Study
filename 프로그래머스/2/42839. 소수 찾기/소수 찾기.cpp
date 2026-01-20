#include <bits/stdc++.h>
using namespace std;

// 제곱근 판별 함수
bool checkPrimeNum(int n)
{
    // 0과 1 제외
    if(n == 0 || n == 1)
    {
        return false;
    }

    // 나눠지는 수가 있는지 제곱근까지 확인
    for(int i = 2; i < (int)sqrt(n) + 1; i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int solution(string numbers) 
{
    int answer = 0;

    // 11과 011같은 중복값 피하기 위해 Set 사용
    set<int> numSet;

    // next_permutation는 사전순으로 작동하므로 정렬된 상태에서 해야 함
    sort(numbers.begin(), numbers.end());

    int r = 0;
    int size = numbers.length();

    // 모든 자리수의 순열 구하기 (이캠퍼스 블로그 참고)
    while(r <= size)
    {
        sort(numbers.begin(), numbers.end());
        do 
        {
            string s = "";
            for (int i = 0; i < r; i++)
            {
                s += numbers[i];
            }

            if(s != "") // 맨 처음 r = 0일 때 ""를 stoi하지 않도록 제어
            {
                numSet.insert(stoi(s));
            }

            reverse(numbers.begin() + r, numbers.end()); // 중복제거
        } while(next_permutation(numbers.begin(), numbers.end()));
        r++;
    }

    for(int i : numSet)
    {
        if(checkPrimeNum(i))
        {
            answer++;
        }
    }

    return answer;
}