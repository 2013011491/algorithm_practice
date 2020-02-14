//200214 16:50 start D2 85.54%   17:50 end 60min ㅜㅜ
#include<iostream>
#include<string>
#include<map>
#include<bitset>

using namespace std;

string series="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int enco(char c)
{
    for(int i=0; i<series.size(); ++i)
    {
        if(series[i]==c) return i;
    }
}

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    string str,ans;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>str;
        cout<<"#"<<tc<<" ";
        for(int i=0; i<str.size(); i+=4)
        {
            int sum=0;
            for(int j=0; j<4; ++j)
            {
                sum=sum<<6;
                sum+=enco(str[i+j]);
            }
            string temp="aaa";
            for(int i=2; i>=0; --i)
            {
                temp[i]=sum%256;
                sum=sum>>8;
            }
            cout<<temp;
        }
        cout<<"\n";
    }
    return 0;
}