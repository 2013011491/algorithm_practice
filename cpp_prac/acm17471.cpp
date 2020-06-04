//200603 forsds gold5   fail! restart 0604
#include<iostream>
#include<stack>
#include<cmath>

using namespace std;

int n;
int popul[11]={0,};
int city[11][11]={0,};
int ans=1000000;

void dfs()
{
    int limit = (1<<n)-1;
    for(int i=1; i<limit; ++i)
    {
        int visit[11]={0,};
        int origin=i;
        stack<int> bucket;
        int section[2]={1,1};
        int sum[2]={0,0};

        for(int j=0; j<n; ++j)
        {
            visit[j]=origin%2;
            origin=(origin>>1);
        }
        for(int t=0; t<2; ++t)
        {
            for(int j=0; j<n; ++j)
            {
                if(visit[j]==t)
                {
                    bucket.push(j);
                    visit[j]=t+2;
                    sum[t]+=popul[j];
                    while(!bucket.empty())
                    {
                        int pres=bucket.top();
                        bucket.pop();
                        for(int k=0; k<n; ++k)
                        {
                            if(city[pres][k]==1 && visit[k]==t)
                            {
                                visit[k]=t+2;
                                bucket.push(k);
                                section[t]++;
                                sum[t]+=popul[k];
                            } 
                        }
                    }
                    break;
                }   
            }
        }
        
        if((section[0]+section[1]==n) && (ans>abs(sum[0]-sum[1]))) ans=abs(sum[0]-sum[1]);
    }
}

int main(void)
{
    cin>>n;
    for(int i=0; i<n; ++i){cin>>popul[i];}
    for(int i=0; i<n; ++i)
    {
        int temp;
        cin>>temp;
        for(int j=0; j<temp; ++j)
        {
            int dest;
            cin>>dest;
            city[i][dest-1]=1;
        }
    }
    dfs();
    if(ans==1000000) ans=-1;
    cout<<ans;
    return 0;
}