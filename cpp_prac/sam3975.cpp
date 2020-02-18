//200218 15:50 start D3 38.93% 15:59 end
#include<iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,a,b,c,d;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>a>>b>>c>>d;
        cout<<"#"<<tc<<" ";
        int alice=a*d;
        int bob=b*c;
        if(alice>bob) cout<<"ALICE"<<"\n";
        else if(alice<bob) cout<<"BOB"<<"\n";
        else cout<<"DRAW"<<"\n";
    }
    return 0;
}