//200327 17:09 start d4 17.88
#include<iostream>
#include<string>
#include<map>
#include<stack>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t,k;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>k;
        int count=1;
        string ans="Yes";
        int check=1;
        map<string,int> trans;
        int graph[16][16]={0,};
        int visit[16]={0,};
        for(int i=0; i<k; ++i)
        {
            string a,b;
            cin>>a>>b;
            if(trans[a]==0) trans[a]=count++;
            if(trans[b]==0) trans[b]=count++;
            graph[trans[a]][trans[b]]=1;
            graph[trans[b]][trans[a]]=1;
        }
        int limit=count-1;
        stack<int> bucket;
        bucket.push(1);
        visit[1]=1;
        while(!bucket.empty())
        {
            int stp=bucket.top();
            bucket.pop();
            for(int i=1; i<=limit; ++i)
            {
                if(i==stp) continue;
                if(graph[stp][i]==0)
                {
                    if(visit[i]==0)
                    {
                        visit[i]=visit[stp];
                        bucket.push(i);
                    }else if(visit[i]!=visit[stp])
                    {
                        check=0;
                        ans="No";
                        break;
                    }
                }else
                {
                    if(visit[i]==0)
                    {
                        visit[i]=visit[stp]%2 + 1;
                        bucket.push(i);
                    }else if(visit[i]==visit[stp])
                    {
                        check=0;
                        ans="No";
                        break;
                    }
                }
            }
            if(check==0) break;
        }
        cout<<"#"<<tc<<" "<<ans<<"\n";
    }
    return 0;
}