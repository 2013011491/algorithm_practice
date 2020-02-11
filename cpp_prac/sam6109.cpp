//200210 20:51 start d4 43.21%   21:36 45 min
#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);


    int t,n;
    string s;
    int board[20][20]={0,};
    deque<int> bucket;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n>>s;
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j){ cin>>board[i][j]; }
        }
        cout<<"#"<<tc<<"\n";
        if(s=="up")
        {
            for(int i=0; i<n; ++i)
            {
                for(int j=0; j<n; ++j)
                {
                    if(board[j][i]!=0)
                    {
                        bucket.push_back(board[j][i]);
                        board[j][i]=0;
                    }
                }
                int first,second;
                int pres=0;
                while(!bucket.empty())
                {
                    first=bucket.front();
                    bucket.pop_front();
                    if(bucket.empty())
                    {
                        board[pres++][i]=first;
                        break;
                    }
                    second=bucket.front();
                    bucket.pop_front();
                    if(first==second) board[pres++][i]=first*2;
                    else 
                    {
                        board[pres++][i]=first;
                        bucket.push_front(second);
                    }
                }
            }
        }else if(s=="down")
        {
            for(int i=0; i<n; ++i)
            {
                for(int j=n-1; j>=0; --j)
                {
                    if(board[j][i]!=0)
                    {
                        bucket.push_back(board[j][i]);
                        board[j][i]=0;
                    }
                }
                int first,second;
                int pres=n-1;
                while(!bucket.empty())
                {
                    first=bucket.front();
                    bucket.pop_front();
                    if(bucket.empty())
                    {
                        board[pres--][i]=first;
                        break;
                    }
                    second=bucket.front();
                    bucket.pop_front();
                    if(first==second) board[pres--][i]=first*2;
                    else 
                    {
                        board[pres--][i]=first;
                        bucket.push_front(second);
                    }
                }
            }
        }
        else if(s=="left")
        {
            for(int i=0; i<n; ++i)
            {
                for(int j=0; j<n; ++j)
                {
                    if(board[i][j]!=0)
                    {
                        bucket.push_back(board[i][j]);
                        board[i][j]=0;
                    }
                }
                int first,second;
                int pres=0;
                while(!bucket.empty())
                {
                    first=bucket.front();
                    bucket.pop_front();
                    if(bucket.empty())
                    {
                        board[i][pres++]=first;
                        break;
                    }
                    second=bucket.front();
                    bucket.pop_front();
                    if(first==second) board[i][pres++]=first*2;
                    else 
                    {
                        board[i][pres++]=first;
                        bucket.push_front(second);
                    }
                }
            }
        }
        else if(s=="right")
        {
            for(int i=0; i<n; ++i)
            {
                for(int j=n-1; j>=0; --j)
                {
                    if(board[i][j]!=0)
                    {
                        bucket.push_back(board[i][j]);
                        board[i][j]=0;
                    }
                }
                int first,second;
                int pres=n-1;
                while(!bucket.empty())
                {
                    first=bucket.front();
                    bucket.pop_front();
                    if(bucket.empty())
                    {
                        board[i][pres--]=first;
                        break;
                    }
                    second=bucket.front();
                    bucket.pop_front();
                    if(first==second) board[i][pres--]=first*2;
                    else 
                    {
                        board[i][pres--]=first;
                        bucket.push_front(second);
                    }
                }
            }
        }
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j){ cout<<board[i][j]<<" "; }
            cout<<"\n";
        }
    }
    return 0;
}