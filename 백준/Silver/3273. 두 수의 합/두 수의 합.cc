#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v (2000000);
    int n, inputNum, x;
    int cnt = 0;
    
    cin >> n;
    
    vector<int> inputVector;

    // 수열 입력
    for(int i = 0; i < n; i++)
    {
        cin >> inputNum;
        inputVector.push_back(inputNum);
    }

    cin >> x;

    // 입력받은 수열 돌면서 체크리스트 확인
    for(int i = 0; i < n; i++)
    {
        // 현재 채킹중인 수는 x보다 무조건 작아야 함.
        if(inputVector[i] < x)
        {
            // 체크리스트에 존재하는것이 확인되었으면 카운트 증가
            if(v[x - inputVector[i]] == 1)
            {
                cnt++;
            }
        }
        
        v[inputVector[i]] = 1;
    }

    cout << cnt;
}