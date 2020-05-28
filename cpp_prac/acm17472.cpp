//200528 gold3 forsds during 79min
#include<iostream>
#include<stack>
#include<array>
#include<algorithm>

using namespace std;

int n,m,nofi;
int board[12][12]={0,};
int way[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int island[9]={0,1,2,3,4,5,6,7,8};
int nofb=0,check=0,ans=0;
array<array<int,3>,130> bridge;
array<array<int,3>,130>::iterator it;

bool classcomp(array<int,3> lhs, array<int,3> rhs){return lhs[2]<rhs[2]? true: false; }
void findisland()
{
    int count=2;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        { 
            if(board[i][j]==1)
            {
                stack<array<int,2>> bucket;
                bucket.push({i,j});
                while(!bucket.empty())
                {
                    array<int,2> pres=bucket.top();
                    bucket.pop();
                    if(board[pres[0]][pres[1]]==count) continue;
                    board[pres[0]][pres[1]]=count;
                    for(int k=0; k<4; ++k)
                    {
                        int nx=pres[0]+way[k][0], ny=pres[1]+way[k][1];
                        if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                        if(board[nx][ny]==1) bucket.push({nx,ny});

                    }
                }
                count++;
            }
        }
    }
    nofi=count-2;
}

void findbridge()
{
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            if(board[i][j]!=0)
            {
                for(int st=j+1; st<m; ++st)
                {
                    if(board[i][st]==board[i][j]) break;
                    else if(board[i][st]!=0)
                    {
                        if(st-j<3) break;
                        bridge[nofb][2]=st-j-1;
                        if(board[i][st]>board[i][j])
                        {
                            bridge[nofb][0]=board[i][j];
                            bridge[nofb][1]=board[i][st];
                        }else
                        {
                            bridge[nofb][0]=board[i][st];
                            bridge[nofb][1]=board[i][j];
                        }
                        nofb++;
                        break;
                    }
                }
                for(int st=i+1; st<n; ++st)
                {
                    if(board[st][j]==board[i][j]) break;
                    else if(board[st][j]!=0)
                    {
                        if(st-i<3) break;
                        bridge[nofb][2]=st-i-1;
                        if(board[st][j]>board[i][j])
                        {
                            bridge[nofb][0]=board[i][j];
                            bridge[nofb][1]=board[st][j];
                        }else
                        {
                            bridge[nofb][0]=board[st][j];
                            bridge[nofb][1]=board[i][j];
                        }
                        nofb++;
                        break;
                    }
                }
            }
        }
    }
    sort(bridge.begin(),bridge.begin()+nofb,classcomp);
    it=unique(bridge.begin(),bridge.begin()+nofb);
    nofb=it-bridge.begin();
}

int findhead(int p)
{
    if(island[p]!=p)
    {
        island[p]=findhead(island[p]);
        return island[p];
    }else return p;
}

void selectbridge()
{
    int limit=nofi-1;
    int count=0;
    for(int i=0; i<nofb; ++i)
    {
        int x=findhead(bridge[i][0]), y=findhead(bridge[i][1]);
        if(x==y) continue;
        else
        {
            island[y]=island[x];
            count++;
            ans+=bridge[i][2];
        }
        if(count==limit){check=1; break;}
    }
}

int main(void)
{
    cin>>n>>m;
    for(int i=0; i<n; ++i){for(int j=0; j<m; ++j){ cin>>board[i][j]; }}
    findisland();
    findbridge();
    selectbridge();
    if(check==0) cout<<-1;
    else cout<<ans;
    return 0;
}