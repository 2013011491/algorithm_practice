//200227 16:40 start d3 70.65%  16:45 end ez
#include<iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t,n,k;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        int check[101]={0,};
        int g;
        cin>>n>>k;
        for(int i=0; i<k; ++i)
        {
            cin>>g;
            check[g]=1;
        }
        cout<<"#"<<tc<<" ";
        for(int i=1; i<=n; ++i)
        {
            if(check[i]==0) cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}