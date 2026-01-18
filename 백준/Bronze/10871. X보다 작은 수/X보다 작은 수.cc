#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    int inputNum;

    // 첫재 줄에 N과 X 주어짐
    cin >> n >> x;

    // 둘째 줄에 수열 입력받음
    for(int i = 0; i < n; i++)
    {
        cin >> inputNum;
        if(inputNum < x)
        {
            cout << inputNum << " ";
        }
    }

    return 0;
}