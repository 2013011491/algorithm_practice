//200218 16:52 start D4 40.30% 17:30 end
//이진법 삼진법 변환의 경우 어느 변환이 가장 효율적인지 생각할것
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

long long twovalue(string binw)
{
    long long index=1;
    long long ans=0;
    for(int i=binw.size()-1; i>=0; --i)
    {
        if(binw[i]=='1') ans+=index;
        index*=2;
    }
    return ans;
}

string tentoth(long long ten)
{
    string ans="";
    while(ten!=0)
    {
        ans.push_back(char(ten%3)+'0');
        ten/=3;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

bool check(string nthree, string threw)
{
    if(nthree.size()!=threw.size()) return false;
    int sum=0;
    for(int i=0; i<nthree.size(); ++i)
    {
        if(nthree[i]!=threw[i])
        {
            if(sum==0) sum++;
            else return false;
        }
    }
    return true;
}


int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    string binw,threw;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>binw>>threw;
        cout<<"#"<<tc<<" ";
        long long twov=twovalue(binw);
        int index=1;
        for(int i=binw.size()-1; i>=0; --i)
        {
            long long pres;
            if(binw[i]=='0') pres=twov+index;
            else pres=twov-index;
            index*=2;
            string nthree=tentoth(pres);
            if(check(nthree,threw))
            {
                cout<<pres<<"\n";
                break;
            }
        }
    }
    return 0;
}