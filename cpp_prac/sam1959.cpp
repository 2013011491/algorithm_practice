//200214 16:00 start D2 80.40%  16:12 end
#include<iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);


    int t,n,m;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cout<<"#"<<tc<<" ";
        cin>>n>>m;    
        int ai[20]={0,};
        int bj[20]={0,};
        for(int i=0; i<n; ++i){ cin>>ai[i]; }
        for(int i=0; i<m; ++i){ cin>>bj[i]; }
        int max=0;
        if(n<m)
        {
            for(int k=0; k<=m-n; ++k)
            {
                int sum=0;
                for(int i=0; i<n; ++i)
                {
                    sum+=(ai[i]*bj[i+k]);
                }
                if(sum>max) max=sum;
            }
        }else
        {
            for(int k=0; k<=n-m; ++k)
            {
                int sum=0;
                for(int i=0; i<m; ++i)
                {
                    sum+=(ai[i+k]*bj[i]);
                }
                if(sum>max) max=sum;
            }
        }
        cout<<max<<"\n";
    }
    return 0;
}