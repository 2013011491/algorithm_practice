//2019-11-01 19:18~19:56
#include<iostream>
#include<vector>
#include<array>
#include<algorithm>

using namespace std;

int storage[102][102]={0,};

bool classcomp(array<int,2> lhs, array<int,2> rhs)
{
    if((lhs[0]*lhs[1])<(rhs[0]*rhs[1])) return true;
    else if((lhs[0]*lhs[1])==(rhs[0]*rhs[1])) return lhs[0]<rhs[0];
    else return false;
}

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int t;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cout<<"#"<<tc<<" ";

        int n;
        cin>>n;

        vector<array<int,2>> bucket;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++) cin>>storage[i][j];
            storage[i][n]=0;
        }
        for(int j=0; j<=n; j++) storage[n][j]=0;

        int col,row;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(storage[i][j]!=0)
                {
                    int k=j;
                    int l=i;
                    while(storage[l][k]!=0)
                    {
                        while(storage[l][k]!=0)
                        {
                            storage[l][k]=0;
                            k++;
                        }
                        l++;
                        col=k-j;
                        k=j;
                    }
                    row=l-i;
                    bucket.push_back({row,col});
                    j=j+col;
                }
            }
        }
        sort(bucket.begin(),bucket.end(),classcomp);
        cout<<bucket.size()<<" ";
        for(int i=0; i<bucket.size(); i++) cout<<bucket[i][0]<<" "<<bucket[i][1]<<" ";
        cout<<"\n";
    }
    return 0;
}