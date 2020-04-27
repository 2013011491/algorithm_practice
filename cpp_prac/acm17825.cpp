//200426 gold2 swexpert practice  for 54min yeah!!!!
#include<iostream>
#include <array>

using namespace std;

int value[10]={0,};
int ans=0;
array<array<int,2>,4> pawn={0,};

int board[6][22]={{0,},
                  {10,13,16,19},
                  {20,22,24},
                  {30,28,27,26},
                  {25,30,35},
                  {40}};

array<int,2> nextp(int x, int y, int a)
{
    int ny=y+a;
    array<int,2> result={x,ny};
    if(x==0)
    {
        if(ny==5) result={1,0};
        else if(ny==10) result={2,0};
        else if(ny==15) result={3,0};
        else if(ny==20) result={5,0};
        else if(ny>20) result={-1,-1};
    }else if(x==1 || x==3)
    {
        if(ny>=4) return nextp(4,ny-4,0);
    }else if(x==2)
    {
        if(ny>=3) return nextp(4,ny-3,0);
    }else if(x==4)
    {
        if(ny==3) result={5,0};
        else if(ny>3) result={-1,-1};
    }else if(x==5)
    {
        if(ny>0) result={-1,-1};
    }
    return result;
}

void dfs(int st,int sum)
{
    if(st==10)
    {
        if(sum>ans) ans=sum;
        return;
    }
    int nv=value[st];
    for(int i=0; i<4; ++i)
    {
        if(pawn[i][0]==-1) continue;
        array<int,2> np = nextp(pawn[i][0],pawn[i][1],nv);
        int check=1;
        if(np[0]!=-1)
        {
            for(int j=0; j<4; ++j)
            {
                if((np[0]==pawn[j][0] && np[1]==pawn[j][1]))
                {
                    check=0;
                    break;
                }
            }
        }
        if(check==1)
        {
            int x=pawn[i][0],y=pawn[i][1];
            pawn[i][0]=np[0]; pawn[i][1]=np[1];
            if(np[0]==-1) dfs(st+1,sum);
            else dfs(st+1,sum+board[np[0]][np[1]]);
            pawn[i][0]=x; pawn[i][1]=y;
        }
    }
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for(int i=0; i<10; ++i){cin>>value[i];}
    for(int i=1; i<20; ++i){board[0][i]=2*i;}
    //for(int i=0; i<4; ++i){for(int j=0; j<2; ++j){cout<<pawn[i][j]<<" ";}cout<<"\n";}
    dfs(0,0);
    cout<<ans;
    
    return 0;
}