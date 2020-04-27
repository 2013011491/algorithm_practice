//200424 gold2 swexpert practice 
#include <iostream>
#include <array>

using namespace std;

struct point
{
    array<array<int,2>,11> stack;
    int slen;
    int color;
};

point board[16][16];
array<array<int,3>,12> pawn;
array<array<int,2>,5> way;

int white(int p,int w)
{
    int minus=0;
    int x=pawn[p][0]; int nx=x+way[w][0];
    int y=pawn[p][1]; int ny=y+way[w][1];
    int limit=board[x][y].slen;
    for(int s=pawn[p][2]; s<limit; ++s)
    {
        board[nx][ny].stack[board[nx][ny].slen]=board[x][y].stack[s];
        pawn[board[x][y].stack[s][0]][0]=nx;
        pawn[board[x][y].stack[s][0]][1]=ny;
        pawn[board[x][y].stack[s][0]][2]=board[nx][ny].slen++;
        minus++;
    }
    board[x][y].slen-=minus;
    if(board[nx][ny].slen>=4) return 1;
    return 0;
}

int red(int p, int w)
{
    int minus=0;
    int x=pawn[p][0]; int nx=x+way[w][0];
    int y=pawn[p][1]; int ny=y+way[w][1];
    int origin=pawn[p][2];
    int limit=board[x][y].slen;
    for(int s=limit-1; s>=origin; --s)
    {
        board[nx][ny].stack[board[nx][ny].slen]=board[x][y].stack[s];
        pawn[board[x][y].stack[s][0]][0]=nx;
        pawn[board[x][y].stack[s][0]][1]=ny;
        pawn[board[x][y].stack[s][0]][2]=board[nx][ny].slen++;
        minus++;
    }
    board[x][y].slen-=minus;
    if(board[nx][ny].slen>=4) return 1;
    return 0;
}

int main(void)
{
    //cin.tie(NULL);
    //ios::sync_with_stdio(false);

    int n,k;
    for(int i=0; i<16; ++i){for(int j=0; j<16; ++j){board[i][j].color=2; board[i][j].slen=0;}}
    way[1]={0,1}; way[2]={0,-1}; way[3]={-1,0}; way[4]={1,0};
    cin>>n>>k;
    for(int i=1; i<=n; ++i){for(int j=1; j<=n; ++j){cin>>board[i][j].color;}}
    
    for(int i=1; i<=k; ++i)
    {
        int x,y,w;
        cin>>x>>y>>w;
        board[x][y].stack[0][0]=i;
        board[x][y].stack[0][1]=w;
        board[x][y].slen++;
        pawn[i][0]=x;
        pawn[i][1]=y;
        pawn[i][2]=0;
    }
            
    int count=1;
    for(count=1; count<=1000; ++count)
    {
        int check=0;
        for(int p=1; p<=k; ++p)
        {
            int w=board[pawn[p][0]][pawn[p][1]].stack[pawn[p][2]][1];
            int ncolor=board[pawn[p][0]+way[w][0]][pawn[p][1]+way[w][1]].color;
            check=0;
            if(ncolor==0) check=white(p,w);
            else if(ncolor==1) check=red(p,w);
            else if(ncolor==2)
            {
                if(w==1) board[pawn[p][0]][pawn[p][1]].stack[pawn[p][2]][1]=2;
                else if(w==2) board[pawn[p][0]][pawn[p][1]].stack[pawn[p][2]][1]=1;
                else if(w==3) board[pawn[p][0]][pawn[p][1]].stack[pawn[p][2]][1]=4;
                else if(w==4) board[pawn[p][0]][pawn[p][1]].stack[pawn[p][2]][1]=3;

                w=board[pawn[p][0]][pawn[p][1]].stack[pawn[p][2]][1];
                ncolor=board[pawn[p][0]+way[w][0]][pawn[p][1]+way[w][1]].color;
                if(ncolor==0 || ncolor==1) --p;
            }
            //for(int i=1; i<=n; ++i){for(int j=1; j<=n; ++j){cout<<board[i][j].slen<<" ";}cout<<"\n";}
            //cout<<count<<" "<<p<<"\n";
            if(check==1) break;
        }
        if(check==1) break;
    }
    if(count>1000) cout<<-1;
    else cout<<count;
    return 0;   
}