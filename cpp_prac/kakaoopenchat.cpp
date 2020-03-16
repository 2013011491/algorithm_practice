#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string,string> nick;
    vector<pair<int,string>> modi;
    map<string,string>::iterator it;
    
    string ent="님이 들어왔습니다.";
    string out="님이 나갔습니다.";
    
    for(int i=0; i<record.size(); i++)
    {
        int preslen=record[i].size();
        if(record[i][0]=='E')
        {
            int leng=0;
            for(int j=6; j<preslen; j++)
            {
                if(record[i][j]!=' ') leng++;
                else break;
            }
            modi.push_back(make_pair(1,record[i].substr(6,leng)));
            nick[record[i].substr(6,leng)]=record[i].substr(7+leng,preslen-7-leng);
             
            
        }else if(record[i][0]=='C')
        {
            int leng=0;
            for(int j=7; j<preslen; j++)
            {
                if(record[i][j]!=' ') leng++;
                else break;
            }
            it = nick.find(record[i].substr(7,leng));
            if(it!=nick.end()) nick[record[i].substr(7,leng)]=record[i].substr(8+leng,preslen-8-leng);

        }else if(record[i][0]=='L')
        {
            int leng=0;
            for(int j=6; j<record[i].size(); j++)
            {
                if(record[i][j]!=' ') leng++;
                else break;
            }
            modi.push_back(make_pair(2,record[i].substr(6,leng)));
        }
    }
    int modilen=modi.size();
    for(int i=0; i<modilen; i++)
    {
        int nicklen=nick.size();
        if(modi[i].first==1)
        {
            answer.push_back(nick[modi[i].second]+ent);
        }else if(modi[i].first==2)
        {
            answer.push_back(nick[modi[i].second]+out);
        }
    }
    return answer;
}