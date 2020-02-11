//200211 19:21 start d2 59.24%   19::44 end 23min
#include<iostream>
#include<string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,n,k;
    char s;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n;
        string docu;
        for(int i=0; i<n; ++i)
        {
            cin>>s>>k;
            docu.append(k,s);
        }
        cout<<"#"<<tc<<"\n";
        for(int i=0; i<docu.size(); i+=10){ cout<<docu.substr(i,10)<<"\n"; }
    }
    return 0;
}