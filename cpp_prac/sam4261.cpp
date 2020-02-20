//200220 15:52 start d4 56.65%
#include<iostream>
#include<string>
#include<array>

using namespace std;

array<char,256> keypad;
string ston(string dic)
{
    string ans;
    for(int i=0; i<dic.size(); ++i){ans.push_back(keypad[dic[i]]);}
    return ans;
}

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    keypad['a']='2'; keypad['b']='2'; keypad['c']='2'; keypad['d']='3'; keypad['e']='3'; keypad['f']='3';
    keypad['g']='4'; keypad['h']='4'; keypad['i']='4'; keypad['j']='5'; keypad['k']='5'; keypad['l']='5';
    keypad['m']='6'; keypad['n']='6'; keypad['o']='6'; keypad['p']='7'; keypad['q']='7'; keypad['r']='7'; keypad['s']='7';
    keypad['t']='8'; keypad['u']='8'; keypad['v']='8'; keypad['w']='9'; keypad['x']='9'; keypad['y']='9'; keypad['z']='9';
    int t,n;
    string s;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        int ans=0;
        cin>>s>>n;
        for(int i=0; i<n; ++i)
        { 
            string dic;
            cin>>dic;
            if(dic.size()!=s.size()) continue;
            if(s==ston(dic)) ans++;
        }
        cout<<"#"<<tc<<" "<<ans<<"\n";
    }
    return 0;
}