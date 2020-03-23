//200323 21:12 start d4 29.68% ver2 more fast using just array
#include<iostream>

using namespace std;


int arr[500000]={0,};

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,n;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n;
        int ans=0;
        for(int i=0; i<=n; ++i){arr[i]=0;}
        for(int i=0; i<n; ++i)
        {
            int temp;
            cin>>temp;
            if(temp>=n) arr[n]++;
            else arr[temp]++;
        }
        long long prev=0;
        for(int i=n; i>=0; --i)
        {
            if(arr[i]!=0)
            {
                if(prev>=i)
                {
                    ans=prev;
                    break;
                }
                prev+=arr[i];
                if(prev>=i)
                {
                    ans=i;
                    break;
                }
            }
        }
        cout<<"#"<<tc<<" "<<ans<<"\n";
    }
    return 0;
}