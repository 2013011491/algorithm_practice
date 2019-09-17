#include<iostream>
#include<stack>
#include<array>

#define MAX 90000
using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,n;
    char road[100][100];

    cin>>t;
    for(int tc=0; tc<t; tc++)
    {
        cin>>n;
        for(int i=0; i<n; i++) cin>>road[i];
        cout<<"#"<<tc+1<<" ";

        int check[100][100];
        fill_n(&check[0][0],sizeof(check)/sizeof(**check),MAX);
        int sum=0;
        int max=MAX;
        stack<array<int,3>> bucket;
        array<int,3> pres;
        bucket.push({0,0,0});

        while(bucket.size())
        {
            pres=bucket.top();
            bucket.pop();
            check[pres[0]][pres[1]]=pres[2];
            sum=(road[pres[0]][pres[1]]-'0')+pres[2];
            if(sum>=max) continue;
            
            if(pres[0]==n-1 && pres[1]==n-1)
            {
                max=sum;
                continue;
            }
            //cout<<pres[0]<<" "<<pres[1]<<" "<<pres[2]<<"\n";
//북
            if(pres[0]>0 && check[pres[0]-1][pres[1]]>sum) bucket.push({pres[0]-1,pres[1],sum});
//서            
            if(pres[1]>0 && check[pres[0]][pres[1]-1]>sum) bucket.push({pres[0],pres[1]-1,sum});
//남           
            if(pres[0]<n-1 && check[pres[0]+1][pres[1]]>sum) bucket.push({pres[0]+1,pres[1],sum});
//동            
            if(pres[1]<n-1 && check[pres[0]][pres[1]+1]>sum) bucket.push({pres[0],pres[1]+1,sum});
        }
        cout<<max<<"\n";
    }
    return 0;
}