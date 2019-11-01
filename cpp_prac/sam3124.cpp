#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;


bool arraycomp(array<int,3> lhs, array<int,3> rhs) 
{
    return lhs[2]>rhs[2];
}

int vertex[100002];

int find_ele(int x)
{
    if(vertex[x]==x) return x;
    else return vertex[x]=find_ele(vertex[x]);
}

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++)
    {
        cout<<"#"<<tc<<" ";
        int v,e,s,d,w;
        long long answer=0;
        cin>>v>>e;
        for(int i=1; i<=v; i++) vertex[i]=i;
        vector<array<int,3>> bucket;

        for(int i=0; i<e; i++)
        {  
            cin>>s>>d>>w;
            bucket.push_back({s,d,w});
        }
        sort(bucket.begin(),bucket.end(),arraycomp);
        /*for(int i=0; i<e; i++)
        {
            for(int j=0; j<3; j++) cout<<bucket[i][j]<<" ";
            cout<<"\n";
        }*/
        int check=0;
        while(check!=v-1)
        {
            array<int,3> pres=bucket.back();
            bucket.pop_back();
            int first=find_ele(pres[0]);
            int second=find_ele(pres[1]);
            if(first!=second)
            {
                vertex[second]=first;
                answer+=pres[2];
                check++;
            }
        }
        cout<<answer<<"\n";
    }
    return 0;
}