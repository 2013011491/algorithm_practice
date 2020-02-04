//200204 14:36 start 14:50 end
#include<iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,n;
    int pascal[12][12]={0,};
    pascal[0][1]=1;
    for(int i=1; i<10; ++i)
    {
        for(int j=1; j<i+2; ++j)
        {
            pascal[i][j] = pascal[i-1][j-1]+pascal[i-1][j];
        }
    }
    
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cout<<"#"<<tc<<"\n";
        cin>>n;
        for(int i=0; i<n; ++i)
        {
            for(int j=1; j<i+2; ++j){ cout<<pascal[i][j]<<" "; }
            cout<<"\n";
        }
    }
    return 0;
}