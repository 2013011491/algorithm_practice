#include<iostream>

using namespace std;

long long Dsum(long long n)
{
    long long sum=0;
    while(n!=0)
    {
        sum+=(n%10);
        n/=10;
    }
    return sum;
}

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    long long n;
    cin>>t;
    
    for(int tc=1; tc<=t; ++tc)
    {
        cout<<"#"<<tc<<" ";
        cin>>n;
        while(n>=10)
        {
            n=Dsum(n);
        }
        cout<<n<<"\n";
    }
    return 0;
}