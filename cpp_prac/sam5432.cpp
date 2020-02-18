//200215 17:47 start D4 59.01% 18:18
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
        int st=0;
        int ans=0;
        for(int i=0; i<str.size(); ++i)
        {
            if(str[i]=='(' && str[i+1]==')')
            {
                ans+=st;
                i++;
            }else if(str[i]=='(')
            {
                st++;
                ans++;
            }else if(str[i]==')') st--;
        }
        cout<<"#"<<tc<<" "<<ans<<"\n";
    }
    return 0;
}