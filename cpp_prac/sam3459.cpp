#include<iostream>
#include<array>
#include<stack>
#include<string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    long long n;

    cin>>t;
    for(int tc=0; tc<t; tc++)
    {
        cin>>n;
        cout<<"#"<<tc+1<<" ";


        //start
        if(n==1)
        {
            cout<<"Bob\n";
            continue;
        }

        long long x=2,y=6;
        
        while(1)
        {
            if(x<=n && n<y)
            {
                cout<<"Alice\n";
                break;
            }else if(n<x)
            {
                cout<<"Bob\n";
                break;
            }
            x=4*x+2;
            y=4*y+2;
        }
    }
    return 0;
}