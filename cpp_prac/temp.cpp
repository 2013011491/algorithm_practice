#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int n=lock.size();
    int m=key.size();
    vector<array<int,2>> lposi;
    vector<array<int,2>> kposi;
    vector<array<int,2>>::iterator it;
    for(int i=0; i<lock.size(); i++)
    {
        for(int j=0; j<lock.size(); j++)
        {
            if(lock[i][j]==0) lposi.push_back({i,j});
        }
    }
    for(int i=0; i<key.size(); i++)
    {
        for(int j=0; j<key.size(); j++)
        {
            if(key[i][j]==1) kposi.push_back({i,j});
        }
    }
    for(int k=0; k<3; k++)
    {
        for(int i=0; i<kposi.size(); i++)
        {
            int xsub=lposi[0][0]-kposi[i][0];
            int ysub=lposi[0][1]-kposi[i][1];
            vector<array<int,2>> lcop=lposi;
            int check=1;
            for(int j=0; j<kposi.size(); j++)
            {
                array<int,2> tt={kposi[j][0]+xsub,kposi[j][1]+ysub};
                it=find(lcop.begin(),lcop.end(),tt);
                if(it==lcop.end())
                {
                    if(kposi[j][0]+xsub>=n || kposi[j][0]+xsub<0 || kposi[j][1]+ysub>=n || kposi[j][1]+ysub<0) continue;
                    else
                    {
                        check=0;
                        break;
                    }
                }else lcop.erase(it);
            }
            if(check==1 && lcop.empty()) return true;
        }
        for(int i=0; i<kposi.size(); i++)
        {
            int temp=kposi[i][0];
            kposi[i][0]=kposi[i][1];
            kposi[i][1]=m-temp-1;
        }
    }
    return answer;
}
int main(void)
{
    bool a= solution({{0, 0, 0}, {1, 0, 0}, {0, 1, 1}},{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}});
    cout<<a;
    return 0;
}