#include <string>
#include <cctype>
#include <vector>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> buck1;
    vector<string> buck2;
    for(int i=0; i<str1.size()-1; i++)
    {
        if(isalpha(str1[i])&&isalpha(str1[i+1]))
        {
            string temp;
            temp.push_back(tolower(str1[i]));
            temp.push_back(tolower(str1[i+1]));
            buck1.push_back(temp);
        }
    }
    
    for(int i=0; i<str2.size()-1; i++)
    {
        if(isalpha(str2[i])&&isalpha(str2[i+1]))
        {
            string temp;
            temp.push_back(tolower(str2[i]));
            temp.push_back(tolower(str2[i+1]));
            buck2.push_back(temp);
        }
    }
    if(buck1.size()==0 && buck2.size()==0) return 65536;
    
    int common=0;
    int sum=buck1.size()+buck2.size();
    for(int i=0; i<buck1.size(); i++)
    {
        for(int j=0; j<buck2.size(); j++)
        {
            if(buck1[i]==buck2[j])
            {
                common++;
                buck2.erase(buck2.begin()+j);
                break;
            }
        }
    }
    sum-=common;
    answer= common*65536/sum;
    
    return answer;
}