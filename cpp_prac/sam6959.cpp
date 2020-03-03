//200303 21:45 start d4 40.06%
#include<iostream>
#include<string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int t;
    string num;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>num;
        cout<<"#"<<tc<<" ";
        int check=0;
        while(num.size()>1)
        {
            int a=num[0]-'0';
            int b=num[1]-'0';
            a+=b;
            string temp;
            if(a>=10)
            {
                temp.push_back(a/10+'0');
                temp.push_back(a%10+'0');
            }else temp.push_back(a+'0');
            num=temp+num.substr(2);
            check=(check+1)%2;
        }
        string winner;
        if(check==0) winner="B";
        else winner="A";
        cout<<winner<<"\n";
    }
    return 0;
}