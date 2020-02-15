//200215 15:36 start d3  75.35% 15:50
#include<iostream>
#include<string>
#include<array>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,n;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n;
        array<string,50> field;
        int ans=0;
        for(int i=0; i<n; ++i){ cin>>field[i]; }
        for(int i=0; i<n/2; ++i)
        {
            for(int j=n/2-i; j<=n/2+i; ++j){ ans+=(field[i][j]-'0'); }
        }
        for(int i=0; i<n; ++i){ ans+=(field[n/2][i]-'0'); }
        for(int i=0; i<n/2; ++i)
        {
            for(int j=n/2-i; j<=n/2+i; ++j){ ans+=(field[n-1-i][j]-'0'); }
        }
        cout<<"#"<<tc<<" "<<ans<<"\n";
    }
    return 0;
}