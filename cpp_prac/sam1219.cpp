#include<iostream>
#include<stack>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int trash;
    int n;
    int x,y;
    for(int tc=0; tc<10; tc++)
    {
        cin>>trash>>n;
        stack<int> bucket;
        int line1[100]={0,};
        int line2[100]={0,};
        int check[100]={0,};
        for(int i=0; i<n; i++)
        {
            cin>>x>>y;
            if(line1[x]==0) line1[x]=y;
            else line2[x]=y;
        }

        cout<<"#"<<tc+1<<" ";
        bucket.push(0);
        check[0]=1;
        x=0;
        while(bucket.size())
        {
            n=bucket.top();
            bucket.pop();
            if(n==99)
            {
                x=1;
                break;
            }
            if(line1[n]!=0 && check[line1[n]]!=1) bucket.push(line1[n]);
            if(line2[n]!=0 && check[line2[n]]!=1) bucket.push(line2[n]);
        }
        cout<<(x==1 ? 1 : 0)<<"\n"; 
    }

    return 0;
}