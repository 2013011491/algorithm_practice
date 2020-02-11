//200211 19:46 start D3 42.95%  20:30  44min
//greedy 느낌의 dfs 현재 진행에서 그대로 depth만 가거나 점수 더해서 가거나 이런갈래로 
#include<iostream>
#include<array>

using namespace std;

array<array<int,2>,20> kcal;
int visit[20]={0,};
int maxP=0;
int t,n,l;

void dfs(int st, int point, int sum)
{
    if(sum>l) return;
    if(sum<=l && point>maxP) maxP=point;
    for(int i=st; i<n; ++i)
    {
        if(visit[i]==0)
        {
            visit[i]=1;
            dfs(i,point+kcal[i][0], sum+kcal[i][1]);
            visit[i]=0;
        }
    }
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    { 
        cin>>n>>l;
        for(int i=0; i<n; ++i)
        {
            cin>>kcal[i][0]>>kcal[i][1];
        }
        dfs(0,0,0);
        cout<<"#"<<tc<<" "<<maxP<<"\n";
        maxP=0;
    }
    return 0;
}