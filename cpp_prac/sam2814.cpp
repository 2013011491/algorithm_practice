//200204 15:28 start 16:15  end for48m
#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool check(string str, int k)
{
    for(int i=0; i<str.size(); ++i)
    {
        if(str[i]==(k+'0')) return false;
    }
    return true;
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,n,m;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n>>m;
        cout<<"#"<<tc<<" ";
        int vertex[10][10]={0,};
        stack<string> bucket;

        int ans=1;
        for(int i=0; i<m; ++i)
        {
            int a,b;
            cin>>a>>b;
            vertex[a-1][b-1]=1;
            vertex[b-1][a-1]=1;
        }
        for(int i=0; i<n; ++i)
        {
            char st=i+'0';
            for(int j=0; j<n; ++j)
            {
                if(vertex[i][j]==1)
                {
                    string temp;
                    temp+=st;
                    temp+=(j+'0');
                    bucket.push(temp);
                }
            }
            while(!bucket.empty())
            {
                string temp=bucket.top();
                bucket.pop();
                if(ans<temp.size()) ans=temp.size();
                for(int k=0; k<n; ++k)
                {
                    if(vertex[temp[temp.size()-1]-'0'][k]==1 && check(temp,k))
                    {
                        bucket.push(temp+char(k+'0'));
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}