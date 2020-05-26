#include<vector>
#include<algorithm>
#include<stack>
#include<array>
#include<iostream>

using namespace std;

vector<vector<int>> nboard;
int way[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int ans=0;
int n;

int checkmax()
{
    int max=0;
    for(int i=0; i<n; ++i){for(int j=0; j<n; ++j){if(nboard[i][j]>max) max=nboard[i][j];}}
    if(max>ans) ans=max;
    return max;
}

void move(int w)
{
    for(int i=0; i<n; ++i)
    {
        stack<int> bucket;
        array<int,2> stp;
        array<int,2> index;
        if(w==0){ stp={n-1,i}; index={n-1,i};}
        else if(w==1){stp={0,i}; index={0,i};}
        else if(w==2){stp={i,0}; index={i,0};}
        else if(w==3){stp={i,n-1}; index={i,n-1};}
        
        for(int j=0; j<n; ++j)
        {
            if(nboard[stp[0]][stp[1]]==0){stp[0]+=way[w][0]; stp[1]+=way[w][1]; continue;}
            if(bucket.empty()){ bucket.push(nboard[stp[0]][stp[1]]); nboard[stp[0]][stp[1]]=0;}
            else
            {
                int topp=bucket.top();
                int pres=nboard[stp[0]][stp[1]];
                nboard[stp[0]][stp[1]]=0;
                bucket.pop();
                if(topp==pres) nboard[index[0]][index[1]]=(pres<<1);
                else
                {
                    nboard[index[0]][index[1]]=topp;
                    bucket.push(pres);
                }
                index[0]+=way[w][0]; index[1]+=way[w][1];
            }
            stp[0]+=way[w][0]; stp[1]+=way[w][1];
        }
        if(!bucket.empty()) nboard[index[0]][index[1]]=bucket.top();
    }
}

void dfs(int depth)
{
    if(depth>5) return;
    int maxv=checkmax();
    if((maxv<<(5-depth))<=ans) return;
    vector<vector<int>> oboard;
    oboard.clear();
    oboard.assign(nboard.begin(),nboard.end());
    for(int i=0; i<4; ++i)
    {
        move(i);
        dfs(depth+1);
        nboard.clear();
        nboard.assign(oboard.begin(),oboard.end());
    }
}

int main(void)
{
    cin>>n;
    
    for(int i=0; i<n; ++i)
    {
        vector<int> rows;
        for(int j=0; j<n; ++j)
        {
            int temp;
            cin>>temp;
            rows.push_back(temp);
        }
        nboard.push_back(rows);
    }
    dfs(0);
    cout<<ans;
	return 0;
}


