#include<iostream>

using namespace std;

int main(void)
{
    int n;
    cin>>n;

    int answer;
    int pre;
    for(int i=1; i<n; i++)
    {
        answer=i;
        pre=i;
        while(pre)
        {
            answer+=(pre%10);
            pre/=10;
        }
        if(answer==n)
        {
            cout<<i;
            return 0;
        }
    }    
    cout<<0;
    return 0;
}