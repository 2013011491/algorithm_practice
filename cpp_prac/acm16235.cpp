//200512 for swexpert gold4 
#include<iostream>
#include<array>
#include<algorithm>

using namespace std;

int n,m,k;
int way[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int A[12][12]={0,};
typedef struct ground
{
    int nutri;
    int dead;
    int tnum;
    array<int,103> trees;
}ground;
ground board[12][12];

void treesort()
{
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            if(board[i][j].tnum!=0) sort(board[i][j].trees.begin(),board[i][j].trees.begin()+board[i][j].tnum);
        }
    }
}

void spring()
{
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            if(board[i][j].tnum==0) continue;
            int tnum=board[i][j].tnum;
            for(int q=0; q<tnum; ++q)
            {
                if(board[i][j].trees[q]<=board[i][j].nutri){ board[i][j].nutri-=board[i][j].trees[q]; board[i][j].trees[q]++;}
                else
                {
                    for(q; q<tnum; ++q)
                    {
                        board[i][j].dead+=(board[i][j].trees[q]/2);
                        board[i][j].trees[q]=0;
                        board[i][j].tnum--;                        
                    }
                    break;
                }
                
            }
        }
    }
}
void summer()
{
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            if(board[i][j].dead!=0)
            {
                board[i][j].nutri+=board[i][j].dead;
                board[i][j].dead=0;
            }
        }
    }
}
void autumn()
{
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            if(board[i][j].tnum==0) continue;
            int tnum=board[i][j].tnum;
            int brednum=0;
            for(int q=0; q<tnum; ++q){if(board[i][j].trees[q]%5==0) brednum++;}
            if(brednum!=0)
            {
                for(int w=0; w<8; ++w)
                {
                    int nx=i+way[w][0], ny=j+way[w][1];
                    if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
                    for(int q=0; q<brednum; ++q){board[nx][ny].trees[board[nx][ny].tnum]=1; board[nx][ny].tnum++;}
                }
            }
        }
    }
    treesort();
}
void winter()
{
    for(int i=0; i<n; ++i){for(int j=0; j<n; ++j){board[i][j].nutri+=A[i][j];}}
}
void oneyear()
{
    spring();
    summer();
    autumn();
    winter();
}

void printstat()
{
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j){cout<<board[i][j].nutri<<" ";}
        cout<<"      ";
        for(int j=0; j<n; ++j){cout<<board[i][j].dead<<" ";}
        cout<<"      ";
        for(int j=0; j<n; ++j){cout<<board[i][j].tnum<<" ";}
        cout<<"\n";
    }
}
int main(void)
{
    cin>>n>>m>>k;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            cin>>A[i][j];
            board[i][j].nutri=5;
            board[i][j].dead=0;
            board[i][j].tnum=0;
        }
    }
    for(int i=0; i<m; ++i)
    {
        int x,y,z;
        cin>>x>>y>>z;
        board[x-1][y-1].trees[board[x-1][y-1].tnum]=z;
        board[x-1][y-1].tnum++;
    }
    //printstat();
    //cout<<"\n";
    for(int i=0; i<k; ++i){oneyear();}
    int ans=0;
    for(int i=0; i<n; ++i){for(int j=0; j<n; ++j){if(board[i][j].tnum!=0) ans+=board[i][j].tnum;}}
    cout<<ans;
    
    return 0;
}