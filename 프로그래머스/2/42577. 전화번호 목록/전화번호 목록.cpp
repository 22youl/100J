#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(),phone_book.end());
    for(int i=0;i<phone_book.size()-1;i++)
    {
        int k=0;
        if(phone_book[i].size() > phone_book[i+1].size())
            continue;
        if(phone_book[i][k] != phone_book[i+1][k])
            continue;
        else
        {
            while(true)
            {
                if(phone_book[i].size() != 1)
                    k++;
                if(phone_book[i][k] != phone_book[i+1][k])
                    break;
                if(k == phone_book[i].size()-1)
                {
                    answer = false;
                    return answer;
                }
            }
        }
    }
    return answer;
}