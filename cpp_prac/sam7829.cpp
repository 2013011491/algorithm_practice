//200306 17:02 start d4 80.75%  17:07 ez
#include<iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    long long p,minv,maxv,temp;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        maxv=0;
        minv=1000001;
        cin>>p;
        for(int i=0; i<p; ++i)
        {
            cin>>temp;
            if(temp<minv) minv=temp;
            if(temp>maxv) maxv=temp;
        }
        cout<<"#"<<tc<<" "<<minv*maxv<<"\n";
    }
    return 0;
}