//200207 18:03 start D3 33.80% 18:15 end 12min
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
        cout<<"#"<<tc<<" ";
        cin>>n;
        cout<<(1+(2*(n-1)*(n-1)))<<" "<<((2*n*n)-1)<<"\n";
    }
    return 0;
}