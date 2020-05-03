//200427 gold2 swexpert practice   for 49 min yeah!!!!  
#include<iostream>
#include<array>
#include<stack>
#include<cmath>

using namespace std;

int n;
array<array<int,23>,23> board={0,};
int ans=0;

void bup()
{
    for(int i=0; i<n; ++i)
    {
        array<int,23> temp={0,};
        stack<int> bucket;
        int index=0;
        for(int j=0; j<n; ++j)
        {
            if(board[j][i]==0) continue;
            if(bucket.empty()) bucket.push(board[j][i]);
            else
            {
                int pres=bucket.top();
                bucket.pop();
                if(pres==board[j][i]) temp[index++]=(board[j][i]<<1);
                else
                { 
                    temp[index++]=pres;
                    bucket.push(board[j][i]);
                }
            }
        }
        if(!bucket.empty()) temp[index]=bucket.top();
        for(int j=0; j<n; ++j){board[j][i]=temp[j];}
    }
}
void bdown()
{
    for(int i=0; i<n; ++i)
    {
        array<int,23> temp={0,};
        stack<int> bucket;
        int index=0;
        for(int j=n-1; j>=0; --j)
        {
            if(board[j][i]==0) continue;
            if(bucket.empty()) bucket.push(board[j][i]);
            else
            {
                int pres=bucket.top();
                bucket.pop();
                if(pres==board[j][i]) temp[index++]=(board[j][i]<<1);
                else
                { 
                    temp[index++]=pres;
                    bucket.push(board[j][i]);
                }
            }
        }
        if(!bucket.empty()) temp[index]=bucket.top();
        int k=0;
        for(int j=n-1; j>=0; --j){board[j][i]=temp[k++];}
    }
}
void bleft()
{
    for(int i=0; i<n; ++i)
    {
        array<int,23> temp={0,};
        stack<int> bucket;
        int index=0;
        for(int j=0; j<n; ++j)
        {
            if(board[i][j]==0) continue;
            if(bucket.empty()) bucket.push(board[i][j]);
            else
            {
                int pres=bucket.top();
                bucket.pop();
                if(pres==board[i][j]) temp[index++]=(board[i][j]<<1);
                else
                { 
                    temp[index++]=pres;
                    bucket.push(board[i][j]);
                }
            }
        }
        if(!bucket.empty()) temp[index]=bucket.top();
        for(int j=0; j<n; ++j){board[i][j]=temp[j];}
    }
}
void bright()
{
    for(int i=0; i<n; ++i)
    {
        array<int,23> temp={0,};
        stack<int> bucket;
        int index=0;
        for(int j=n-1; j>=0; --j)
        {
            if(board[i][j]==0) continue;
            if(bucket.empty()) bucket.push(board[i][j]);
            else
            {
                int pres=bucket.top();
                bucket.pop();
                if(pres==board[i][j]) temp[index++]=(board[i][j]<<1);
                else
                { 
                    temp[index++]=pres;
                    bucket.push(board[i][j]);
                }
            }
        }
        if(!bucket.empty()) temp[index]=bucket.top();
        int k=0;
        for(int j=n-1; j>=0; --j){board[i][j]=temp[k++];}
    }
}
int checkmax()
{
    int max=0;
    for(int i=0; i<n; ++i){for(int j=0; j<n; ++j){if(board[i][j]>max) max=board[i][j];}}
    if(max>ans) ans=max;
    return max;
}
void dfs(int st)
{
    if(st>5) return;
    int max=checkmax();
    if((max<<(5-st))<=ans) return;
    int obd[23][23]={0,};
    copy(&board[0][0],&board[0][0]+23*23,&obd[0][0]);
    bup(); dfs(st+1); copy(&obd[0][0],&obd[0][0]+23*23,&board[0][0]);
    bdown(); dfs(st+1); copy(&obd[0][0],&obd[0][0]+23*23,&board[0][0]);
    bright(); dfs(st+1); copy(&obd[0][0],&obd[0][0]+23*23,&board[0][0]);
    bleft(); dfs(st+1); copy(&obd[0][0],&obd[0][0]+23*23,&board[0][0]);
}


int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0; i<n; ++i){for(int j=0; j<n; ++j){cin>>board[i][j];}}
    //for(int i=0; i<n; ++i){for(int j=0; j<n; ++j){cout<<board[i][j]<<" ";}cout<<"\n";}
    dfs(0);
    cout<<ans;
    return 0;
}