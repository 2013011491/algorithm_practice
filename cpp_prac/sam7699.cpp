//200219 21:28 start D4 51.19%  22:10 end
#include<iostream>
#include<array>
#include<string>

using namespace std;

array<string,20> isl;
array<int,26> visit;
int ans=0;
int r,c;

void dfs(int i, int j, int sum)
{
    if(visit[isl[i][j]-'A']!=0)
    {
        if(sum>ans) ans=sum;
        return;
    }
    visit[isl[i][j]-'A']=1;
    if(i>0) dfs(i-1,j,sum+1);
    if(i<r-1) dfs(i+1,j,sum+1);
    if(j>0) dfs(i,j-1,sum+1);
    if(j<c-1) dfs(i,j+1,sum+1);
    visit[isl[i][j]-'A']=0;
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>r>>c;
        ans=0;
        visit={0,};
        for(int i=0; i<r; ++i){ cin>>isl[i]; }
        dfs(0,0,0);
        if(r==1 && c==1) ans=1;
        cout<<"#"<<tc<<" "<<ans<<"\n";
    }
    return 0;
}