//페르마의 소정리 n^p =- n (mod p)
//A*B^-1  % P
//(AB^p-2)%p
//((A%p)(B^(p-2)%p))%p
#include<iostream>

using namespace std;


long long fac[1000001]={0,};
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    long long n,r;
    long long p=1234567891;
    fac[1]=1;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n>>r;
        if(fac[n]==0)
        {
            for(int i=2; i<=n; ++i)
            {
                if(fac[i]==0) fac[i]=(fac[i-1]*i)%p;
            }
        }
        long long a=fac[n];
        long long y=p-2;
        long long x=(fac[r]*fac[n-r])%p;
        long long ret=1;
        while(y>0)
        {
            if(y%2)
            {
                ret*=x;
                ret%=p;
            }
            x*=x;
            x%=p;
            y/=2;
        }
        long long ans=((a%p)* (ret%p))%p;
        cout<<"#"<<tc<<" "<<ans<<"\n";
    }

    return 0;
}