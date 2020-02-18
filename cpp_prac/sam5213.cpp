#include<iostream>
#include<array>

using namespace std;
array<long long, 1000001> num={0,};

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    long long left,right;
    for(int i=1; i<=1000000; i+=2)
    {
        for(int j=1; (j*i)<=1000000; ++j)
        {
            num[(i*j)]+=i;
        }
    }
    for(int i=1; i<1000001; ++i)
    {
        num[i]+=num[i-1];
    }
    cin>>t;
    for(int tc=1;tc<=t; ++tc)
    {
        cin>>left>>right;
        cout<<"#"<<tc<<" ";
        cout<<num[right]-num[left-1]<<"\n";
    }
    return 0;
}