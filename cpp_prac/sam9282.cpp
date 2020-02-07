//200205 15:58 start d4 17.13%  1605 pause
#include<iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int t,n,m;
    cin>>t;

    for(int tc=1; tc<=t; ++tc)
    {
        
        cout<<"#"<<tc<<" ";
        cin>>n>>m;

        int choco[52][52]={0,};

        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j){ cin>>choco[i][j]; }
        }


    }
    return 0;
}
