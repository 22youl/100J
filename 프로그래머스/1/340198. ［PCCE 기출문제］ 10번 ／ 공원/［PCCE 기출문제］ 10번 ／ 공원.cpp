#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;
    int max = -1;

    sort(mats.begin(), mats.end(), greater<int>());

    for(int i=0;i<park.size();i++)
    {
        for(int j=0;j<park[0].size();j++)
        {
            int count = 0;
            if(park[i][j] == "-1")
            {
                count++;

                while(i+count < park.size() &&
                      j+count < park[0].size())
                {
                    bool con = true;

                    for(int c=0;c<=count;c++)
                    {
                        for(int d=0;d<=count;d++)
                        {
                            if(park[i+c][j+d] != "-1")
                            {
                                con = false;
                                break;
                            }
                        }

                        if(con == false)
                            break;
                    }

                    if(con == true)
                        count++;
                    else
                        break;
                }
            }

            max = (max > count) ? max : count;
        }
    }

    for(int i=0;i<mats.size();i++)
    {
        if(mats[i] <= max)
            return mats[i];
    }

    return -1;
}