//200313 16:49 start d4 40.48%
#include<iostream>
#include<cmath>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t,x1,y1,x2,y2;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        int ans=0;
        cin>>x1>>y1>>x2>>y2;
        cout<<"#"<<tc<<" ";
        int w=abs(y2-y1);
        int h=abs(x2-x1);
        if(w==h)
        {
            cout<<w*2<<"\n";
            continue;
        }
        if(w>h) ans=2*h;
        else ans=2*w;
        int dif=abs(w-h);
        ans+=(dif/2) * 4;
        if(dif%2==1) ans++;
        cout<<ans<<"\n";
    }

    return 0;
}