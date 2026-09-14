#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> o;
    for(auto player : participant)
    {
        if(o.end() == o.find(player))
        {
            o.insert(make_pair(player,1));
        }
        else
            o[player]++;
    }
    for(auto player : completion)
    {
        o[player]--;
    }
    for(auto player : participant)
    {
        if(o[player] > 0)
        {
            answer = player;
            break;
        }
    }
    return answer;
}