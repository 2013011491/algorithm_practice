#include <string>
#include <vector>

using namespace std;

vector<string> strdeli(string str)
{
    int st=0;
    vector<string> pres;
    for(int i=0; i<str.size(); ++i)
    {
        if(str[i]==',')
        {
            pres.push_back(str.substr(st,i-st));
            st=i+1;
        }
    }
    pres.push_back(str.substr(st));
    return pres;
}
string solution(string m, vector<string> musicinfos) {
    string answer = "";
    int anst=0;
    for(int i=0; i<musicinfos.size(); ++i)
    {
        vector<string> pres=strdeli(musicinfos[i]);
        int fint=stoi(pres[1].substr(0,2))*60+ stoi(pres[1].substr(3,2));
        int stt=stoi(pres[0].substr(0,2))*60+ stoi(pres[0].substr(3,2));
        int intert=fint-stt;
        int slen=pres[3].size();
        string summelo="";
        for(int j=0; j<pres[3].size(); ++j){if(pres[3][j]=='#') slen--;}
        for(int j=0; j<intert/slen; ++j){summelo+=pres[3];}
        int count=intert%slen;
        for(int j=0; count!=0; j++)
        {
            summelo.push_back(pres[3][j]);
            if(pres[3][j]!='#') count--;
        }
        summelo.push_back('0');
        int tt1=summelo.size();
        int tt2=m.size();
        for(int j=0; j<tt1-tt2; ++j)
        {
            if(summelo.substr(j,m.size())==m && summelo[j+m.size()]!='#' && intert>anst)
            {
                answer=pres[2];
                anst=intert;
            }
        }
    }
    if(answer=="") answer="(None)";
    return answer;
}