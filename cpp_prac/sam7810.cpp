//200323 21:12 start d4 29.68%
#include<iostream>
#include<map>

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
        int ans=0;
        map<int,int> arr;
        map<int,int>::reverse_iterator rit;
        for(int i=0; i<n; ++i)
        {
            int temp;
            cin>>temp;
            if(temp>=n) arr[n]++;
            else arr[temp]++;
        }
        long long prev=0;
        for(rit=arr.rbegin(); rit!=arr.rend(); ++rit)
        {
            if((rit->first)<=prev)
            {
                ans=prev;
                break;
            }
            prev+=(rit->second);
            if(prev>=(rit->first))
            {
                ans=rit->first;
                break;
            }
        }
        cout<<"#"<<tc<<" "<<ans<<"\n";
    }
    return 0;
}