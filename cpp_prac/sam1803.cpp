#include<iostream>
#include<array>

long long MAXV=100000000000;

using namespace std;

array<array<int,3>,300001> edge;
array<array<long long,2>,100001> visit;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t,n,m,stp,endp;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n>>m>>stp>>endp;
        for(int i=0; i<=n; ++i){ visit[i][0]=MAXV; visit[i][1]=0;}
        for(int i=0; i<m; ++i){cin>>edge[i][0]>>edge[i][1]>>edge[i][2];}
        cout<<"#"<<tc<<" ";
        visit[stp][0]=0;
        visit[stp][1]=1;
        int pres=stp;
        int minv,mini=stp;
        while(mini!=endp)
        {
            minv=MAXV;
            for(int i=0; i<m; ++i)
            {
                if(edge[i][0]==pres && visit[edge[i][1]][1]==0)
                {
                    if(visit[edge[i][1]][0]>visit[pres][0]+edge[i][2])
                    {
                        visit[edge[i][1]][0]=visit[pres][0]+edge[i][2];
                    }
                    if(visit[edge[i][1]][0]<minv)
                    {
                        minv=visit[edge[i][1]][0];
                        mini=edge[i][1];
                    }
                }else if(edge[i][1]==pres && visit[edge[i][0]][1]==0)
                {
                    if(visit[edge[i][0]][0]>visit[pres][0]+edge[i][2])
                    {
                        visit[edge[i][0]][0]=visit[pres][0]+edge[i][2];
                    }
                    if(visit[edge[i][1]][0]<minv)
                    {
                        minv=visit[edge[i][0]][0];
                        mini=edge[i][0];
                    }
                }
                pres=mini;
                visit[pres][1]=1;
            }
        }
        cout<<visit[endp][0]<<"\n";
    }
    return 0;
}