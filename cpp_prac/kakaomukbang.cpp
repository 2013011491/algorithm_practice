#include <string>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

bool classcomp(array<int,2> lhs, array<int,2> rhs)
{
    if(lhs[0]<rhs[0]) return true;
    else if(lhs[0]==rhs[0]) return lhs[1]<rhs[1]? true: false;
    else return false;
}

bool secomp(array<int,2> lhs, array<int,2> rhs){return lhs[1]<rhs[1]? true : false;}

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    long long total=0;
    int cycle=food_times.size();
    vector<array<int,2>> ft;
    //resave to dif vector
    for(int i=0; i<food_times.size(); ++i)
    {
        total+=food_times[i];
        ft.push_back({food_times[i],i+1});
    }
    if(total<=k) return -1; //case eating all
    
    sort(ft.begin(),ft.end(),classcomp);
    int plen=0;
    int value=0;
    int pres=ft[0][0];
    int index=0;
    for(index; index<ft.size(); ++index)
    {
        if(ft[index][0]!=pres) break;
        plen++;
    }
    while(k/((pres-value)*cycle)>=1)
    {
        k=k-((pres-value)*cycle);
        cycle-=plen;
        value=pres;
        pres=ft[index][0];
        plen=0;
        for(index; index<ft.size(); ++index)
        {
            if(ft[index][0]!=pres) break;
            plen++;        
        }
    }
    sort(ft.begin()+(index-plen), ft.end(), secomp);
    k%=cycle;
    answer=ft[index-plen+k][1];
    
    return answer;
}