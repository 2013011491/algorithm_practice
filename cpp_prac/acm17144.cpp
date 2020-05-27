//200524 forsds  during 47min
#include<iostream>

using namespace std;

int r,c,t;
int way[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int ux,uy,dx,dy;
typedef struct dirty
{
    int dust=0;
    int after=0;
}dirty;
dirty board[53][53];

void printbd()
{
    for(int i=0; i<r; ++i){for(int j=0; j<c; ++j){cout<<board[i][j].dust<<" ";}cout<<"\n";}
    cout<<"\n";
}
void spread()
{
    for(int i=0; i<r; ++i)
    {
        for(int j=0; j<c; ++j)
        {
            if(board[i][j].dust>0)
            {
                int adding=board[i][j].dust/5;
                for(int k=0; k<4; ++k)
                {
                    int nx=i+way[k][0], ny=j+way[k][1];
                    if(nx<0 || ny<0 || nx>=r || ny>=c) continue;
                    if(board[nx][ny].dust==-1) continue;
                    board[nx][ny].after+=adding;
                    board[i][j].dust-=adding;
                }
            }
        }
    }
    for(int i=0; i<r; ++i)
    {
        for(int j=0; j<c; ++j)
        {
            if(board[i][j].after>0)
            {
                board[i][j].dust+=board[i][j].after;
                board[i][j].after=0;
            }
        }
    }
}

void uprotate()
{
    int stx=ux-1, sty=uy;
    while(1)
    {
        if(stx>0 && sty==0)
        {
            board[stx][sty].dust=board[stx-1][sty].dust;
            stx--;
        }else if(stx==0 && sty<c-1)
        {
            board[stx][sty].dust=board[stx][sty+1].dust;
            sty++;
        }else if(stx<ux && sty==c-1)
        {
            board[stx][sty].dust=board[stx+1][sty].dust;
            stx++;
        }else if(stx==ux && sty>0)
        {
            if(stx==ux && sty==1){ board[stx][sty].dust=0; break;}
            board[stx][sty].dust=board[stx][sty-1].dust;
            sty--;
        }
    }
}

void dorotate()
{
    int stx=dx+1, sty=dy;
    while(1)
    {
        if(stx<r-1 && sty==0)
        {
            board[stx][sty].dust=board[stx+1][sty].dust;
            stx++;
        }else if(stx==r-1 && sty<c-1)
        {
            board[stx][sty].dust=board[stx][sty+1].dust;
            sty++;
        }else if(stx>dx && sty==c-1)
        {
            board[stx][sty].dust=board[stx-1][sty].dust;
            stx--;
        }else if(stx==dx && sty>0)
        {
            if(stx==dx && sty==1){ board[stx][sty].dust=0; break;}
            board[stx][sty].dust=board[stx][sty-1].dust;
            sty--;
        }
    }
}
void clean()
{
    uprotate();
    dorotate();
}

int main(void)
{
    cin>>r>>c>>t;
    int count=0;
    for(int i=0; i<r; ++i)
    {
        for(int j=0; j<c; ++j)
        {
            cin>>board[i][j].dust;
            if(board[i][j].dust==-1 && count==0){ux=i; uy=j; dx=i+1; dy=j; count++;}
        }
    }
    for(int i=0; i<t; ++i)
    {
        spread();
        clean();
    }
    int ans=0;
    for(int i=0; i<r; ++i){for(int j=0; j<c; ++j){if(board[i][j].dust>0) ans+=board[i][j].dust;}}
    cout<<ans;
}