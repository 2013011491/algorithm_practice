//200210 20:32 start d2 61.43%  20:41 end
#include<iostream>
#include<array>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int t,n;
    array<int,8> money={50000, 10000, 5000, 1000, 500, 100, 50, 10};
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n;
        cout<<"#"<<tc<<"\n";
        for(int i=0; i<money.size(); ++i)
        {
            cout<<n/money[i]<<" ";
            n%=money[i];
        }
        cout<<"\n";
    }
    return 0;
}