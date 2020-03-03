//200303 20:44 start d4 87.26% 21:04  20min
#include<iostream>
#include<string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,ans,trash;
    string oper,gar;
    for(int tc=1; tc<=10; ++tc)
    {
        cin>>n;
        ans=1;
        for(int i=1; i<=n/2; ++i)
        {
            cin>>trash>>oper;
            getline(cin,gar);
            if(ans==0) continue;
            if(!(oper=="+"||oper=="-"||oper=="*"||oper=="/")) ans=0;
        }
        for(int i=n/2+1; i<=n; ++i)
        {
            cin>>trash>>oper;
            if(ans==0) continue;
            if(oper=="+"||oper=="-"||oper=="*"||oper=="/") ans=0;
        }
        cout<<"#"<<tc<<" "<<ans<<"\n";
    }
    return 0;
}