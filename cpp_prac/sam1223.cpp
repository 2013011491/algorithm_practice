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
        int pres;
        for(int i=0; i<oplen; ++i)
        {
            if(op[i]=='+')
            { 
                ans+=pres;
                pres=0;
            }else if(op[i]=='*')
            {
                pres*=(op[i+1]-'0');
                ++i;
            }else pres=(op[i]-'0');
        }
        ans+=pres;
        cout<<ans<<"\n";
    }
    return 0;
}