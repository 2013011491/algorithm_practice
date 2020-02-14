//200214 16:40 start D2 71.99%  16:49 end
#include<iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,n;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n;
        int minman=100001;
        int nmin=0;
        int pres;
        for(int i=0; i<n; ++i)
        { 
            cin>>pres; 
            if(pres<0) pres*=(-1);
            if(pres<minman)
            {
                minman=pres;
                nmin=1;
            }else if(pres==minman)
            {
                nmin++;
            }
        }
        cout<<"#"<<tc<<" "<<minman<<" "<<nmin<<"\n";
    }
    return 0;
}