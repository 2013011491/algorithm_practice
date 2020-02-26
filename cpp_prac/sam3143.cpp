//200226 17:07 start d4 47.04%  17:19 ez
#include<iostream>
#include<string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    string a,b;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>a>>b;
        cout<<"#"<<tc<<" ";
        if(b.size()>a.size())
        {
            cout<<a.size()<<"\n";
            continue;
        }
        int ans=0;
        for(int i=0; i<a.size(); ++i)
        {
            ans++;
            if(a.substr(i,b.size())==b) i+=(b.size()-1);
        }
        cout<<ans<<"\n";
    }
    return 0;
}