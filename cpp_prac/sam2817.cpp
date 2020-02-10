//200207 19:03 start D3 46.64%  19:25 end 22min
#include<iostream>

using namespace std;


int number[20]={0,};
int ans=0;
int n,k;

void dfs(int sum, int st)
{
    if(sum+number[st]==k)
    {
        ans++;
    }else if(sum+number[st]<k)
    {
        for(int i=st+1; i<n; ++i)
        {
            dfs(sum+number[st],i);
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
        cin>>n>>k;
        for(int i=0; i<n; ++i){ cin>>number[i]; }
        cout<<"#"<<tc<<" ";

        ans=0;
        for(int i=0; i<n; ++i){ dfs(0,i); }
        cout<<ans<<"\n";

    }
    return 0;
}