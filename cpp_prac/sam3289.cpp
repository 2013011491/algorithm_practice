//2019-10-31, 20:37~21:43

#include<iostream>
#include<vector>

using namespace std;

int bucket[1000002];

int find_ele(int x)
{
    if(bucket[x]==x) return x;
    else return bucket[x]=find_ele(bucket[x])
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,n,m,op,a,b;

    cin>>t;
    for(int tc=1; tc<=t; tc++)
    {
        cout<<"#"<<tc<<" ";
        cin>>n>>m;
        for(int i=0; i<=n; i++) bucket[i]=i;

        for(int i=0; i<m; i++)
        {
            cin>>op>>a>>b;
            int first=find_ele(a);
            int second=find_ele(b);
            
            if(op==0 && first!=second)
            {
                bucket[second]=first;
            }else if(op==1)
            {
                if(first==second) cout<<1;
                else cout<<0;
            } 
        }
        cout<<"\n";
    }
    return 0;
}
