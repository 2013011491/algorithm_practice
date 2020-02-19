//200219 20:47 start D4 66.57% 21:09 basic!
#include<iostream>
#include<array>
#include<queue>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n,st,from,to;
    for(int tc=1; tc<=10; ++tc)
    {
        array<array<int,101>,101> netwk={0,};
        array<int,101> visit={0,};
        queue<array<int,2>> bucket;
        cin>>n>>st;
        for(int i=0; i<n/2; ++i)
        {
            cin>>from>>to;
            netwk[from][to]=1;
        }
        bucket.push({st,0});
        array<int,2> ans={st,0};
        visit[st]=1;
        while(!bucket.empty())
        {
            array<int,2> pres=bucket.front();
            bucket.pop();
            if(ans[1]<pres[1]) ans=pres;
            else if(ans[1]==pres[1] && ans[0]<pres[0]) ans=pres;
            for(int i=1; i<=100; ++i)
            {
                if(netwk[pres[0]][i]==1 && visit[i]==0)
                {
                    visit[i]=1;
                    bucket.push({i,pres[1]+1});
                }
            } 
        }
        cout<<"#"<<tc<<" "<<ans[0]<<"\n";
    }
    return 0;
}