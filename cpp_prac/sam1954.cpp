//200204 14:52 start  15:20 end
#include<iostream>

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
        cout<<"#"<<tc<<"\n";

        int slug[10][10]={0,};
        int st=0,i=0,j=0;
        int end=n-1;
        int num=1;
        while(num<=n*n)
        {
            slug[i][j]=num++;
            if(i==st+1 && j==st)
            {
                ++st,--end;
                i=j=st;
            }
            else if(i==st && j<end) ++j;
            else if(i<end && j==end) ++i;
            else if(i==end && j>st) --j;
            else if(i>st && j==st) --i;
        }
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j){ cout<<slug[i][j]<<" "; }
            cout<<"\n";
        }
    }
    return 0;
}