//200511 gold4 for swexpert restart   for 56min !!!! yeah!
//understanding how to coding bfs and no abuse pruing
#include<iostream>
#include<array>
#include<queue>

using namespace std;

int n,m;
int vnum=0;
int ans=2501;
int board[53][53]={0,};
int way[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
array<array<int,2>,11> virus;
array<array<int,2>,11> selecv;

void cal()
{
    int nboard[53][53]={0,};
    copy(&board[0][0],&board[0][0]+(53*53),&nboard[0][0]);
    queue<array<int,2>> bucket;
    for(int i=0; i<m; ++i)
    {
        array<int,2> stp; stp[0]=selecv[i][0]; stp[1]=selecv[i][1];
        nboard[stp[0]][stp[1]]=0;
        bucket.push(stp);
    }
    while(!bucket.empty())
    {
        array<int,2> stp=bucket.front();
        bucket.pop();
        if(nboard[stp[0]][stp[1]]>=ans) continue;
        for(int i=0; i<4; ++i)
        {
            int nx=stp[0]+way[i][0], ny=stp[1]+way[i][1];
            if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
            if(nboard[nx][ny]>nboard[stp[0]][stp[1]]+1)
            {
                nboard[nx][ny]=nboard[stp[0]][stp[1]]+1;
                bucket.push({nx,ny});
            }
        }
    }
    int max=0;
    for(int i=0; i<vnum; ++i){nboard[virus[i][0]][virus[i][1]]=0;}
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            if(nboard[i][j]==2501) return;
            else if(nboard[i][j]==-1) continue;
            else if(nboard[i][j]>max) max=nboard[i][j];
        }
    }
    if(max<ans) ans=max;
}

void find_cal(int st, int depth)
{
    if(depth==m)
    {
        cal();
        return;
    }
    for(int i=st; i<vnum; ++i)
    {
        selecv[depth]=virus[i];
        find_cal(i+1,depth+1);
    }
}

int main(void)
{
    cin>>n>>m;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            int temp;
            cin>>temp;
            if(temp==2)
            {
                board[i][j]=2501;
                virus[vnum++]={i,j};
            }else if(temp==0) board[i][j]=2501;
            else if(temp==1) board[i][j]=-1;
        }
    }
    find_cal(0,0);
    if(ans==2501) ans=-1;
    cout<<ans;
    //for(int i=0; i<n; ++i){for(int j=0; j<n; ++j){cout<<board[i][j]<<" ";}cout<<"\n";}
    return 0;
}