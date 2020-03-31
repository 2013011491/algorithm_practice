//20324 16:56 start d4 51.55%
#include<iostream>
#include<string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    string str;

    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>str;
        int trans[256]={0,};
        int ans=0;
        for(int i=0; i<str.size(); ++i){trans[str[i]]++;}
        for(int i=0; i<26; ++i){ans+=(trans['a'+i]*(trans['a'+i]+1)/2);}
        cout<<"#"<<tc<<" "<<ans<<"\n";
    }
    return 0;
}