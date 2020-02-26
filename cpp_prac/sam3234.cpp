//200226 13:21 start D4 40.48% 14:19 end about 60min
#include<iostream>
#include<cmath>
using namespace std;

int weight[10]={0,};
int visit[10]={0,};
int n;
long long ans=0;
long long sum=0;
long long fac(long long n)
{
    if(n==1) return 1;
    return n*fac(n-1);
}
void dfs(int left, int right, int pres, long long sum)
{
    if(pres==n) 
    {
        ans++;
        return;
    }
    if(left>=right+sum)
    {
        ans+=(fac(n-pres)*pow(2,(n-pres)));
        return;
    }
    
    for(int i=0; i<n; ++i)
    {
        if(visit[i]==0)
        {
            visit[i]=1;
            dfs(left+weight[i],right,pres+1,sum-weight[i]);
            if(right+weight[i]<=left) dfs(left,right+weight[i],pres+1,sum-weight[i]);
            visit[i]=0;
        }
    }
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n;
        sum=0;
        for(int i=0; i<n; ++i)
        { 
            cin>>weight[i];
            sum+=weight[i]; 
        }
        cout<<"#"<<tc<<" ";
        ans=0;
        dfs(0,0,0,sum);
        cout<<ans<<"\n";
    }
    return 0;
}