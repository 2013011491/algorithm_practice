#include<iostream>
#include<array>
#include<stack>


using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,n;
    char board[301][301];

    cin>>t;
    for(int tc=0; tc<t; tc++)
    {
        cin>>n;
        int click=0;
        int num[301][301]={0,};
        stack<array<int,2>> bucket;
        array<int,2> pre;
        for(int i=0; i<n; i++)
        {
            cin>>board[i];
            for(int j=0; j<n; j++)
            {
                if(board[i][j]=='*')
                {
                    num[i][j]=-10;
                    if(i==0)
                    {
                        if(j==0)
                        {
                            num[0][1]++;
                            num[1][0]++;
                            num[1][1]++;
                        }else if(j==n-1)
                        {
                            num[0][n-2]++;
                            num[1][n-2]++;
                            num[1][n-1]++;
                        }else
                        {
                            num[0][j-1]++;
                            num[1][j-1]++;
                            num[1][j]++;
                            num[1][j+1]++;
                            num[0][j+1]++;
                        }
                    }else if(j==0)
                    {
                        num[i-1][j]++;
                        num[i-1][j+1]++;
                        num[i][j+1]++;
                        if(j!=n-1)
                        {
                            num[i+1][j]++;
                            num[i+1][j+1]++;
                        }
                    }else if(i==n-1)
                    {
                        num[i][j-1]++;
                        num[i-1][j-1]++;
                        num[i-1][j]++;
                        if(j!=n-1)
                        {
                            num[i-1][j+1]++;
                            num[i][j+1]++;
                        }
                    }else if(j==n-1)
                    {
                        num[i-1][j]++;
                        num[i-1][j-1]++;
                        num[i][j-1]++;
                        num[i+1][j-1]++;
                        num[i+1][j]++;
                    }else
                    {
                        num[i-1][j]++;
                        num[i-1][j-1]++;
                        num[i][j-1]++;
                        num[i+1][j-1]++;
                        num[i+1][j]++;
                        num[i-1][j+1]++;
                        num[i][j+1]++;
                        num[i+1][j+1]++;
                    }
                }
            }
        }
        cout<<"#"<<tc+1<<" ";
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(num[i][j]==0)
                {
                    click++;
                    bucket.push({i,j});

                    while(bucket.size())
                    {
                        pre=bucket.top();
                        bucket.pop();

                        if(pre[0]>=0 && pre[0]<n && pre[1]>=0 && pre[1]<n)
                        {
                            if(num[pre[0]][pre[1]]==0)
                            {
                                bucket.push({pre[0]-1,pre[1]-1});
                                bucket.push({pre[0]-1,pre[1]});
                                bucket.push({pre[0]-1,pre[1]+1});
                                bucket.push({pre[0],pre[1]+1});
                                bucket.push({pre[0]+1,pre[1]+1});
                                bucket.push({pre[0]+1,pre[1]});
                                bucket.push({pre[0]+1,pre[1]-1});
                                bucket.push({pre[0],pre[1]-1});
                                num[pre[0]][pre[1]]=-1;
                            
                            }else if(num[pre[0]][pre[1]]>0) num[pre[0]][pre[1]]=-1;

                        }
                    }

                }
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(num[i][j]>0) click++;
            }
        }
        cout<<click<<"\n";


    }
    return 0;
}