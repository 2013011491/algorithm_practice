//200527 forsds gold3
#include<iostream>

using namespace std;

int board[10][10]={0,};
int paper[5]={5,5,5,5,5};
int ans=26;
void attach(int x, int y, int n){for(int i=x; i<x+n; ++i){for(int j=y; j<y+n; ++j){board[i][j]=0;}}}
void dettach(int x, int y, int n){for(int i=x; i<x+n; ++i){for(int j=y; j<y+n; ++j){board[i][j]=1;}}}
void printbd()
{
    for(int i=0; i<10; ++i){for(int j=0; j<10; ++j){cout<<board[i][j]<<" ";} cout<<"\n";}
    cout<<"\n";
}
bool isposi(int x, int y, int n)
{
    if(x+n>10 || y+n>10) return false;
    for(int i=x; i<x+n; ++i)
    {
        for(int j=y; j<y+n; ++j)
        {
            if(board[i][j]==0) return false;
        }
    }
    return true;
}
void dfs(int x, int y, int sum)
{
    int check=1;
    if(sum>=ans) return;
    for(int i=x; i<10; ++i)
    {
        for(int j=0; j<10; ++j)
        {
            if(board[i][j]==1)
            {
                check=0;
                for(int k=5; k>=1; --k)
                {
                    if(paper[k-1]==0) continue;
                    if(isposi(i,j,k))
                    {
                        attach(i,j,k);
                        paper[k-1]--;
                        //printbd();
                        dfs(i,j,sum+1);
                        paper[k-1]++;
                        dettach(i,j,k);
                    }
                }
                break;
            }
        }
        if(check==0) break;
    }
    if(check==1)
    {
        int result=0;
        for(int i=0; i<5; ++i){result+=(5-paper[i]);}
        if(result<ans) ans=result;
        return;
    }
}
int main(void)
{
    for(int i=0; i<10; ++i){for(int j=0; j<10; ++j){cin>>board[i][j];}}
    dfs(0,0,0);
    if(ans==26) ans=-1;
    cout<<ans;
    return 0;
}