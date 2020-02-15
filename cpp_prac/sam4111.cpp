//200215 17:11 start d4 21.91%   17:41 30min
//Good!!
#include<iostream>
#include<array>
#include<algorithm>
#include<set>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,n,k;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cout<<"#"<<tc<<" ";
        cin>>n>>k;
        set<int> point;
        set<int>::iterator it;
        array<int,10001> distan;
        int temp;
        for(int i=0; i<n; ++i)
        { 
            cin>>temp;
            point.insert(temp);
        }
        if(point.size()<=k)
        {
            cout<<0<<'\n';
            continue;
        }
        int past=*(point.begin());
        int i=0;
        for(it=point.begin(); it!=point.end(); ++it)
        {
            int pres=*it;
            distan[i++]=pres-past;
            past=pres;
        }
        sort(distan.begin(),distan.begin()+i);
        int ans=0;
        for(int j=0; j<=i-k; ++j){ ans+=distan[j]; }
        cout<<ans<<"\n";
    }
    return 0;
}