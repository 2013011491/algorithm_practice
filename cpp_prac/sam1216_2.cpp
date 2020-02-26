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
    for(int tt=1; tt<=1; ++tt)
    {
        cin>>tc;
        for(int i=0; i<100; ++i){ cin>>board[i]; }
        cout<<"#"<<tc<<" ";
        
        int maxlen=1;
        for(int i=0; i<100; ++i)
        {
            string rowstr;
            for(int j=0; j<100; ++j){ rowstr.push_back(board[j][i]);}
            for(int j=0; j<99; ++j)
            {
                int k=1;
                while(1)
                {
                    if(j>=k && j+k<=99)
                    {
                        if(ispal(board[i].substr(j-k,2*k+1)))
                        {
                            if(2*k+1>maxlen){ maxlen=2*k+1; }
                            k++;
                        }else break;
                    }else break;
                }
                if(board[i][j]==board[i][j+1])
                {
                    k=1;
                    while(1)
                    {
                        if(j>=k && j+k<=98)
                        {
                            if(ispal(board[i].substr(j-k,2*k+2)))
                            {
                                if(2*k+2>maxlen){ maxlen=2*k+2; }
                                k++;
                            }else break;
                        }else break;
                    }
                }
                k=1;
                while(1)
                {
                    if(j>=k && j+k<=99)
                    {
                        if(ispal(rowstr.substr(j-k,2*k+1)))
                        {
                            if(2*k+1>maxlen){ maxlen=2*k+1; }
                            k++;
                        }else break;
                    }else break;
                }
                if(rowstr[j]==rowstr[j+1])
                {
                    k=1;
                    while(1)
                    {
                        if(j>=k && j+k<=98)
                        {
                            if(ispal(rowstr.substr(j-k,2*k+2)))
                            {
                                if(2*k+2>maxlen){ maxlen=2*k+2; }
                                k++;
                            }else break;
                        }else break;
                    }
                }
            }
        }
        cout<<maxlen<<"\n";
    }
    return 0;
}