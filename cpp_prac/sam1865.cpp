//200301 16L40 start d4 49.36%
#include<iostream>

using namespace std;

double prop[17][17]={0,};
int visit[17];
int n;
double maxv=0;
void dfs(int st, double sum)
{
    if(st==n)
    {
        if(maxv<sum) maxv=sum;
        return;
    }
    if(sum<=maxv) return;
    for(int i=0; i<n; ++i)
    {
        if(visit[i]==0 && prop[st][i]!=0)
        {
            visit[i]=1;
            dfs(st+1,sum*prop[st][i]);
            visit[i]=0;
        }
    }
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(6);

    int t;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        
        maxv=0;
        cin>>n;
        for(int i=0; i<n; ++i)
        {
            visit[i]=0;
            for(int j=0; j<n; ++j){ cin>>prop[i][j]; prop[i][j]/=100;}
        }
        dfs(0,1);
        cout<<"#"<<tc<<" "<<maxv*100<<"\n";
    }
    return 0;
}