#include<iostream>
#include<string>
#include<stack>

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

        int pres;
        stack<char> oper;
        stack<int> num;

        for(int i=0; i<oplen; ++i)
        {

            if(op[i]=='(') oper.push('(');
            else if(op[i]=='+')
            { 
                oper.push('+');
            }else if(op[i]=='*')
            {
                if(op[i+1]=='(')
                {
                    oper.push('*');
                }else
                {
                    pres=num.top();
                    num.pop();
                    pres*=(op[i+1]-'0');
                    num.push(pres);
                    ++i;
                }
            }else if(op[i]==')')
            {
                while(oper.top()!='(')
                {
                    oper.pop();
                    pres=num.top();
                    num.pop();
                    pres+=num.top();
                    num.pop();
                    num.push(pres);
                }
                oper.pop();
                if(!oper.empty() && oper.top()=='*')
                {
                    oper.pop();
                    pres=num.top();
                    num.pop();
                    pres*=num.top();
                    num.pop();
                    num.push(pres);
                }
            }else
            {
                num.push(op[i]-'0');
            }
            
        }
        pres=0;
        while(!num.empty())
        {
            pres+=num.top();
            num.pop();
        }
        cout<<pres<<"\n";
    }
    return 0;
}