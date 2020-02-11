//200210 20:15 start d2 80.29%  20:20 end
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
        cout<<"#"<<tc<<" ";

        int check=1;
        for(int i=0; i<str.size()/2; ++i)
        {
            if(str[i]!=str[str.size()-1-i])
            {
                check=0;
                break;
            }
        }
        cout<<check<<"\n";
    }
    return 0;
}