#include<iostream>
#include<set>
#include<array>

using namespace std;

int visited[100001];
struct classcomp
{
    bool operator() (const array<int,3> lhs, const array<int,3> rhs) const
    {
        if(lhs[2]<rhs[2])
        {
            return true;
        }else if(lhs[2]==rhs[2])
        {
            if(lhs[0]<rhs[0])
            {
                return true;
            }else if(lhs[0]==rhs[0])
            {
                if(lhs[1]<rhs[1]) return true;
                else return false;
            }else return false;
        }else return false;
        
    }
};

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,v,e;
    int st,end,val;
    cin>>t;
    for(int tc=0; tc<t; tc++)
    {
        cin>>v>>e;
        for(int i=0; i<=v; i++) visited[i]=0;
        set<array<int,3>,classcomp> bucket;
        for(int i=0; i<e; i++)
        {
            cin>>st>>end>>val;
            bucket.insert({st,end,val});
        }
        cout<<"#"<<tc+1<<" ";

        //start
        array<int,3> pres;
        int sum=0;
        int k=1;
        for(set<array<int,3>>::iterator it=bucket.begin(); it!=bucket.end(); ++it)
        {
            pres=*it;
            if(visited[pres[0]]==visited[pres[1]])
            {
                if(visited[pres[0]]==0   && visited[pres[1]]==0)
                {
                    visited[pres[0]]=k;
                    visited[pres[1]]=k;
                    k++;
                }else continue;
            }else
            {
                if(visited[pres[0]]==0) visited[pres[0]]=visited[pres[1]];
                else if(visited[pres[1]]==0) visited[pres[1]]=visited[pres[0]];
                else
                {
                    int temp=visited[pres[1]];
                    for(int i=1; i<=v; i++)
                    {
                        if(visited[i]==temp) visited[i]=visited[pres[0]];
                    }
                }
            }
            sum+=pres[2];
        }
        cout<<sum<<"\n";
    }

    return 0;
}