#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<string> words) {
    int answer = 0;
    map<string,int> count;
    for(int i=0; i<words.size(); ++i)
    {
        for(int j=1; j<=words[i].size(); ++j){count[words[i].substr(0,j)]++;}
    }
    for(int i=0; i<words.size(); ++i)
    {
        for(int j=1; j<=words[i].size(); ++j)
        {
            answer++;
            if(count[words[i].substr(0,j)]==1) break;
        }
    }
    return answer;
}