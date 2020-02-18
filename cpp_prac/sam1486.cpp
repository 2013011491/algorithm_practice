//200218 17:41 start D4 70.52% 18:11  30min
//index좀 잘보자 !, 조합의 경우 visit도 필요없음.
#include<iostream>
#include<array>

using namespace std;

array<int,20> heights;
int n,b;
int minh=200001;

void dfs(int st,int sum)
{
    if(minh==b) return;
    if(sum>=b)
    {
        if(sum<minh) minh=sum;
        return;
    }
    for(int i=st; i<n; ++i)
    { dfs(i+1,sum+heights[i]); }
}

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n>>b;
        for(int i=0; i<n; ++i){ cin>>heights[i]; }
        dfs(0,0);
        cout<<"#"<<tc<<" "<<minh-b<<"\n";
        minh=200001;
    }
    return 0;
}