//200306 17:53 start d4 68.21%
#include<iostream>

using namespace std;

int x[21][21]={0,};
int y[21][21]={0,};
int visit[21]={0,};
int n;
long long minv=80000000001;

void solution(long long sumx, long long sumy, int turn)
{
    if(turn==n/2)
    {
        long long temp=sumx*sumx+(sumy*sumy);
        if(temp<minv) minv=temp;
        return;
    }
    for(int i=0; i<n; ++i)
    {
        if(visit[i]==0)
        {
            visit[i]=1;
            for(int j=i; j<n; ++j)
            {
                if(visit[j]==0)
                {
                    visit[j]=1;
                    if(sumx*x[i][j]+sumy*y[i][j]>0) solution(sumx-x[i][j],sumy-y[i][j],turn+1);
                    else solution(sumx+x[i][j],sumy+y[i][j],turn+1);
                    visit[j]=0;
                }
            }
            visit[i]=0;
            break;
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
        for(int i=0; i<n; ++i){cin>>x[i][i]>>y[i][i];}
        for(int i=0; i<n; ++i)
        {
            visit[i]=0;
            for(int j=i; j<n; ++j)
            {
                if(i==j) continue;
                x[i][j]=x[j][j]-x[i][i];
                y[i][j]=y[j][j]-y[i][i];
            }
        }
        
        minv=80000000001;
        solution(0,0,0);
        cout<<"#"<<tc<<" "<<minv<<"\n";
    }
    return 0;
}