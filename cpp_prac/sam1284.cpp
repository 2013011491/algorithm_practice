//200206 20:10 start d2 81.68% 20:24 end
#include<iostream>

using namespace std;

int calA(int p, int w){ return p*w; }
int calB(int q, int r, int s, int w) {return w<=r ? q : (w-r)*s+q; }

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,p,q,r,s,w;
    cin>>t;

    for(int tc=1; tc<=t; ++tc)
    {
        cout<<"#"<<tc<<" ";
        cin>>p>>q>>r>>s>>w;
        int a = calA(p,w);
        int b = calB(q,r,s,w);
        cout<< (a<b ? a : b) <<"\n";
    }
    return 0;
}