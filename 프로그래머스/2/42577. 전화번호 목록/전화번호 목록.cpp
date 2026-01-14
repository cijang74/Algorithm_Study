#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// phone_book = {"119", "97674223", "1195524421"}
bool solution(vector<string> phone_book) 
{
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());

    // 체이닝 구조 처럼 저장하기위해 unordered_multimap 사용
    unordered_multimap<string, string> m;
    
    // 1. 맨 앞자리 기준으로 인덱스 선정하여 해시 저장
    for(int i = 0; i < phone_book.size(); i++)
    {
        char identify = phone_book[i][0] - '0'; // 1, 9, 1
        
        // 1번째 인덱스에 119, 1196624421등 저장
        m.insert(make_pair(to_string(identify), phone_book[i])); 
    }

    // 2. 0번째 인덱스부터 9번째 인덱스까지 접근하여
    // 연결 리스트 선회하며 접두어 검사
    for(int i = 1; i < 10; i++)
    {
        string currentKey = to_string(i);
        auto range = m.equal_range(currentKey); // key가 "1"인 요소들 범위 가져오기

        // 쓸 데 없는 연산 줄이기 위해 키에 데이터가 하나 이상 있는지 확인 후 진행
        if(range.first != range.second)
        {
            for (auto it = range.first; next(it) != range.second; ++it) // it은 119, 1196624421등..
            {
                // 앞놈의 길이가 더 긴 경우
                if(it->second.size() > next(it)->second.size())
                {
                    // 뒷놈 길이만큼 검사할 것.
                    int check_size = next(it)->second.size();

                    // 뒷놈의 길이만큼 앞놈 앞부분 일치 검사
                    string longString_prefix = it->second.substr(0, check_size);

                    if(next(it)->second.compare(longString_prefix) == 0)
                    {
                        answer = false;
                        cout << answer;
                        return answer;
                    }
                }

                // 뒷놈의 길이가 더 긴 경우
                else if(it->second.size() < next(it)->second.size())
                {
                    // 앞놈 길이만큼 검사할 것.
                    int check_size = it->second.size();

                    // 앞놈의 길이만큼 뒷놈 앞부분 일치 검사
                    string longString_prefix = next(it)->second.substr(0, check_size);
                    
                    if(it->second.compare(longString_prefix) == 0)
                    {
                        answer = false;
                        cout << answer;
                        return answer;
                    }
                }

                // 인접한 두 요소의 길이가 같은경우
                else
                {
                    // 그냥 바로 비교
                    if(it->second.compare(next(it)->second) == 0)
                    {
                        answer = false;
                        cout << answer;
                        return answer;
                    }
                }
            }
        }
    }
    
    cout << answer;
    return answer;
}