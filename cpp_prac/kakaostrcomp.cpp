#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.size();
    int limit=s.size()/2;
    for(int i=1; i<=limit; i++)
    {
        string prev=s.substr(0,i);
        int temp=0;
        int count=1;
        int j;
        for(j=i; j<=s.size()-i; j+=i)
        {
            if(prev==s.substr(j,i)) count++;
            else
            {
                if(count!=1)
                {
                    while(count!=0)
                    {
                        temp++;
                        count/=10;
                    }  
                }  
                temp+=prev.size();
                prev=s.substr(j,i);
                count=1;
            }
        }
        if(count==1) temp+= (s.substr(j-i)).size();
        else
        {
            while(count!=0)
            {
                temp++;
                count/=10;
            }
            temp+=prev.size();
            if(j<s.size()) temp+=(s.substr(j)).size();
        }
        if(temp<answer) answer=temp;
    }
    
    return answer;
}