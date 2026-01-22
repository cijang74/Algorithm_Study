#include <bits/stdc++.h>
using namespace std;

vector<int> answer;

int basicMinutes;
int basicFee;
int unitMinutes;
int unitFee;

struct Car
{
    bool isInPark = false;
    string enterTime;
    string outTime;
    int totalMinutes = 0;
    int resultFee = 0;
    
    Car() {}
};

vector<string> splitStringWithSpace(string s)
{
    string str = s;
    stringstream ss(str);

    string word;
    vector<string> words;

    while(getline(ss, word, ' '))
    {
        words.push_back(word);
    }

    return words;
}

int calculateParkingMinutes(string enterTime, string outTime)
{
    int minuets = 0;

    // enterTime 혹은 outTime의 양식: "05:34"
    int H1 = stoi(enterTime.substr(0, 2));
    int M1 = stoi(enterTime.substr(3, 2));

    int H2 = stoi(outTime.substr(0, 2));
    int M2 = stoi(outTime.substr(3, 2));

    if(M1 > M2)
    {
        // ex) 0148 차량의 07:59 ~ 19:09
        minuets = (H2 - H1 - 1) * 60 + (60 - M1) + M2;
    }

    else if(M1 < M2)
    {
        // ex) 5961 차량의 05:34 ~ 07:59        
        minuets = (H2 - H1) * 60 + (M2 - M1);
    }

    // M1 == M2
    else
    {
        // ex) 0000차량의 18:59 ~ 23:59
        minuets = (H2 - H1) * 60;
    }

    // minutes: 이번 입차-출차 과정에서의 체류 시간
    return minuets;
}

// 총 체류 minutes 기준으로 요금 계산
int calculateParkingFee(int totalMinutes)
{
    int extraFee = 0;
    int result = 0;

    if(totalMinutes > basicMinutes)
    {
        // 그냥 int형으로 계산하여 올림하려고 하면 안됨. int/int가 실수가 나온다고 해도, 실수가 나오는 것 자체를 허용을 안하고 소수점 뒤 숫자를 버려버림.
        extraFee += ceil(((float)totalMinutes - (float)basicMinutes)/(float)unitMinutes) * unitFee;
    }
    
    result = basicFee + extraFee;

    return result;
}

// fees: [180, 5000, 10, 600]
// records: ["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", 
// "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"]
vector<int> solution(vector<int> fees, vector<string> records) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    set<string> carNumbers;
    set<string>::iterator iter;

    // 1. fees를 기준으로 현재 코드에서 사용할 기본 시간, 기본 요금, 단위 시간, 단위 요금 세팅
    basicMinutes = fees[0];
    basicFee = fees[1];
    unitMinutes = fees[2];
    unitFee = fees[3];

    // 2. records를 기준으로 [차량번호]-[해당 자동차의 정보 구조체] 구조의 해시 생성
    unordered_map<string, Car> m;
    for(int i = 0; i < records.size(); i++)
    {
        // records[0] = "05:34 5961 IN"
        // words = {"05:34", "5961", "IN"}
        vector<string> words = splitStringWithSpace(records[i]);

        // 입차라면
        if(words[2] == "IN")
        {
            m.insert({words[1], Car()});
            carNumbers.insert(words[1]);

            m[words[1]].isInPark = true;
            m[words[1]].enterTime = words[0];
        }

        // 출차라면
        else if(words[2] == "OUT")
        {
            m[words[1]].isInPark = false;
            m[words[1]].outTime = words[0];
            m[words[1]].totalMinutes += calculateParkingMinutes(m[words[1]].enterTime, m[words[1]].outTime);
        }
    }

    // 3. 중복을 거르고 저장해놓은 자동차 번호들을 가진 carNumbers를 기준으로 낮은 번호 순 정렬 (set은 이미 정렬되어 있음)
    for(iter = carNumbers.begin(); iter != carNumbers.end(); iter++)
    {
        string index = *iter;

        // 마지막 계산 시 아직 주차장에 있다고 판단된 차들은 23:59에 출차된 것으로 간주
        if(m[index].isInPark)
        {
            m[index].isInPark = false;
            m[index].outTime = "23:59";
            m[index].totalMinutes += calculateParkingMinutes(m[index].enterTime, m[index].outTime);
        }

        // 요금 계산
        m[index].resultFee = calculateParkingFee(m[index].totalMinutes);
        answer.push_back(m[index].resultFee);
    }

    return answer;
}