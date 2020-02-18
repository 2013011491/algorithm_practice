//200218 14:58 start D3 75.83%  15:46 48min
//짜증나는 문제 그냥 짜는거
#include<iostream>
#include<string>
#include<array>

using namespace std;


array<string,10> encryp={"0001101","0011001","0010011","0111101",
"0100011","0110001","0101111","0111011","0110111","0001011"};

int valitest(string str, int lasti)
{
    if(lasti<55) return 0;
    int index=1;
    int sum=0,ans=0;
    string ansstr=str.substr(lasti-55,56);
    for(int i=0; i<ansstr.size(); i+=7)
    {
        string pres=ansstr.substr(i,7);
        for(int j=0; j<10; ++j)
        {
            if(pres==encryp[j])
            {
                ans+=j;
                if(index%2==1) sum+=(3*j);
                else sum+=j;
                index++;
                break;
            }
        }
    }
    if(sum%10==0) return ans;
    else return 0;
}

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t,n,m;
    string pres;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n>>m;
        int ans=0;
        if(m<56)
        {
            cout<<0<<"\n";
            continue;
        } 
        int lasti=0;
        int isfind=0;
        for(int i=0; i<n; ++i)
        {
            cin>>pres;
            if(isfind==1) continue;
            for(int j=pres.size()-1; j>=0; --j)
            {
                if(pres[j]=='1')
                {
                    lasti=j;
                    isfind=1;
                    ans=valitest(pres,lasti);
                    break;
                }
            }
        }
        cout<<"#"<<tc<<" "<<ans<<"\n";
    }

    return 0;
}