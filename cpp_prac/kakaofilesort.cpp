#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

bool classcomp(pair<string,int> lhs, pair<string,int> rhs)
{
    string lhead,rhead;
    string lnum="00000",rnum="00000";
    int numst,numfi;
    for(numst=0; numst<lhs.first.size(); ++numst)
    {
        if(!isdigit(lhs.first[numst])) lhead.push_back(tolower(lhs.first[numst]));
        else break;
    }
    for(numfi=numst+1; numfi<lhs.first.size(); ++numfi){if(!isdigit(lhs.first[numfi])) break;}
    for(int i=5-numfi+numst; i<5; ++i){lnum[i]=lhs.first[numst++];}
    
    for(numst=0; numst<rhs.first.size(); ++numst)
    {
        if(!isdigit(rhs.first[numst])) rhead.push_back(tolower(rhs.first[numst]));
        else break;
    }
    for(numfi=numst+1; numfi<rhs.first.size(); ++numfi){if(!isdigit(rhs.first[numfi])) break;}
    for(int i=5-numfi+numst; i<5; ++i){rnum[i]=rhs.first[numst++];}
    
    if(lhead<rhead) return true;
    else if(lhead==rhead)
    {
        if(lnum<rnum) return true;
        else if(lnum==rnum)
        {
            if(lhs.second<rhs.second) return true;
        }
    }
    return false;
}

vector<string> solution(vector<string> files) {
    vector<pair<string,int>> answer;
    for(int i=0; i<files.size(); ++i){answer.push_back(make_pair(files[i],i));}
    sort(answer.begin(),answer.end(),classcomp);
    for(int i=0; i<answer.size(); ++i){files[i]=answer[i].first;}
    return files;
}