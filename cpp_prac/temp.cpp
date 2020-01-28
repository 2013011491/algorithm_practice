#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(void)
{
    //cin.tie(NULL);
    //ios::sync_with_stdio(false);

    int oplen;
    string op;
    for(int tc=1; tc<=1; ++tc)
    {
        cout<<"#"<<tc<<" ";
        
        cin>>oplen>>op;

        int pres;
        vector<char> oper;
        vector<int> num;

        for(int i=0; i<oplen; ++i)
        {
            cout<<i<<"\n";
            if(op[i]=='(') oper.push_back('(');
            else if(op[i]=='+')
            { 
                oper.push_back('+');
            }else if(op[i]=='*')
            {
                if(op[i+1]=='(')
                {
                    oper.push_back('*');
                }else
                {
                    pres=num.back();
                    num.pop_back();
                    pres*=(op[i+1]-'0');
                    num.push_back(pres);
                    ++i;
                }
            }else if(op[i]==')')
            {
                cout<<i<<" ";
                while(oper.back()!='(')
                {
                    oper.pop_back();
                    pres=num.back();
                    num.pop_back();
                    pres+=num.back();
                    num.pop_back();
                    num.push_back(pres);
                }
                oper.pop_back();
                if(!oper.empty() && oper.back()=='*')
                {
                    pres=num.back();
                    num.pop_back();
                    pres*=num.back();
                    num.pop_back();
                    num.push_back(pres);
                }
            }else
            {
                num.push_back(op[i]-'0');
            }

            for(int j=0; j<oper.size(); ++j){ cout<<oper[j]<<" ";}
            cout<<"\n";
            for(int j=0; j<num.size(); ++j){ cout<<num[j]<<" ";}
            cout<<"\n";
            
        }
        pres=0;
        while(!num.empty())
        {
            pres+=num.back();
            num.pop_back();
        }
        cout<<pres<<"\n";
    }
    return 0;
}