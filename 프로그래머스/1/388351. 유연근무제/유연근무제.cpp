#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for(int i=0;i<schedules.size();i++)
    {
        schedules[i] += 10;
        if(schedules[i]%100 >= 60)
        {
            schedules[i] += 40;
        }
    }
    for(int i=0;i<schedules.size();i++)
    {
        bool temp=true;
        for(int days=0;days<7;days++)
        {
            int d=(startday-1+days)%7;
            if(d==5 || d==6)
            {
                continue;
            }
            if(schedules[i] < timelogs[i][days])
            {
                temp=false;
                break;
            }
        }
        if(temp==true)
            answer++;
    }
    return answer;
}