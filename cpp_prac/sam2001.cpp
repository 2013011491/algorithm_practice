//200207 17:45 start D2 68.93% 17:55 end
#include<iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,n,m;
    cin>>t;
    int board[15][15] = {0,};
    for(int tc=1; tc<=t; ++tc)
    {
        cout<<"#"<<tc<<" ";
        cin>>n>>m;
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j){ cin>>board[i][j]; }
        }

        int max=0;
        for(int i=0; i<=n-m; ++i)
        {
            for(int j=0; j<=n-m; ++j)
            {
                int temp=0;
                for(int l=i; l<i+m; ++l)
                {
                    for(int k=j; k<j+m; ++k){ temp+=board[l][k]; }
                }
                if(temp>max) max=temp;
            }
        }
        cout<<max<<"\n";
    }

    return 0;
}