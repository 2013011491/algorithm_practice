#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string,int> compr;
    for(int i=1; i<27; ++i)
    {
        string temp;
        temp.push_back('A'+i-1);
        compr[temp]=i;
    }
    int st=0;
    int count=27;
    int i;
    while(1)
    {
        for(i=1; i<=msg.size()-st; ++i)
        {
            if(compr[msg.substr(st,i)]==0)
            {
                compr[msg.substr(st,i)]=count++;
                break;
            }
        }
        answer.push_back(compr[msg.substr(st,i-1)]);
        st+=(i-1);
        if(st==msg.size()) break;        
    }
    return answer;
}