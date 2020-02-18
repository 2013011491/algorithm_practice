//200218 16:00 start D3 39.99%  16:32 end
#include<iostream>
#include<string>
#include<array>
#include<algorithm>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t,n,m,k;
    array<int,101> arr;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n>>m>>k;
        int sum=0;
        string ans="Possible";
        for(int i=0; i<n; ++i){ cin>>arr[i]; }
        sort(arr.begin(),arr.begin()+n);
        for(int i=0; i<n; ++i)
        {
            int pres=(arr[i]/m)*k-sum;
            if(pres<=0)
            {
                ans="Impossible";
                break;
            }
            sum++;
        }
        cout<<"#"<<tc<<" "<<ans<<"\n";
    }
    return 0;
}