//200214 15:39 start D2 81.23%   16:00 end
#include<iostream>
#include<string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    long long n;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n;
        cout<<"#"<<tc<<" ";

        int pres;
        int i=1;
        string check="0000000000";
        while(check!="1111111111")
        {
            pres=n*(i++);
            while(pres!=0)
            {
                check[pres%10]='1';
                pres/=10;
            }
        }
        cout<<n*(i-1)<<"\n";
    }
    return 0;
}