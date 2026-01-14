#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


string solution(vector<string> participant, vector<string> completion) 
{
    string answer;

    // 동명이인 있을 수 있으므로 체이닝 구조 처럼 저장하기위해 unordered_multimap 사용
    unordered_multimap<string, bool> m;
    
    // 참가자 배열 참고하여 해시 초기화
    for(int i = 0; i < participant.size(); i++) // i < 3
    {
        // key값 leo, value값 true처럼 초기화
        string key = participant[i]; // key = leo
        m.insert(make_pair(key, false));
    }
    
    // 완주자 배열 참고하여 해시 값 업데이트
    for(int i = 0; i < completion.size(); i++) // i < 3
    {
        string key = completion[i];

        // 해시에서 completion[i]를 key값으로 가지고있는 항목 찾기위해 이터레이터 사용
        auto it = m.find(key);

        // 해시에 해당 항목이 실제 존재하는지 체크
        if(it != m.end())
        {
            m.erase(it);
        }
    }
    
    // 완주하지 못한 인물을 출력
    answer = m.begin()->first;
    cout << answer << endl;
    return answer;
}