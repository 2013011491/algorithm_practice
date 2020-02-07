//200206 20:31 start d3 84.20% 20:52 end
#include<iostream>
#include<string>
#include<array>

using namespace std;

bool ispal(string str)
{
    int half=str.size()/2;
    for(int i=0; i<half; ++i)
    {
        if(str[i]!=str[str.size()-1-i]) return false;
    }
    return true;
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    array<string,8> board;
    for(int tc=1; tc<=10; ++tc)
    {
        cin>>n;
        for(int i=0; i<8; ++i){ cin>>board[i]; }
        cout<<"#"<<tc<<" ";

        if(n==1)
        {
            cout<<64<<"\n";
            continue;
        }
        int ans=0;
        for(int i=0; i<8; ++i)
        {
            for(int j=0; j<9-n; ++j)
            {
                if(ispal(board[i].substr(j,n))) ans++;
            }
        }
        for(int i=0; i<8; ++i)
        {
            string pres;
            for(int k=0; k<8; ++k)
            {
                pres.append(1,board[k][i]);
            }
            for(int j=0; j<9-n; ++j)
            {
                if(ispal(pres.substr(j,n))) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}