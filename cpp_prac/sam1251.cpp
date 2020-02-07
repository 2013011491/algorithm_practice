//200206 21:02 start d4 65.68%  20:10 end
#include<iostream>
#include<array>

using namespace std;

array<array<long long,2>,1000> island;
long long vertex[1000][1000]={0,};
long long ans[1001]={0,};

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(0);

    int t,n;
    double e;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n;
        cout<<"#"<<tc<<" ";
        for(int i=0; i<n; ++i){ cin>>island[i][0]; }
        for(int i=0; i<n; ++i){ cin>>island[i][1]; }
        cin>>e;

        double sum=0;
        for(int i=0; i<n; ++i)
        {
            array<long long,2> pres=island[i];
            for(int j=i+1; j<n; ++j)
            {
                array<long long,2> next=island[j];
                vertex[i][j] = (next[0]-pres[0])*(next[0]-pres[0]) + (next[1]-pres[1])*(next[1]-pres[1]);
                vertex[j][i] = vertex[i][j];
            }
        }
        /*for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j){ cout<<vertex[i][j]<<" ";}
            cout<<"\n";
        }*/
        for(int i=0; i<n-1; ++i)
        {
            long long min = 2000000000001;
            int mindex=0;
            for(int j=0; j<n; ++j)
            {
                if(vertex[0][j]!=0 && vertex[0][j]<min)
                {
                    min=vertex[0][j];
                    mindex=j;
                } 
            }
            ans[i]=min;
            vertex[0][mindex]=0;
            for(int j=0; j<n; ++j)
            {
                if(vertex[0][j]!=0 && vertex[mindex][j]<vertex[0][j]) vertex[0][j]=vertex[mindex][j];
            }
        }
        for(int i=0; i<n-1; ++i)
        {
            sum+=(ans[i]*e);
        }
        cout<<sum<<"\n";
    }
    return 0;
}