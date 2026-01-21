#include <bits/stdc++.h>
using namespace std;

// 작업 구조체
struct Job
{
    int requestTime; // 요청시간
    int duration; // 소요시간
    Job(int REQUESTTIME, int DURATION) : requestTime(REQUESTTIME), duration(DURATION) {}
};

// 우선순위 비교를 위한 구조체
struct cmp
{
    bool operator()(Job &a, Job &b)
    {
        // 1순위는 소요시간임
        if(a.duration != b.duration)
        {
            return a.duration > b.duration;
        }

        // 2순위는 요청시간임
        else
        {
            return a.requestTime > b.requestTime;
        }
    }
};

int solution(vector<vector<int>> jobs) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int answer = 0;
    int currentTime = 0;
    int HDDActivateTime = 0;
    bool isHDDUsing = false;

    priority_queue<Job, vector<Job>, cmp> pq;
    unordered_multimap<int, int> m; // key로 요청시간, value로 해당 요청시간을 가진 jbos의 index를 저장
    int turnAroundChecker = 0;
    int jobsNum = jobs.size();
    int clearJobsCount = 0;

    // 요청시간, index 해시 세팅
    for(int i = 0; i < jobs.size(); i++)
    {
        m.insert(make_pair(jobs[i][0], i));
    }

    while(clearJobsCount < jobsNum)
    {
        if(isHDDUsing && currentTime == HDDActivateTime)
        {
            isHDDUsing = false;
            clearJobsCount++;
        }

        // 1. 요청시간이 현재 시간인 작업 대기큐에 삽입
        auto range = m.equal_range(currentTime);

        for(auto it = range.first; it != range.second; ++it)
        {
            // it->second가 요청시간이 현재 시간인 작업의 index임.
            // 요청시간, 소요시간 순으로 우선순위 큐에 삽입
            pq.push(Job(jobs[it->second][0], jobs[it->second][1]));
        }

        // 2. 하드 사용중이 아니면서 대기큐에 대기중인 작업들이 있으면 작업 수행
        if(!isHDDUsing && !pq.empty())
        {
            // 현재 수행할 작업
            Job currentJob = pq.top();
            pq.pop();

            isHDDUsing = true;
            HDDActivateTime = currentTime + currentJob.duration;
            turnAroundChecker += HDDActivateTime - currentJob.requestTime;
        }
        currentTime++;
    }
    
    answer = (int)turnAroundChecker/jobsNum;
    // cout << answer;
    return answer;
}