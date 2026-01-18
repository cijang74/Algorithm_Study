#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    char a = 'a';
    char z = 'z';

    int start = (int)a;
    int end = (int)z;
    
    for(int i = start; i <= end; i++)
    {
        int cnt = 0;

        for(int j = 0; j < s.length(); j++)
        {
            char check_char = s[j];
            int check_int = (int)check_char;
            
            if(check_int == i)
            {
                cnt ++;
            }
        }

        cout << cnt << " ";
    }
}