//200211 18:36 start d2 85.30%  18:43 end
#include<iostream>

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
        cout<<"#"<<tc<<" ";
        if(n%2==0) cout<<"-"<<n/2<<"\n";
        else cout<<n-(n/2)<<"\n";
    }
    return 0;
}