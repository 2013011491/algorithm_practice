//200220 14:04 start D3 42.94% 14:19 end
#include<iostream>
#include<array>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t,n,p;
    array<int,500> bstop={0,};
    array<int,500> ai={0,};
    array<int,500> bi={0,};
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n;
        cout<<"#"<<tc<<" ";
        for(int i=0; i<n; ++i)
        {
            cin>>ai[i]>>bi[i];
        }
        cin>>p;
        for(int i=0; i<p; ++i)
        {
            int c;
            cin>>c;
            int ans=0;
            for(int j=0; j<n; ++j)
            {
                if(ai[j]<=c && c<=bi[j]) ans++;
            }
            cout<<ans<<" ";
        }
        cout<<"\n";
       }
    return 0;
}