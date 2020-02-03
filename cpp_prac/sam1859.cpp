//200203 14:52 start  15:17 end
#include<iostream>

using namespace std;

int price[1000002]={0,};
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,n;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cout<<"#"<<tc<<" ";
        cin>>n;
        int maxindex=0;
        int startindex=0;
        long long ans=0;
        for(int i=0; i<n; ++i)
        {
            cin>>price[i];
            if(price[i]>=price[maxindex]) maxindex=i;
        }
        for(int j=startindex; j<maxindex; ++j)
        {
            ans+=(price[maxindex]-price[j]);
        }
        startindex=(++maxindex);


        while(maxindex!=n)
        {
            for(int i=startindex; i<n; ++i)
            {
                if(price[i]>=price[maxindex]) maxindex=i;
            }
            for(int j=startindex; j<maxindex; ++j)
            {
                ans+=(price[maxindex]-price[j]);
            }
            startindex=(++maxindex);
        }
        cout<<ans<<"\n";
    }
    return 0;
}