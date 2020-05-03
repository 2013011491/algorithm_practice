//2000502 gold3 restart
#include<iostream>
#include<string>
#include<array>

using namespace std;

int n,m;
array<string,13> board;
int way[4][2]={{0,1},{0,-1},{-1,0},{1,0}}; // r,l,u,d
int red[2]={0,};
int blue[2]={0,};
int ans=11;

array<int,5> go(int w,int r[2],int b[2])
{
    array<int,5> result={0,r[0],r[1],b[0],b[1]};
    int comp1,comp2;
    if(w==0){comp1=b[1]; comp2=r[1];}
    else if(w==1){comp1=r[1]; comp2=b[1];}
    else if(w==2){comp1=r[0]; comp2=b[0];}
    else if(w==3){comp1=b[0]; comp2=r[0];}

    if(comp1<comp2) //red 먼저옮기기
    {
        int nx=r[0],ny=r[1];
        while(1)
        {
            nx+=way[w][0];
            ny+=way[w][1];

            if(board[nx][ny]=='O')
            {
                result[0]=1;
                break;
            }else if(board[nx][ny]=='#')
            {
                result[1]=nx-way[w][0]; result[2]=ny-way[w][1];
                board[result[1]][result[2]]='#';
                break;
            }
        }
        nx=b[0]; ny=b[1];
        while(1)
        {
            nx+=way[w][0];
            ny+=way[w][1];
            
            if(board[nx][ny]=='O')
            {
                result[0]=2;
                break;
            }else if(board[nx][ny]=='#')
            {
                result[3]=nx-way[w][0]; result[4]=ny-way[w][1];
                break;
            }
        }
        board[result[1]][result[2]]='.';
    }else // blue먼저 옮기기
    {
        int nx=b[0],ny=b[1];
        while(1)
        {
            nx+=way[w][0];
            ny+=way[w][1];
    
            if(board[nx][ny]=='O')
            {
                result[0]=2;
                return result;
            }else if(board[nx][ny]=='#')
            {
                result[3]=nx-way[w][0]; result[4]=ny-way[w][1];
                board[result[3]][result[4]]='#';
                break;
            }
        }
        nx=r[0]; ny=r[1];
        while(1)
        {
            nx+=way[w][0];
            ny+=way[w][1];

            if(board[nx][ny]=='O')
            {
                result[0]=1;
                break;
            }else if(board[nx][ny]=='#')
            {
                result[1]=nx-way[w][0]; result[2]=ny-way[w][1];
                break;
            }
        }
        board[result[3]][result[4]]='.';
    }
    return result;
}

void dfs(int st,int r[2],int b[2])
{
    if(st>=ans) return;
    for(int i=0; i<4; ++i)
    {
        array<int,5> result=go(i,r,b);
        if(result[0]==1)
        {
            if(st+1<ans) ans=st+1;
            break;
        }else if(result[0]==0)
        {
            int cr[2]={result[1],result[2]};
            int cb[2]={result[3],result[4]};
            dfs(st+1,cr,cb);
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin>>n>>m;
    for(int i=0; i<n; ++i)
    {
        cin>>board[i];
        for(int j=0; j<m; ++j)
        {
            if(board[i][j]=='B')
            {
                blue[0]=i;
                blue[1]=j;
                board[i][j]='.';
            }else if(board[i][j]=='R')
            {
                red[0]=i;
                red[1]=j;
                board[i][j]='.';
            }
        }
    }
    dfs(0,red,blue);
    if(ans==11) ans=-1;
    cout<<ans;

    return 0;
}