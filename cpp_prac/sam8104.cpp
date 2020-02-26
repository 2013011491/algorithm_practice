//200226 17:20 start d3 46.93%  18:07 
//concentrate!!
#include<iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    long long n,k;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n>>k;
        cout<<"#"<<tc<<" ";
        long long ans;
        if(n%2==0)
        {
            ans=n*(k*n+1)/2;
            for(int i=0; i<k; ++i){ cout<<ans<<" "; }
        }else
        {
            n--;
            ans=n*(k*n+1)/2 + n*k +1;
            for(int i=0; i<k; ++i){ cout<<ans+i<<" "; }
        }
        cout<<"\n";
    }
    return 0;
}