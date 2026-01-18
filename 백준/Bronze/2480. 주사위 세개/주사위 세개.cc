#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v;
    int inputNum;
    int cnt = 0;
    int same = 0;
    int max = 0;
    int cash = 0;

    for(int i = 0; i < 3; i++)
    {
        cin >> inputNum;
        if(max < inputNum)
        {
            max = inputNum;
        }
        v.push_back(inputNum);
    }

    for(int i = 0; i < 2; i++)
    {
        for(int j = i + 1; j < 3; j++)
        {
            if(v[i] == v[j])
            {
                cnt++;
                same = v[i];
            }
        }
    }

    if(cnt == 3)
    {
        cash = 10000 + (same * 1000);
    }

    else if(cnt == 1)
    {
        cash = 1000 + (same * 100);
    }

    else
    {
        cash = max * 100;
    }

    cout << cash;
}