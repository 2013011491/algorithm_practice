#include <string>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int dartlen=dartResult.size();
    vector<int> numstack;
    for(int i=0; i<dartlen; i++)
    {
        if(dartResult[i]=='S') continue;
        else if(dartResult[i]=='D') numstack[numstack.size()-1]*=numstack[numstack.size()-1];
        else if(dartResult[i]=='T') numstack[numstack.size()-1]=numstack[numstack.size()-1]*numstack[numstack.size()-1]*numstack[numstack.size()-1];
        else if(dartResult[i]=='*')
        {
            numstack[numstack.size()-1]*=2;
            if(numstack.size()!=1) numstack[numstack.size()-2]*=2;
        }else if(dartResult[i]=='#')
        {
            numstack[numstack.size()-1]*=(-1);
        }else if(dartResult[i]=='1')
        {
            if(dartResult[i+1]=='0')
            {
                numstack.push_back(10);
                i++;
            }else numstack.push_back(1);
        }
        else
        {
            numstack.push_back(dartResult[i]-'0');
        }   
    }
    dartlen=numstack.size();
    for(int i=0; i<dartlen; i++) answer+=numstack[i];
    return answer;
}