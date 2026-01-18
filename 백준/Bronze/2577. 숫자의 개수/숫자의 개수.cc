#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v(10);
    int a, b, c;
    string result;

    cin >> a >> b >> c;
    result = to_string(a * b * c);

    for(int i = 0; i < result.length(); i++)
    {
        v[(int)result[i] - 48] += 1;
    }

    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\n";
    }
}