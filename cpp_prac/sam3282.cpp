//200303 15:14 start d3 27.15%
#include<iostream>
#include<array>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t,n,k;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n>>k;
        array<array<int,2>,102> vc;
        array<array<int,1001>,101> weight;
        for(int i=0; i<=k; ++i){weight[0][i]=0;}
        vc[0][0]=vc[0][1]=0;
        for(int i=1; i<=n; ++i){cin>>vc[i][0]>>vc[i][1];}
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=k; ++j)
            {
                if(j>=vc[i][0]) weight[i][j]=max(vc[i][1]+weight[i-1][j-vc[i][0]],weight[i-1][j]);
                else weight[i][j]=weight[i-1][j];
            }
        }
        cout<<"#"<<tc<<" "<<weight[n][k]<<"\n";
    }
    return 0;
}