#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<string> lines) {
    int answer = 1;
    vector<pair<long,long>> changed;
    
    int linenum=lines.size();
    for(int i=0; i<linenum; i++)
    {
        long start=0;
        long end=0;
        end=(lines[i][11]-'0')*36000 + (lines[i][12]-'0')*3600 + (lines[i][14]-'0')*600 + (lines[i][15]-'0')*60 + (lines[i][17]-'0')*10 + (lines[i][18]-'0');
        end = end*1000 + (lines[i][20]-'0')*100 + (lines[i][21]-'0')*10 + (lines[i][22]-'0');
        start = (lines[i][24]-'0')*1000;
        int temp=100;
        for(int j=26; j<lines[i].size()-1; j++)
        {
            start += (lines[i][j]-'0')*temp;
            temp/=10;
        }
        start = end-start+1;
        if(start<0) start=0;
        changed.push_back(make_pair(start,end));
    }
    //for(int i=0; i<changed.size(); i++) cout<<changed[i].first<<" "<<changed[i].second<<" "<<i<<"\n";
    //cout<<"\n";
    int max=1;
    for(int i=0; i<changed.size()-1; i++)
    {
        int st=changed[i].second;
        int last=st+999;
        int count=1;
        //cout<<i<<"\n";
        //cout<<st<<" "<<last<<"\n";
        for(int j=i+1; j<changed.size(); j++)
        {
            if(last<changed[j].first || st>changed[j].second) continue;
            count++;
            //cout<<changed[j].first<<" "<<changed[j].second<<" "<<j<<"\n";
        }
        //cout<<"\n";
        if(count>max) max=count;
    }
    answer=max;
    return answer;
}