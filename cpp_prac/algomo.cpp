//2019-11-17 1735~1805
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int c,n,temp;
    cin>>c;
    for(int tc=1; tc<=c; ++tc)
    {
        cin>>n;
        vector<int> russia;
        vector<int> korea;
        int ans=0;
        for(int i=0; i<n; ++i)
        { 
            cin>>temp;
            russia.push_back(temp);
        }
        for(int i=0; i<n; ++i)
        { 
            cin>>temp;
            korea.push_back(temp);
        }
        sort(russia.begin(),russia.end());
        sort(korea.begin(),korea.end());
        int end=n-1;
        for(int i=0; i<n; ++i)
        {
            if(russia[i]>korea[i])
            {
                temp=korea[0];
                korea.erase(korea.begin());
                korea.push_back(temp);
                i--;
                end--;
            }
            if(i==end) break;
        }
        for(int i=0; i<n; ++i)
        {
            if(russia[i]<=korea[i]) ans++;
            else break;
        }
        cout<<ans<<"\n";
    }
    return 0;
}