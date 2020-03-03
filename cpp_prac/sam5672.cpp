//2003030 16:34 start D4 26.92%  17:05end
//정답률에 쫄지말자 그냥 해봐라
#include<iostream>
#include<string>

using namespace std;
string ans;
string origin;

void dfs(int left,int right)
{
    if(left==right){ ans.push_back(origin[left]); return;}
    if(origin[left]<origin[right])
    {
        ans.push_back(origin[left]);
        dfs(left+1,right);
    }else if(origin[left]>origin[right])
    {
        ans.push_back(origin[right]);
        dfs(left,right-1);
    }else
    {
        ans.push_back(origin[left]);
        int fleft=left+1;
        int fright=right-1;
        int check=1;
        while(fleft<fright)
        {
            if(origin[fleft]!=origin[fright])
            {
                check=1;
                break;
            }
            fleft++;
            fright--;
        }
        if(check==1)
        {
            if(origin[fleft]<origin[fright]) dfs(left+1,right);
            else dfs(left,right-1);            
        }else dfs(left+1,right);
    }
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,n;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n;
        origin="";
        ans="";
        for(int i=0; i<n; ++i)
        {
            char temp;
            cin>>temp;
            origin.push_back(temp);
        }
        dfs(0,n-1);
        cout<<"#"<<tc<<" "<<ans<<"\n";
    }
    return 0;
}