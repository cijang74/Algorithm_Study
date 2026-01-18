#include <bits/stdc++.h>

using namespace std;

int main()
{
    int inputNum;
    vector<int> v;

    for(int i = 0; i < 3; i++)
    {
        cin >> inputNum;
        v.push_back(inputNum);
    }

    sort(v.begin(), v.end());
    
    for(int i = 0; i < 3; i++)
    {
        cout << v[i] << " ";
    }
}