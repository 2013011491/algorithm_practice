#include<iostream>
#include<stack>
#include<array>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,n;
    cin>>t;
    for(int tc=0; tc<t; tc++)
    {
        cin>>n;
        int room[n][n];
        int visited[n][n];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++) visited[i][j]=0;
        }
        int leng,st;
        stack<array<int,2>> bucket;
        array<int,2> max={0,0};
        array<int,2> pres;
        int presV;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++) cin>>room[i][j];
        }
        cout<<"#"<<tc+1<<" ";

        //start
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!visited[i][j])
                {
                    bucket.push({i,j});
                    st=room[i][j];
                    leng=0;
                }
                while(!bucket.empty())
                {
                    pres=bucket.top();
                    bucket.pop();
                    presV=room[pres[0]][pres[1]];
                    leng++;
                    visited[pres[0]][pres[1]]=1;
                    if(pres[1]<n-1 && room[pres[0]][pres[1]+1]==presV+1) bucket.push({pres[0],pres[1]+1});
                    else if(pres[0]<n-1 && room[pres[0]+1][pres[1]]==presV+1) bucket.push({pres[0]+1,pres[1]});
                    else if(pres[0]>0 && room[pres[0]-1][pres[1]]==presV+1) bucket.push({pres[0]-1,pres[1]});
                    else if(pres[1]>0 && room[pres[0]][pres[1]-1]==presV+1) bucket.push({pres[0],pres[1]-1});
                }
                if(leng>max[1])
                {
                    max[0]=st;
                    max[1]=leng;
                }else if(leng==max[1] && st<max[0]) max[0]=st;
            }
        }
        cout<<max[0]<<" "<<max[1]<<"\n";
    }
    return 0;
}