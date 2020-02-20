//200220 14:36 start d3 21.76%
#include<iostream>

using namespace std;

long long combi(long long n, long long r)
{
    if(n==r || r==0) return 1;
    return combi(n-1, r-1)+combi(n-1,r);
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    long long n,r;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n>>r;
        cout<<"#"<<tc<<" "<<combi(n,r)%1234567891<<"\n";
    }

    return 0;
}