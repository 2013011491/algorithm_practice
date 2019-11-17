//2019-11-14 20:02~21:34
#include <iostream>
#include <string>
#include <array>
#include <stack>
#include <climits>

using namespace std;

long long calculop(string opt, long long a, long long b)
{
    if(opt=="+") return a+b;
    if(opt=="*") return a*b;
    if(opt=="-") return a-b;
}

long long calculop(string opt)
{
    int a=opt[0]-'0';
    int b=opt[2]-'0';
    if(opt[1]=='+') return a+b;
    if(opt[1]=='*') return a*b;
    if(opt[1]=='-') return a-b;
}

int main(void)
{
    int n;
    string exp;
    long long ans=LONG_MIN;
    stack<array<string,2>> bucket;
    stack<array<long long,2>> bucketp;
    array<string,2> pres;
    array<long long,2> presp;
    cin>>n>>exp;
    int maxop=n/2;
    if(n==1)
    {
        cout<<exp;
        return 0;
    }
    //start
    bucket.push({"",exp});
    bucketp.push({0,0});
    while(!bucket.empty())
    {
        pres=bucket.top();
        bucket.pop();
        presp=bucketp.top();
        bucketp.pop();

        if(presp[1]==maxop)
        {
            long long temp=calculop(pres[0],presp[0],pres[1][0]-'0');
            if(temp>ans) ans=temp;
            continue;
        }else if(presp[1]>maxop)
        {
            if(presp[0]>ans) ans=presp[0];
            continue;
        }

        if(pres[0]=="")
        {
            bucketp.push({pres[1][0]-'0',presp[1]+1});
            bucket.push({pres[1].substr(1,1),pres[1].substr(2)});

            if(pres[1].size()>3)
            {
                bucketp.push({calculop(pres[1].substr(0,3)),presp[1]+2});
                bucket.push({pres[1].substr(3,1),pres[1].substr(4)});
            }

        }else
        {
            bucketp.push({calculop(pres[0],presp[0],pres[1][0]-'0'),presp[1]+1});
            bucket.push({pres[1].substr(1,1),pres[1].substr(2)});
            
            if(pres[1].size()>3)
            {
                bucketp.push({calculop(pres[0],presp[0],calculop(pres[1].substr(0,3))),presp[1]+2});
                bucket.push({pres[1].substr(3,1),pres[1].substr(4)});
            }else if(pres[1].size()==3)
            {
                bucketp.push({calculop(pres[0],presp[0],calculop(pres[1].substr(0,3))),presp[1]+2});
                bucket.push({"",""});
            }
        }
    }
    cout<<ans;
    return 0;
}
