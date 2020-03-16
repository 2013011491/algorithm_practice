#include <string>
#include <vector>
#include <cctype>
#include <cstring>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if(cacheSize==0) return cities.size()*5;
    int cityNum=cities.size();
    
    for(int j=0; j<cityNum; j++)
    {
        for(int k=0; k<cities[j].size(); k++)
        {cities[j][k]=tolower(cities[j][k]);}
    }
    
    vector<string> cache;
    cache.push_back(cities[0]);
    answer+=5;
    
    int i=1;
    int check=0;
    string pres;
    for(i; i<cityNum; i++)
    {
        if(cache.size()==cacheSize) break;
        for(vector<string>::iterator it=cache.begin(); it!=cache.end(); ++it)
        {
            pres=*it;
            if(pres==cities[i])
            {
                check=1;
                answer+=1;
                cache.erase(it);
                cache.push_back(pres);
                break;
            }
        }
        if(check==0)
        {
            cache.push_back(cities[i]);
            answer+=5;
        }
        check=0;
    }
    check=0;
    if(i<cityNum)
    {
        for(i; i<cityNum; i++)
        {
            for(vector<string>::iterator it=cache.begin(); it!=cache.end(); ++it)
            {
                pres=*it;
                if(pres==cities[i])
                {
                    answer+=1;
                    check=1;
                    cache.erase(it);
                    cache.push_back(pres);
                    break;                    
                }
            }
            if(check==0)
            {
                cache.erase(cache.begin());
                cache.push_back(cities[i]);
                answer+=5;
            }
            check=0;
        }
    }
    return answer;
}