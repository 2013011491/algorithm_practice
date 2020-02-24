//200224 15:52 start d3 84.07% start 15:58 end  so so ez
#include<iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    long long l,u,x;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>l>>u>>x;
        cout<<"#"<<tc<<" "<<(x<l ? l-x : (x>u ? -1 : 0))<<"\n";
    }
    return 0;
}