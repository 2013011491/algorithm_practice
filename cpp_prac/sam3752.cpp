#include<iostream>
#include<set>
#include<array>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,n;
    int sum=0;
    cin>>t;
    for(int tc=0; tc<t; tc++)
    {
        cin>>n;
        set<long long> bucket;
        long long sum[n];
        int data[n];
        bucket.insert(0);
        for(int i=0; i<n; i++)
        {
            cin>>data[i];
            sum[i]=data[0];
            bucket.insert(data[i]);
        }
        cout<<"#"<<tc+1<<" ";

        for(int i=0; i<n-1; i++)
        {
            for(int l=i+1; l<n; l++) sum[l]=data[i];
            for(int k=i+1; k<n; k++)
            {
                for(int j=k; j<n; j++)
                {
                    sum[j-k+i+1]+=data[j];
                    bucket.insert(sum[j-k+i+1]);
                }
            }
        }

        cout<<bucket.size()<<"\n";
    }
    return 0;
}