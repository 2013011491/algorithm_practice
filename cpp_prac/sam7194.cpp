    //2019-11-02 17:04~
    #include <iostream>
    #include <stack>
    #include <array>

    using namespace std;

    int main(void)
    {
        cin.tie(NULL);
        ios::sync_with_stdio(false);

        int tl,s,t,a,b;
        cin>>tl;

        for(int tc=1; tc<=tl; tc++)
        {
            cout<<"#"<<tc<<" ";
            cin>>s>>t>>a>>b;
            int ans=-1;
            stack<array<int,2>> bucket;
            bucket.push({t,0});
            array<int,2> head;
            while(!bucket.empty())
            {
                head=bucket.top();
                bucket.pop();
                if(head[0]==s)
                {
                    ans=head[1];
                    break;
                }
                else if(head[0]<s) continue;
                if(head[0]>a) bucket.push({head[0]-a,head[1]+1});
                if(head[0]%b==0) bucket.push({head[0]/b,head[1]+1});
            }
            cout<<ans<<"\n";
        }
        return 0;
    }