//200316 17:08 start d4 27.27%
#include<iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    long long n,k;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        int answer=1;
        cin>>n>>k;
        if(n>=k) answer=k;
        else 
        {
            for(int i=n; i>0; --i)
            {
                if(k==1) break;
                if(k%i==0)
                {
                    answer*=i;
                    k/=i;
                }
            }
        }
        cout<<"#"<<tc<<" "<<answer<<"\n";
    }
    return 0;
}