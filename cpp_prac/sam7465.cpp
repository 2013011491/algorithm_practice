//200220 16:26 start d4 43.71% 16:38 ez basic
#include<iostream>
#include<stack>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t,n,m;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        int visit[101]={0,};
        int contact[101][101]={0,};
        cin>>n>>m;
        for(int i=0; i<m; ++i)
        {
            int from,to;
            cin>>from>>to;
            contact[from][to]=1;
            contact[to][from]=1;
        }
        int ans=0;
        for(int i=1; i<=n; ++i)
        {
            if(visit[i]==0)
            {
                ans++;
                stack<int> bucket;
                bucket.push(i);
                while(!bucket.empty())
                {
                    int pres=bucket.top();
                    bucket.pop();
                    visit[pres]=1;
                    for(int i=1; i<=n; ++i)
                    {
                        if(contact[pres][i]==1 && visit[i]==0) bucket.push(i);
                    }
                }
            }
        }
        cout<<"#"<<tc<<" "<<ans<<"\n";
    }
    return 0;
}