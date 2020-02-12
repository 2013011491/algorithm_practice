//200212 17:52 start D2 68.11%   18:00 end
#include<iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,h1,m1,h2,m2;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>h1>>m1>>h2>>m2;
        cout<<"#"<<tc<<" ";
        h1=(h1+h2+(m1+m2)/60)%12;
        if(h1==0) h1=12;
        m1=(m1+m2)%60;
        cout<<h1<<" "<<m1<<"\n";
    }
    return 0;
}