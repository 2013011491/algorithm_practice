//200205 14:48 start D3 48.22%   15:46 end
#include<iostream>
#include<queue>

using namespace std;
 
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
 
 
    int t,n,m;
    int cost[102]={0,};
    int weight[2002]={0,};
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cout<<"#"<<tc<<" ";
        cin>>n>>m;
        int park[102]={0,};
        int st=1;
        queue<int> waiting;
        int ans=0;
 
        for(int i=1; i<=n; ++i){ cin>>cost[i]; }
        for(int i=1; i<=m; ++i){ cin>>weight[i]; }
         
        for(int i=0; i<2*m; ++i)
        {
            int pres;
            cin>>pres;
            if(pres>0)
            {
                if(st>n) waiting.push(pres);
                else
                {
                    park[st]=1;    
                    ans += (weight[pres]*cost[st]);
                    weight[pres]=st;
                    while(park[st])
                    {
                        st++;
                        if(st>n) break;
                    }
                }
            }else
            {
                pres *= (-1);        
                if(!waiting.empty())
                {
                    int temp = waiting.front();
                    waiting.pop();
                    ans += (weight[temp]*cost[weight[pres]]);
                    weight[temp]=weight[pres];
                }else
                {           
                    park[weight[pres]]=0;
                    if(weight[pres]<st) st=weight[pres];     
                } 
            }
 
        }
        cout<<ans<<"\n";
    }
    return 0;
}