//2019-11-13 18:58
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int popul[11]={0,};
int graph[11][11]={0,};

int main(void)
{
    int n;
    int ans=60000;
    cin>>n;
    queue<vector<int>> bucket;
    for(int i=0; i<n; ++i)
    {
        int temp;
        cin>>temp;
        popul[i]=temp;
    }
    for(int i=0; i<n; ++i)
    {
        int temp;
        cin>>temp;
        for(int j=0; j<temp; ++j)
        {
            int temp2;
            cin>>temp2;
            graph[i][temp2-1]=1;
            graph[temp2-1][i]=1;
        }
    }

    //start
    bucket.push({0});
    while(!bucket.empty())
    {
        int visited[11]={0,};
        vector<int> pres=bucket.front();
        bucket.pop();
        for(int i=0; i<pres.size(); ++i){visited[pres[i]]=1;}
        for(int j=0; j<n; ++j)
        {
            if(graph[pres[pres.size()-1]][j]==1 && !visited[j])
            {
                vector<int> t=pres;
                t.push_back(j);
                bucket.push(t);
            }
        }
        
        queue<int> temp;
        for(int i=0; i<n; ++i)
        {
            if(!visited[i])
            {
                temp.push(i);
                break;
            }
        }

        while(!temp.empty())
        {
            int qhead=temp.front();
            temp.pop();
            if(!visited[qhead])
            {
                visited[qhead]=2;
                for(int i=0; i<n; ++i)
                {
                    if(graph[qhead][i]==1) temp.push(i);
                }
            } 
        }
        int check=0;
        int sum1=0,sum2=0;
        for(int i=0; i<n; ++i)
        {
            if(visited[i]==1) sum1+=popul[i];
            else if(visited[i]==2) sum2+=popul[i];
            else
            {
                check=1;
                break;
            }   
        }
        if(!check)
        {
            int sub;
            if(sum1>sum2) sub=sum1-sum2;
            else sub=sum2-sum1;

            if(ans>sub) ans=sub;
        }
    }
    if(ans==60000) cout<<-1;
    else cout<<ans;

    return 0;
}