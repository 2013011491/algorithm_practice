#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    int bustime[n];
    int timelen=timetable.size();
    vector<int> newtimetable;
    int sum;
    
    for(int i=0; i<n; i++) bustime[i]=540+(t*i);
    for(int i=0; i<timelen; i++)
    {
        sum=0;
        sum+=((timetable[i][0]-'0')*600);
        sum+=((timetable[i][1]-'0')*60);
        sum+=((timetable[i][3]-'0')*10);
        sum+=(timetable[i][4]-'0');
        newtimetable.push_back(sum);
    }
    sort(newtimetable.begin(),newtimetable.end());
    
    
    int i=0;
    int presposi=0;
    for(i; i<n-1; i++)
    {
        int presman=0;
        for(presposi; presposi<timelen; presposi++)
        {
            if(newtimetable[presposi]<=bustime[i])
            {
                presman++;
            }else break;
            if(presman==m)
            {
                presposi++;
                break;
            }
        }
    }
    
    int check=0;
    int finish=0;  
    for(presposi; presposi<timelen; presposi++)
    {
        if(check==m-1)
        {
            if(newtimetable[presposi]>bustime[i])
            {
                finish=1;
                sum=bustime[i];
                break;
            }else if(newtimetable[presposi]<=bustime[i])
            {
                finish=1;
                sum=newtimetable[presposi]-1;
                break;
            }
        }
        
        if(newtimetable[presposi]<=bustime[i])
        {
            check++;
        }else break;
    }
    
    if(finish==0) sum=bustime[i];
    answer.push_back((sum/600)+'0');
    sum%=600;
    answer.push_back((sum/60)+'0');
    sum%=60;
    answer.push_back(':');
    answer.push_back((sum/10)+'0');
    sum%=10;
    answer.push_back(sum+'0');
    
    return answer;
}