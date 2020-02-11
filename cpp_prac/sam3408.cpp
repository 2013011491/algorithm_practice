//200210 20:42 start D3 29.10% 20:49 end
#include<iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    long long n;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n;
        cout<<"#"<<tc<<" ";
        cout<<n*(n+1)/2<<" "<<n*n<<" "<<n*(n+1)<<"\n";
    }
    return 0; 
}