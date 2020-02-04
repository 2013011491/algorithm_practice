//200204 14:02 start   14:16 end
#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for(int tc=1; tc<=10; ++tc)
    {
        int tcn,pres;
        cin>>tcn;
        cout<<"#"<<tcn<<" ";

        int sum[202]={0,};
        for(int i=0; i<100; ++i)
        {
            for(int j=0; j<100; ++j)
            {
                cin>>pres;
                sum[i]+=pres;
                sum[j+100]+=pres;
                if(i==j) sum[200]+=pres;
                if(i+j == 99) sum[201]+=pres;
            }
        }
        int ans=sum[0];
        for(int i=0; i<202; ++i)
        {
            if(ans<sum[i]) ans=sum[i];
        }
        cout<<ans<<"\n";
    }
    return 0;
}