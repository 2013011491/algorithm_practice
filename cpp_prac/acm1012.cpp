#include<iostream>
#include<stack>
#include<array>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,m,n,k,x,y;
    cin>>t;

    for(int tc=0; tc<t; tc++)
    {
        cin>>m>>n>>k;
        stack<array<int,2>> bucket;
        array<int,2> pres;
        int field[50][50]={0,};
        int need=0;
        for(int i=0; i<k; i++)
        {
            cin>>x>>y;
            field[x][y]=1;
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(field[i][j]==1)
                {
                    need++;
                    bucket.push({i,j});
                    while(bucket.size())
                    {
                        pres=bucket.top();
                        bucket.pop();
                        field[pres[0]][pres[1]]=0;
                        if(pres[1]+1<n && field[pres[0]][pres[1]+1]==1) bucket.push({pres[0],pres[1]+1});
                        if(pres[1]>0 && field[pres[0]][pres[1]-1]==1) bucket.push({pres[0],pres[1]-1});
                        if(pres[0]+1<m && field[pres[0]+1][pres[1]]==1) bucket.push({pres[0]+1,pres[1]});
                        if(pres[0]>0 && field[pres[0]-1][pres[1]]==1) bucket.push({pres[0]-1,pres[1]});
                    }
                }
            }
        }
        cout<<need<<"\n";
    }
    return 0;
}