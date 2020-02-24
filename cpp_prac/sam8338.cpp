//200224 16:00 start D3 38.49%  16:14 end
#include<iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t,n;
    int arr[10]={0,};
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n;
        for(int i=0; i<n; ++i){ cin>>arr[i]; }
        long long ans=0;
        for(int i=0; i<n; ++i)
        {
            if(ans==1 || ans==0 || arr[i]==1 || arr[i]==0) ans+=arr[i];
            else ans*=arr[i];
        }
        cout<<"#"<<tc<<" "<<ans<<"\n";
    }
    return 0;

}