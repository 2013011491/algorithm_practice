//algorithm prac forsds gold5 during 2hours  don't confuse right-left
#include<iostream>
#include<queue>
#include<array>

using namespace std;

int n;
int ans=0;
array<array<int,22>,22> board={0,};
int way[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
typedef struct shark
{
    int size=2;
    int x,y;
    int stack=0;
}shark;
shark baby;

int main(void)
{
    cin>>n;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            cin>>board[i][j];
            if(board[i][j]==9){baby.x=i; baby.y=j; board[i][j]=0;}
        }
    }
    
    while(1)
    {
        queue<array<int,3>> bucket;
        bucket.push({baby.x,baby.y,0});
        int visit[22][22]={0,};
        visit[baby.x][baby.y]=1;
        int check=1;
        array<int,3> result={-1,-1,4000};

        while(!bucket.empty())
        {
            array<int,3> pres=bucket.front();
            bucket.pop();
            if(result[2]<pres[2]) break;
            for(int i=0; i<4; ++i)
            {
                int nx=pres[0]+way[i][0], ny=pres[1]+way[i][1];
                if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
                if(visit[nx][ny]!=0 && visit[nx][ny]<=pres[2]+1) continue;
                if(board[nx][ny]==0 || board[nx][ny]==baby.size){ bucket.push({nx,ny,pres[2]+1}); visit[nx][ny]=pres[2]+1;}
                else if(board[nx][ny]<baby.size)
                {
                    check=0;
                    if(result[2]>pres[2]+1){result[0]=nx; result[1]=ny; result[2]=pres[2]+1;}
                    else if(result[2]==pres[2]+1)
                    {
                        if(result[0]>nx){result[0]=nx; result[1]=ny;}
                        else if(result[0]==nx && result[1]>ny){result[0]=nx; result[1]=ny;}
                    }
                    
                }
            }
        }
        if(check==0)
        {
            baby.stack++;
            if(baby.size==baby.stack){baby.size++; baby.stack=0;}
            board[result[0]][result[1]]=0;
            ans+=result[2];
            baby.x=result[0]; baby.y=result[1];
        } 
        if(check==1) break;
    }
    cout<<ans;
    return 0;
}