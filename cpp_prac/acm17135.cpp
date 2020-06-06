//200606 forsds gold4
#include<iostream>
#include<queue>
#include<array>

using namespace std;

int n,m,d;
int oboard[17][17]={0,};
int selecp[3]={0,};
int ans=0;
int way[3][2]={{0,-1},{-1,0},{0,1}};

void bfs()
{
    int result=0;
    int board[17][17]={0,};
    copy(&oboard[0][0],&oboard[0][0]+(17*17),&board[0][0]);
    for(int c=n-1; c>=0; --c)
    {
        int threep[3][3]={n,m,n+m,n,m,n+m,n,m,n+m};
        for(int i=0; i<3; ++i)
        {
            int visit[17][17]={0,};
            queue<array<int,3>> bucket;
            bucket.push({c,selecp[i],1});
            visit[c][selecp[i]]=1;
            while(!bucket.empty())
            {
                array<int,3> pres=bucket.front();
                bucket.pop();
                if(threep[i][2]<pres[2] || pres[2]>d) break;

                if(board[pres[0]][pres[1]]==0)
                {
                    for(int j=0; j<3; ++j)
                    {
                        int nx=pres[0]+way[j][0],ny=pres[1]+way[j][1];
                        if(nx<0 || ny<0 ||nx>=n || ny>=m) continue;
                        if(visit[nx][ny]==1) continue;
                        bucket.push({nx,ny,pres[2]+1});
                        visit[nx][ny]=1;
                    }
                }else if(board[pres[0]][pres[1]]==1)
                {
                    if(threep[i][1]>pres[1])
                    {
                        threep[i][0]=pres[0]; threep[i][1]=pres[1]; threep[i][2]=pres[2];
                    }
                }
            }

        }
        //end selec;
        for(int i=0; i<3; ++i)
        {
            if(threep[i][0]!=n && board[threep[i][0]][threep[i][1]]==1)
            {
                board[threep[i][0]][threep[i][1]]=0; result++;
            } 
        }
    }
    if(result>ans) ans=result;
}

void combi(int st,int depth)
{
    if(depth==3)
    {
        bfs();
        return;
    }
    for(int i=st; i<m; ++i)
    {
        selecp[depth]=i;
        combi(i+1,depth+1);
    }
}
int main(void)
{
    cin>>n>>m>>d;
    for(int i=0; i<n; ++i){for(int j=0; j<m; ++j){cin>>oboard[i][j];}}
    combi(0,0);
    cout<<ans;
    return 0;
}   