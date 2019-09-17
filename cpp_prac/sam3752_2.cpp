#include<iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,n,c;
    cin>>t;
    for(int tc=0; tc<t; tc++)
    {
        cin>>n;
        int data[n];
        int temp[10001]={0,};
        for(int i=0; i<n; i++) cin>>data[i];
        temp[0]=1;
        temp[data[0]]=1;
        int sum=data[0];
        cout<<"#"<<tc+1<<" ";
        for(int j=1; j<n; j++)
        {
            for(int i=sum; i>=0; i--)
            {
                if(temp[i]==1) temp[i+data[j]]=1;
            }
            sum+=data[j];
        }
        int check=0;
        for(int i=0; i<=sum; i++) if(temp[i]==1) check++;
        
        cout<<check<<"\n";

    }
    return 0;
}