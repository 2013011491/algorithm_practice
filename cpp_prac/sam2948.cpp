//200302 16:40 start d3 25.83%
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,n,m;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n>>m;
        string temp;
        int ans=0;
        vector<string> bucket;
        vector<string>::iterator it;
        for(int i=0; i<n; ++i){cin>>temp; bucket.push_back(temp);}
        for(int i=0; i<m; ++i){cin>>temp; bucket.push_back(temp);}
        sort(bucket.begin(),bucket.end());
        it=unique(bucket.begin(),bucket.end());
        cout<<"#"<<tc<<" "<<n+m-distance(bucket.begin(),it)<<"\n";
    }
    return 0;
}