#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v(10);
    int max = 0;

    string number;
    cin >> number;

    // 문자열 체크하면서 각 숫자 별 필요 수 체크
    for(int i = 0; i < number.length(); i++)
    {
        // 6이나 9는 동일하게 취급하기 위해 6번째 인덱스에 다 짬때리기
        if((int)number[i] - 48 == 6 || (int)number[i] - 48 == 9)
        {
            v[6] += 1;
        }

        else
        {
            v[(int)number[i] - 48] += 1;
        }
    }

    // 6번째 인덱스 / 2 해주고 올림 처리
    if(v[6] != 0)
    {
        // 개수가 홀수일경우 (ex. 1, 3, 5)
        if(v[6] % 2 != 0)
        {
            v[6] = (v[6] / 2) + 1;
        }

        else
        {
            v[6] = (v[6] / 2);
        }
    }

    // 각 숫자 별 필요 수량 체크 리스트 확인하며 제일 많이 필요한 숫자의 개수 확인
    for(int i = 0; i < v.size(); i++)
    {
        if(max < v[i])
        {
            max = v[i];
        }
    }

    cout << max;
}