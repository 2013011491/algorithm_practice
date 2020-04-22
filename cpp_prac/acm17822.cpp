//200422 18:41 restart gold3 19:30  during 43min 
//안될 땐 조금 쉬자 걍
#include <iostream>
#include <stack>
#include <array>

using namespace std;

int n,m,t;
int x,d,k;
int num=0,sumv=0;
int board[52][52]={0,};
stack<array<int,2>> bucket;

void rotate(int x, int d, int k)
{
    int line[52]={0,};
    if(d==1) k=m-k;
    for(int i=1; i*x<=n; ++i)
    {
        int col=i*x;
        for(int j=1; j<=m; ++j){line[(j+k)%m]=board[col][j];}
        line[m]=line[0];
        for(int j=1; j<=m; ++j){board[col][j]=line[j];}
    }
}

void search()
{
    for(int i=1; i<n; ++i)
    {
        for(int j=1; j<m; ++j)
        {
            if(board[i][j]==0) continue; 
            if(board[i][j]==board[i][j+1])
            {
                bucket.push({i,j});
                bucket.push({i,j+1});
            }
            if(board[i][j]==board[i+1][j])
            {
                bucket.push({i,j});
                bucket.push({i+1,j});
            }
        }
        if(board[i][m]==0) continue;
        if(board[i][m]==board[i][1])
        {
            bucket.push({i,m});
            bucket.push({i,1});
        }
        if(board[i][m]==board[i+1][m])
        {
            bucket.push({i,m});
            bucket.push({i+1,m});
        }
    }
    for(int j=1; j<m; ++j)
    {
        if(board[n][j]==0) continue;
        if(board[n][j]==board[n][j+1])
        {
            bucket.push({n,j});
            bucket.push({n,j+1});
        }
    }
    if(board[n][m]==0) return;
    if(board[n][m]==board[n][1])
    {
        bucket.push({n,m});
        bucket.push({n,1});
    }
}

void remov()
{
    if(bucket.empty())
    {
        int aver=sumv/num;
        if(sumv%num==0)
        {
            for(int i=1; i<=n; ++i)
            {
                for(int j=1; j<=m; ++j)
                {
                    if(board[i][j]==0) continue;
                    if(board[i][j]<aver){board[i][j]++; sumv++;}
                    else if(board[i][j]>aver){board[i][j]--; sumv--;}
                }
            }
        }else
        {
            for(int i=1; i<=n; ++i)
            {
                for(int j=1; j<=m; ++j)
                {
                    if(board[i][j]==0) continue;
                    if(board[i][j]<=aver){board[i][j]++; sumv++;}
                    else if(board[i][j]>aver){board[i][j]--; sumv--;}
                }
            }
        }
    }else
    {
        while(!bucket.empty())
        {
            array<int,2> pres = bucket.top();
            bucket.pop();
            if(board[pres[0]][pres[1]]!=0)
            {
                sumv-=board[pres[0]][pres[1]];
                num--;
                board[pres[0]][pres[1]]=0;
            }
        }   
    }
}
int main(void)
{   
    cin>>n>>m>>t;
    num=n*m;
    int ans=0;
    for(int i=1; i<=n; ++i){for(int j=1; j<=m; ++j){cin>>board[i][j]; sumv+=board[i][j];}}
    for(int i=0; i<t; ++i)
    {
        cin>>x>>d>>k;
        if(num==0) continue;
        rotate(x,d,k);
        search();
        remov();
        //for(int i=1; i<=n; ++i){for(int j=1; j<=m; ++j){cout<<board[i][j]<<" ";}cout<<"\n";}
    }
    for(int i=1; i<=n; ++i){for(int j=1; j<=m; ++j){ans+=board[i][j];}}
    cout<<ans;
    return 0;
}
