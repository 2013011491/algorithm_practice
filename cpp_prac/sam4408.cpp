#include<iostream>
#include<array>
#include<set>

using namespace std;

struct classcomp
{
    bool operator() (const array<int,2> a, const array<int,2> b)
    {
        return a[0]<b[0];
    }
};
set<array<int,2>> bucket;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,n,a,b;
    array<int,2> pres;
    cin>>t;
    for(int tc=0; tc<t; tc++)
    {
        bucket.clear();
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>a>>b;
            if(a<b) bucket.insert({a,b});
            else bucket.insert({b,a});
        }
        cout<<"#"<<tc+1<<" ";

        //start
        int count=0;
        int last=0;
        set<array<int,2>>::iterator it;
        while(!bucket.empty())
        {
            count++;
            it=bucket.begin();
            pres=*it;
            last=pres[1];
            if(last%2!=0) last++;
            bucket.erase(bucket.begin());
            for(it=bucket.begin(); it!=bucket.end(); ++it)
            {
                pres=*it;
                if(pres[0]>last)
                {
                    last=pres[1];
                    if(last%2!=0) last++;
                    bucket.erase(it);
                }
            }
        }
        cout<<count<<"\n";

    }
    return 0;
}