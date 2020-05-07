//200507 swexpert gold5 19:29 start
#include<iostream>
#include<stack>
#include<array>
#include<cmath>

using namespace std;

int n,l,r;
int popu[53][53]={0,};
int ans=0;
int way[4][2]={{-1,0},{1,0},{0,1},{0,-1}};

void solution()
{
    while(1)
    {
        int visit[53][53]={0,};
        int fi=0;
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=n; ++j)
            {
                if(visit[i][j]==0)
                {
                    int count=1;
                    int sum=0;
                    stack<array<int,2>> bucket;
                    array<array<int,2>,2501> point;
                    bucket.push({i,j});
                    visit[i][j]=1;
                    while(!bucket.empty())
                    {
                        array<int,2> pres=bucket.top();
                        bucket.pop();
                        point[count][0]=pres[0]; point[count++][1]=pres[1];
                        sum+=popu[pres[0]][pres[1]];
                        for(int k=0; k<4; ++k)
                        {
                            int x=pres[0]+way[k][0],y=pres[1]+way[k][1];
                            if(x<1 || x>n || y<1 || y>n) continue;
                            int dif=abs(popu[pres[0]][pres[1]]-popu[x][y]);
                            if(visit[x][y]==0 && dif>=l && dif<=r){ visit[x][y]=1; bucket.push({x,y});}
                        }
                    }
                    if(count!=2)
                    {
                       fi=1; 
                       sum/=(count-1);
                       for(int k=1; k<count; ++k){popu[point[k][0]][point[k][1]]=sum;}
                       //for(int k=1; k<=n; ++k){for(int t=1; t<=n; ++t){cout<<popu[k][t]<<" ";}cout<<"\n";} cout<<"\n";
                    }
                }
            }
        }
        if(fi==0) break;
        ans++;
    }
    
}
int main(void)
{
    cin>>n>>l>>r;
    for(int i=1; i<=n; ++i){for(int j=1; j<=n; ++j){cin>>popu[i][j];}}
    solution();
    cout<<ans;
    return 0;
}