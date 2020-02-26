//200225 16:36 start d3 80.00% 16:57 
//너무 무식하게 풀었음
#include<iostream>
#include<string>
#include<array>

using namespace std;

bool ispal(string str)
{
    for(int i=0; i<str.size()/2; ++i)
    {
        if(str[i]!=str[str.size()-1-i]) return false;
    }
    return true;
}

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int tc;
    array<string,100> board;
    for(int tt=1; tt<=10; ++tt)
    {
        cin>>tc;
        for(int i=0; i<100; ++i){ cin>>board[i]; }
        cout<<"#"<<tc<<" ";
        int maxlen=100;
        int check=1;
        for(maxlen; maxlen>1; --maxlen)
        {
            for(int i=0; i<100; ++i)
            {
                for(int j=0; j<=100-maxlen; ++j)
                {
                    if(ispal(board[i].substr(j,maxlen)))
                    {
                        check=0;
                        break;
                    }
                }
                if(check==0) break;
            }
            if(check==0) break;

            for(int i=0; i<100; ++i)
            {
                for(int j=0; j<=100-maxlen; ++j)
                {
                    string pres;
                    for(int k=j; k<maxlen+j; ++k){ pres.push_back(board[k][i]);}
                    if(ispal(pres))
                    {
                        check=0;
                        break;
                    }
                }
                if(check==0) break;
            }
            if(check==0) break;
        }
        if(check==0) cout<<maxlen<<"\n";
        else cout<<1<<"\n";
    }
    return 0;
}