//2019-11-02 16:39~16:58
#include<iostream>

using namespace std;

int field[1002][1002];

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cout<<"#"<<tc<<" ";
        int n,m;
        int answer=0;
        cin>>n>>m;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++) field[i][j]=0;
            field[i][n]=0;
            field[i][n+1]=0;
        }
        for(int j=0; j<n+2; j++)
        {
            field[m][j]=0;
            field[m+1][j]=0;
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(field[i][j]==0)
                {
                    answer++;
                    field[i][j]=1;
                    field[i][j+2]=1;
                    field[i+2][j]=1;
                }
            }
        }
        cout<<answer<<"\n";
    }
    return 0;
}
