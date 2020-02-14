//200214 18:04 start D3 58.12% 18:48 end for 44
//string 이용으로 빠르게 한거같은데 정식 방법은 잘 이해가 안감.
#include<iostream>
#include<string>

using namespace std;

int n;
int ans=0;

void dfs(int col,string board)
{
    for(int i=0; i<n; ++i)
    {
        if(board[col*n+i]!='1')
        {
            if(col==n-1)
            {
                ans++;
                return;
            }
            string temp=board;
            for(int j=col+1; j<n; ++j){ temp[j*n+i]='1';}
            int k=col;
            int j=i;
            while(k>=0 && k<n && j>=0 && j<n)
            {
                temp[k*n+j]='1';
                k++;
                j++;
            }
            k=col;
            j=i;
            while(k>=0 && k<n && j>=0 && j<n)
            {
                temp[k*n+j]='1';
                k++;
                j--;
            }
            dfs(col+1,temp);
        }
    }
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n;
        cout<<"#"<<tc<<" ";
        ans=0;
        string board;
        for(int i=0; i<n*n; ++i){ board.push_back('0'); }
        dfs(0,board);
        cout<<ans<<"\n";
    }
    return 0;
}