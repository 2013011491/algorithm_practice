//200214 16:24 start D2 76.57%  16:39 end
#include<iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,n;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        int sum=0;
        int con[2]={0,};
        int pres=0;
        cout<<"#"<<tc<<" ";
        cin>>n;
        for(int i=0; i<n; ++i)
        {
            cin>>con[0];
            if(con[0]!=0)
            {    
                cin>>con[1];
                if(con[0]==1) pres+=con[1];
                else if(con[0]==2) pres-=con[1];
                if(pres<0) pres=0;
            }
            sum+=pres;
        }
        cout<<sum<<"\n";
    }
    return 0;
}