#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

struct classcomp
{
    bool operator() (pair<long long,int> lhs, pair<long long,int> rhs)
    {
        if(lhs.first>rhs.first) return true;
        else if(lhs.first==rhs.first)
        {
            if(lhs.second<rhs.second) return true;
            else return false;   
        }else return false;
    }
};

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int sum[503]={0,};
    int fail[503]={0,};
    for(int i=0; i<stages.size(); i++)
    {
        fail[stages[i]]++;
        for(int j=stages[i]; j>0; j--) sum[j]++;
    }
    set<pair<long long,int>,classcomp> bucket;
    for(int i=1; i<N+1; i++)
    {
        if(sum[i]==0) bucket.insert(make_pair(0,i));
        else bucket.insert(make_pair(10000000000000*fail[i]/sum[i],i));
    }
    for(set<pair<long long,int>>::iterator it = bucket.begin(); it!=bucket.end(); ++it)
    {
        pair<long long,int> pres= *it;
        answer.push_back(pres.second);
    }
    
    return answer;
}