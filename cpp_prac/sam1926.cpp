//200204 13:19 start 13:30 end
#include<iostream>
#include<string>

using namespace std;

int check_369(int pres)
{
    int result=0;
    while(pres!=0)
    {
        int digit=pres%10;
        if(digit==3 || digit==6 || digit==9) ++result;
        pres/=10;
    }
    return result;
}

int main(void)
{
    int n;
    cin>>n;

    for(int i=1; i<=n; ++i)
    {
        int tsn=check_369(i);
        if(tsn==0) cout<<i<<" ";
        else
        { 
            for(int j=0; j<tsn; ++j){ cout<<"-"; }
            cout<<" ";
        }
    }
    return 0;
}