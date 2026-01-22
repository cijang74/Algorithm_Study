#include <bits/stdc++.h>
using namespace std;

struct User
{
    string userID;
    vector<string> reportList;
    int killCount = 0;
    User() {}
    User(string USERID) : userID(USERID) {}
};

vector<int> answer;

vector<int> solution(vector<string> id_list, vector<string> report, int k) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    unordered_map<string, User> serchHash;
    unordered_multimap<string, string> countHash;
    set<string> deathUsers;
    set<string>::iterator iter;
    
    // 2. id_list의 길이만큼 user 변수를 생성하고, 유저 ID를 입력받아 초기화
    for(int i = 0; i < id_list.size(); i++)
    {
        // 키값으로 유저 ID, 벨류값으로 user변수
        serchHash[id_list[i]] = User(id_list[i]);
    }
    
    // 리포트 요청들 수행
    for(int i = 0; i < report.size(); i++)
    {
        string str = report[i];
        stringstream ss(str);
        
        string word;
        vector<string> words; // words[0]은 신고한 사람, words[1]은 신고 당한사람
        
        // 공백 기준으로 나누기
        while(getline(ss, word, ' '))
        {
            words.push_back(word);
        }
        
        auto range = countHash.equal_range(words[1]);
        bool flag = false;
        
        // 문제점: 유저가 데이터 처음으로 신고당하면 루프는 실행되지 않음
        for(auto it = range.first; it != range.second; ++it)
        {
            // 신고 당한 유저의 카운트 목록에 이미 신고한 유저 신고 내역이 존재한다면
            if(it->second == words[0] && !flag)
            {
                // 이놈 중복신고 했구나
                flag = true;
            }
        }
        
        // 중복신고가 아니라면 
        if(!flag)
        {
            // 카운트용 해시에 키값으로 신고당한 유저, 벨류값으로 신고한 유저 저장
            countHash.insert(make_pair(words[1], words[0]));
            serchHash[words[0]].reportList.push_back(words[1]);
        }
        
        // count 해시 돌면서 신고횟수가 k번 이상이면 처형 목록 리스트에 추가
        int count = 0;
        range = countHash.equal_range(words[1]);

        for(auto it = range.first; it != range.second; ++it)
        {
            count++;
        }
        
        if(count == k)
        {
            deathUsers.insert(words[1]);
        }
    }
    
    // 반복문 돌리면서 해시 접근
    for(int i = 0; i < id_list.size(); i++)
    {
        User currentUser = serchHash[id_list[i]];
        
        int count = 0;

        for(int j = 0; j < currentUser.reportList.size(); j++)
        {
            iter = deathUsers.find(currentUser.reportList[j]);
            if(iter != deathUsers.end())
            {
                count++;
            }
        }
        answer.push_back(count);
    }
    
    return answer;
}