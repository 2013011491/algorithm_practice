#include<iostream>
#include<string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int oplen;
    string op;
    for(int tc=1; tc<=10; ++tc)
    {
        cout<<"#"<<tc<<" ";
        
        cin>>oplen>>op;

        int ans=0;
        for(int i=0; i<oplen; ++i)
        {
            if(op[i]!='+') ans+=(op[i]-'0');
        }
        cout<<ans<<"\n";
    }
    return 0;
}