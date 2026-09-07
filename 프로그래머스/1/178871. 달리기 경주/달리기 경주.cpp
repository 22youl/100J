#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<int,string> i1;
    map<string,int> s1;
    
    for(int i=0;i<players.size();i++)
    {
        i1[i] = players[i];
        s1[players[i]] = i;
    }
    for(int j=0;j<callings.size();j++)
    {
        string Sdx = callings[j];
        int Idx = s1[Sdx];
        i1[Idx] = i1[Idx-1];
        i1[Idx-1] = Sdx;
        s1[Sdx] = Idx-1;
        s1[i1[Idx]]=Idx;
    }
    for (auto temp : i1) {
		answer.push_back(temp.second);//m1의 두번째 요소(이름)들을 넣는다.
	}
    return answer;
}